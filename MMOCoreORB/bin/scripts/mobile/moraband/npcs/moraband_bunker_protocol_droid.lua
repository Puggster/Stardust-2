moraband_bunker_protocol_droid = Creature:new {
	objectName = "@mob/creature_names:protocol_droid_3po_silver",
	customName = "CT-212",
	socialGroup = "",
	faction = "",
	mobType = MOB_DROID,
	level = 100,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9429,
	baseHAM = 24000,
	baseHAMmax = 30000,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 2 * 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = INVULNERABLE,
	optionsBitmask = AIENABLED + CONVERSABLE + INTERESTING,
	diet = HERBIVORE,

	templates = {"object/mobile/3po_protocol_droid_silver.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "moraband_bunker_protocol_droid",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(moraband_bunker_protocol_droid, "moraband_bunker_protocol_droid")