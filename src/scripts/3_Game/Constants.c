const string Syberia_ModPreffix = "[SYBERIA] ";
const bool Syberia_DebugMode = true;

void SybLog(string message)
{
	if (Syberia_DebugMode) Print(Syberia_ModPreffix + message);
}

bool ConfigIsInstanceOf(string basePath, string classname, string baseClassname)
{
	if (!GetGame().ConfigIsExisting(basePath + " " + classname))
	{
		return false;
	}
	
	string baseOutputName;
	while(GetGame().ConfigGetBaseName(basePath + " " + classname, baseOutputName))
	{
		if (baseOutputName == baseClassname)
		{
			return true;
		}
		
		classname = baseOutputName;
	}
	
	return false;
}

enum SyberiaRPC {
    SYBRPC_RESPAWN_SCREEN_OPEN,
	SYBRPC_NEWCHAR_SCREEN_OPEN,
	SYBRPC_EQUIP_SCREEN_OPEN,
	SYBRPC_CREATENEWCHAR_REQUEST,
	SYBRPC_STARTGAME_REQUEST,
	SYBRPC_RESPAWN_REQUEST,
	SYBRPC_DELETECHAR_REQUEST,
	SYBRPC_CREATENEWCHAR_ERROR,
	SYBRPC_PDA_USER_STATE,
	SYBRPC_PDA_ADD_CONTACT,
	SYBRPC_PDA_CHECK_CONTACT,
	SYBRPC_PDA_SEND_MESSAGE,
	SYBRPC_PDA_SEND_GLOBAL_MESSAGE,
	SYBRPC_PDA_SEND_GROUP_MESSAGE,
	SYBRPC_PDA_CMD_GROUP,
	SYBRPC_SCREEN_MESSAGE,
	SYBRPC_CLIENT_OPTIONS
};

enum SyberiaScreenEquipPages {
	SYBSEP_SPAWN_PAGE = 0,
	SYBSEP_BODY_PAGE = 1,
	SYBSEP_PANTS_PAGE = 2,
	SYBSEP_FOOT_PAGE = 3,
	SYBSEP_HEAD_PAGE = 4,
	SYBSEP_WEAPON_PAGE = 5,
	SYBSEP_ITEMS_PAGE = 6,
	SYBSEP_SPECIAL_PAGE = 7
};

enum SyberiaSleepingLevel {
	SYBSL_COLD = -2,
	SYBSL_HOT = -1,
	SYBSL_NONE = 0,
	SYBSL_COMFORT = 1,
	SYBSL_PERFECT = 2
};

const int NTFKEY_SLEEPING = 1000;
const int NTFKEY_MINDSTATE = 1001;
const int NTFKEY_BULLETHIT = 1100;
const int NTFKEY_KNIFEHIT = 1101;
const int NTFKEY_HEMATOMA = 1102;
const int NTFKEY_VISCERADMG = 1103;
const int NTFKEY_CONCUSSION = 1104;
const int NTFKEY_PAIN = 1105;
const int NTFKEY_PAINKILLER = 1106;
const int NTFKEY_ANTIBIOTIC = 1107;
const int NTFKEY_STOMATCHHEAL = 1108;
const int NTFKEY_SEPSIS = 1109;
const int NTFKEY_ZVIRUS = 1110;
const int NTFKEY_BANDAGE1 = 1111;
const int NTFKEY_BANDAGE2 = 1112;
const int NTFKEY_HEMOSTATIC = 1113;
const int NTFKEY_HEMATOPOIESIS = 1114;
const int NTFKEY_USESALVE = 1115;
const int NTFKEY_ADRENALIN = 1116;
const int NTFKEY_OVERDOSED = 1117;
const int NTFKEY_INFLUENZA = 1118;

const int LEVELED_NTFKEY_BADGES_COUNT = 6;
const int LEVELED_NTFKEY_BADGES[LEVELED_NTFKEY_BADGES_COUNT] = { 
	NTFKEY_PAIN, NTFKEY_PAINKILLER, NTFKEY_ADRENALIN, NTFKEY_OVERDOSED, NTFKEY_INFLUENZA, NTFKEY_ANTIBIOTIC 
};

const string ALLOWED_LETTERS_IN_NAME = "abcdefghijklmnopqrstuvwxyz";

// U CAN CHANGE THIS CONSTANTS
const int SLEEPING_MAX_VALUE = 14000;
const int SLEEPING_LEVEL_5 = 100;
const int SLEEPING_LEVEL_4 = 1000;
const int SLEEPING_LEVEL_3 = 5000;
const int SLEEPING_LEVEL_2 = 10000;

const float MINDSTATE_MAX_VALUE = 100;
const float MINDSTATE_LEVEL_5 = 1.0;
const float MINDSTATE_LEVEL_4 = 10.0;
const float MINDSTATE_LEVEL_3 = 30.0;
const float MINDSTATE_LEVEL_2 = 70.0;

// Constants redefinition
modded class PlayerConstants
{
	static const float CHANCE_TO_BLEED_SLIDING_LADDER_PER_SEC = 0.1; // probability of bleeding source occuring while sliding down ladder without gloves given as percentage per second(0.5 means 50% chance bleeding source will happen every second while sliding down) 
	static const float GLOVES_DAMAGE_SLIDING_LADDER_PER_SEC = -0.5;// how much damage the gloves receive while sliding down the ladder (per sec)

	static const float BAREFOOT_MOVEMENT_BLEED_MODIFIER = 0.02;
	static const float SHOES_MOVEMENT_DAMAGE_PER_STEP = 0.001;
	
	static const float BLEEDING_SOURCE_BLOODLOSS_PER_SEC = -2;
	static const float BLOOD_REGEN_RATE_PER_SEC	= 0.05; //base amount of blood regenerated per second 
	
	static const float HEALTH_REGEN_MIN	= 0.002;	//health regen rate at BLOOD_THRESHOLD_FATAL blood level
	static const float HEALTH_REGEN_MAX	= 0.008;	//health regen rate at MAXIMUM blood level
	
	static const float SHOCK_REFILL_CONSCIOUS_SPEED			= 1;		//shock refill speed when the player is conscious
	static const float SHOCK_REFILl_UNCONSCIOUS_SPEED		= 0.1;		//shock refill speed when the player is unconscious
	
	
	// Metabolic
	static const float SL_ENERGY_CRITICAL = 0;
	static const float SL_ENERGY_LOW = 200;
	static const float SL_ENERGY_NORMAL = 1500;
	static const float SL_ENERGY_HIGH = 2800;
	
	static const float METABOLIC_SPEED_ENERGY_BASAL		= 0.01;		//energy loss per second while idle	
	static const float METABOLIC_SPEED_ENERGY_WALK		= 0.02;		//energy loss per second
	static const float METABOLIC_SPEED_ENERGY_JOG		= 0.06;		//energy loss per second
	static const float METABOLIC_SPEED_ENERGY_SPRINT	= 0.10;		//energy loss per second
	
	// Water
	static const float SL_WATER_CRITICAL = 0;
	static const float SL_WATER_LOW = 100;
	static const float SL_WATER_NORMAL = 600;
	static const float SL_WATER_HIGH = 1300;
	
	static const float METABOLIC_SPEED_WATER_BASAL		= 0.02;		//water loss per second while idle	
	static const float METABOLIC_SPEED_WATER_WALK		= 0.05;		//water loss per second
	static const float METABOLIC_SPEED_WATER_JOG		= 0.2;		//water loss per second
	static const float METABOLIC_SPEED_WATER_SPRINT		= 0.3;		//water loss per second
}