/*
 * ArmorObjectMenuComponent.cpp
 *
 *  Created on: 2/4/2013
 *      Author: bluree
 *		Credits: TA & Valk
 */

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/building/BuildingObject.h"
#include "server/zone/objects/player/sui/colorbox/SuiColorBox.h"
#include "ArmorObjectMenuComponent.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"
#include "server/zone/objects/player/sui/callbacks/ColorArmorSuiCallback.h"
#include "server/zone/ZoneServer.h"
#include "templates/customization/AssetCustomizationManagerTemplate.h"

void ArmorObjectMenuComponent::fillObjectMenuResponse(SceneObject* sceneObject, ObjectMenuResponse* menuResponse, CreatureObject* player) const {

	if (!sceneObject->isWearableObject())
		return;

	ManagedReference<SceneObject*> parent = sceneObject->getParent().get();

	if (parent != nullptr && parent->isCellObject()) {
		ManagedReference<SceneObject*> obj = parent->getParent().get();

		if (obj != nullptr && obj->isBuildingObject()) {
			ManagedReference<BuildingObject*> buio = cast<BuildingObject*>(obj.get());

			if (!buio->isOnAdminList(player))
				return;
		}
	}
	else
	{
		if (!sceneObject->isASubChildOf(player))
			return;
	}

	String text = "Color 1 (Primary)";
	menuResponse->addRadialMenuItem(81, 3, "Color Options");
	menuResponse->addRadialMenuItemToRadialID(81, 82, 3, text);
	menuResponse->addRadialMenuItemToRadialID(81, 83, 3, "Color 2 (Secondary)");

	
    WearableObjectMenuComponent::fillObjectMenuResponse(sceneObject, menuResponse, player); 	
}

int ArmorObjectMenuComponent::handleObjectMenuSelect(SceneObject* sceneObject, CreatureObject* player, byte selectedID) const {

	if (selectedID == 82 || selectedID == 83) {
		
		ManagedReference<SceneObject*> parent = sceneObject->getParent().get();
	
		if (parent == nullptr)
			return 0;
	
		if (parent->isPlayerCreature()) {
			player->sendSystemMessage("@armor_rehue:equipped");
			return 0;
		}	

		if (parent->isCellObject()) {
			ManagedReference<SceneObject*> obj = parent->getParent().get();

			if (obj != nullptr && obj->isBuildingObject()) {
				ManagedReference<BuildingObject*> buio = cast<BuildingObject*>(obj.get());

				if (!buio->isOnAdminList(player))
					return 0;
			}
		}
		else
		{
			if (!sceneObject->isASubChildOf(player))
				return 0;
		}

		ZoneServer* server = player->getZoneServer();

		if (server != nullptr) {		

		// The color index.
		String appearanceFilename = sceneObject->getObjectTemplate()->getAppearanceFilename();
		VectorMap<String, Reference<CustomizationVariable*> > variables;
		AssetCustomizationManagerTemplate::instance()->getCustomizationVariables(appearanceFilename.hashCode(), variables, false);

		// The Sui Box.
		ManagedReference<SuiColorBox*> cbox = new SuiColorBox(player, SuiWindowType::COLOR_ARMOR);
		cbox->setCallback(new ColorArmorSuiCallback(server));
		int colorIndex = 0;
			if(selectedID == 83)
			{
				if(variables.size() > 1)
				{
					colorIndex = 1;
				}
				else
				{
					return 0;
				}
			}
			else if (selectedID == 84)
			{
				if(variables.size() > 2)
				{
					colorIndex = 2;
				}
				else
				{
					return 0;
				}
			}

			cbox->setColorPalette(variables.elementAt(colorIndex).getKey());
		cbox->setUsingObject(sceneObject);

		// Add to player.
		ManagedReference<PlayerObject*> ghost = player->getPlayerObject();
		ghost->addSuiBox(cbox);
		player->sendMessage(cbox->generateMessage());
		}

	}
	
	return WearableObjectMenuComponent::handleObjectMenuSelect(sceneObject, player, selectedID);
}
