skalder_matriarch = Creature:new {
	objectName = "@mob/creature_names:snorbal_matriarch",
	customName = "a Skalder Matriarch",
	socialGroup = "snorbal",
	faction = "",
	mobType = MOB_CARNIVORE,
	level = 45,
	chanceHit = 0.47,
	damageMin = 370,
	damageMax = 450,
	baseXp = 4370,
	baseHAM = 9700,
	baseHAMmax = 11700,
	armor = 0,
	resists = {135,135,0,-1,-1,0,0,0,-1},
	meatType = "meat_wild",
	meatAmount = 600,
	hideType = "hide_leathery",
	hideAmount = 475,
	boneType = "bone_mammal",
	boneAmount = 435,
	milkType = "milk_wild",
	milk = 2 * 350,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK + HERD,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/snorbal_matriarch.iff"},
	scale = 1.25,
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"posturedownattack",""},
		{"dizzyattack",""}
	}
}

CreatureTemplates:addCreatureTemplate(skalder_matriarch, "skalder_matriarch")
