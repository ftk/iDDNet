/* (c) Shereef Marzouk. See "licence DDRace.txt" and the readme.txt in the root of the distribution for more information. */

// This file can be included several times.

#ifndef CHAT_COMMAND
#define CHAT_COMMAND(name, params, flags, callback, userdata, help)
#endif

CHAT_COMMAND("credits", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConCredits, this, "Shows the credits of the DDRace mod")
CHAT_COMMAND("emote", "?s[emote name] i[duration in seconds]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConEyeEmote, this, "Sets your tee's eye emote")
CHAT_COMMAND("eyeemote", "?s['on'|'off'|'toggle']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConSetEyeEmote, this, "Toggles use of standard eye-emotes on/off, eyeemote s, where s = on for on, off for off, toggle for toggle and nothing to show current status")
CHAT_COMMAND("settings", "?s[configname]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConSettings, this, "Shows gameplay information for this server")
CHAT_COMMAND("help", "?r[command]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConHelp, this, "Shows help to command r, general help if left blank")
CHAT_COMMAND("info", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConInfo, this, "Shows info about this server")
CHAT_COMMAND("me", "r[message]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConMe, this, "Like the famous irc command '/me says hi' will display '<yourname> says hi'")
CHAT_COMMAND("w", "s[player name] r[message]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConWhisper, this, "Whisper something to someone (private message)")
CHAT_COMMAND("whisper", "s[player name] r[message]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConWhisper, this, "Whisper something to someone (private message)")
CHAT_COMMAND("c", "r[message]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConConverse, this, "Converse with the last person you whispered to (private message)")
CHAT_COMMAND("converse", "r[message]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConConverse, this, "Converse with the last person you whispered to (private message)")
CHAT_COMMAND("pause", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTogglePause, this, "Toggles pause")
CHAT_COMMAND("spec", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConToggleSpec, this, "Toggles spec (if not available behaves as /pause)")
CHAT_COMMAND("pausevoted", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTogglePauseVoted, this, "Toggles pause on the currently voted player")
CHAT_COMMAND("specvoted", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConToggleSpecVoted, this, "Toggles spec on the currently voted player")
CHAT_COMMAND("dnd", "", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConDND, this, "Toggle Do Not Disturb (no chat and server messages)")
CHAT_COMMAND("mapinfo", "?r[map]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConMapInfo, this, "Show info about the map with name r gives (current map by default)")
CHAT_COMMAND("timeout", "?s[code]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTimeout, this, "Set timeout protection code s")
CHAT_COMMAND("save", "r[code]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConSave, this, "Save team with code r to current server. To save to another server, use '/save s r' where s = server (case-sensitive: GER, RUS, etc) and r = code")
CHAT_COMMAND("load", "r[code]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConLoad, this, "Load with code r")
CHAT_COMMAND("map", "?r[map]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConMap, this, "Vote a map by name")
CHAT_COMMAND("rankteam", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTeamRank, this, "Shows the team rank of player with name r (your team rank by default)")
CHAT_COMMAND("teamrank", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTeamRank, this, "Shows the team rank of player with name r (your team rank by default)")
CHAT_COMMAND("rank", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConRank, this, "Shows the rank of player with name r (your rank by default)")
CHAT_COMMAND("rules", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConRules, this, "Shows the server rules")
CHAT_COMMAND("team", "?i[id]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConJoinTeam, this, "Lets you join team i (shows your team if left blank)")
CHAT_COMMAND("lock", "?i['0'|'1']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConLockTeam, this, "Lock team so no-one else can join it")
CHAT_COMMAND("invite", "r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConInviteTeam, this, "Invite a person to a locked team")
CHAT_COMMAND("top5team", "?i[rank to start with]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTeamTop5, this, "Shows five team ranks of the ladder beginning with rank i (1 by default)")
CHAT_COMMAND("teamtop5", "?i[rank to start with]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTeamTop5, this, "Shows five team ranks of the ladder beginning with rank i (1 by default)")
CHAT_COMMAND("top5", "?i[rank to start with]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTop5, this, "Shows five ranks of the ladder beginning with rank i (1 by default)")
CHAT_COMMAND("showothers", "?i['0'|'1']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConShowOthers, this, "Whether to show players from other teams or not (off by default), optional i = 0 for off else for on")
CHAT_COMMAND("showall", "?i['0'|'1']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConShowAll, this, "Whether to show players at any distance (off by default), optional i = 0 for off else for on")
CHAT_COMMAND("specteam", "?i['0'|'1']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConSpecTeam, this, "Whether to show players from other teams when spectating (on by default), optional i = 0 for off else for on")
CHAT_COMMAND("ninjajetpack", "?i['0'|'1']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConNinjaJetpack, this, "Whether to use ninja jetpack or not. Makes jetpack look more awesome")
CHAT_COMMAND("saytime", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConSayTime, this, "Privately messages someone's current time in this current running race (your time by default)")
CHAT_COMMAND("saytimeall", "", CFGFLAG_CHAT|CFGFLAG_SERVER|CFGFLAG_NONTEEHISTORIC, ConSayTimeAll, this, "Publicly messages everyone your current time in this current running race")
CHAT_COMMAND("time", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTime, this, "Privately shows you your current time in this current running race in the broadcast message")
CHAT_COMMAND("timer", "?s['gametimer'|'broadcast'|'both'|'none'|'cycle']", CFGFLAG_CHAT|CFGFLAG_SERVER, ConSetTimerType, this, "Personal Setting of showing time in either broadcast or game/round timer, timer s, where s = broadcast for broadcast, gametimer for game/round timer, cycle for cycle, both for both, none for no timer and nothing to show current status")
CHAT_COMMAND("r", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConRescue, this, "Teleport yourself out of freeze (use sv_rescue 1 to enable this feature)")
CHAT_COMMAND("rescue", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConRescue, this, "Teleport yourself out of freeze (use sv_rescue 1 to enable this feature)")

CHAT_COMMAND("kill", "", CFGFLAG_CHAT|CFGFLAG_SERVER, ConProtectedKill, this, "Kill yourself")

CHAT_COMMAND("modhelp", "r[message]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConModhelp, this, "Request the help of a moderator with a description of the problem")

#if defined(CONF_SQL)
CHAT_COMMAND("times", "?s[player name] ?i[number of times to skip]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTimes, this, "/times ?s?i shows last 5 times of the server or of a player beginning with name s starting with time i (i = 1 by default)")
CHAT_COMMAND("points", "?r[player name]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConPoints, this, "Shows the global points of a player beginning with name r (your rank by default)")
CHAT_COMMAND("top5points", "?i[number]", CFGFLAG_CHAT|CFGFLAG_SERVER, ConTopPoints, this, "Shows five points of the global point ladder beginning with rank i (1 by default)")
#endif

// iDDNet
CHAT_COMMAND("cmdlist", "?s[category]", CFGFLAG_CHAT, ConCMDList, this, "List all commands which are accessible for users")
CHAT_COMMAND("dummy", "", CFGFLAG_CHAT, ConDummy, this, "Creates your own Dummy if it doesn\'t exist")
CHAT_COMMAND("dummy_del", "", CFGFLAG_CHAT, ConDummyDelete, this, "Removes your Dummy")
CHAT_COMMAND("dummy_change", "", CFGFLAG_CHAT, ConDummyChange, this, "Swap you with your dummy")
CHAT_COMMAND("dummy_swap", "", CFGFLAG_CHAT, ConDummyChange, this, "Swap you with your dummy")
CHAT_COMMAND("dummy_hammer", "?i[range]", CFGFLAG_CHAT, ConDummyHammerFly, this, "Your Dummy looks at you and hitting with hammer")
CHAT_COMMAND("dummy_hammerfly", "?i[range]", CFGFLAG_CHAT, ConDummyHammerFly, this, "Your Dummy looks at you and hitting with hammer")
CHAT_COMMAND("control_dummy", "", CFGFLAG_CHAT, ConDummyControl, this, "Go to spectators and control your dummy")
CHAT_COMMAND("dummy_copy_move", "", CFGFLAG_CHAT, ConDummyCopyMove, this, "Dummy copies all your movement.")
//the same but in another interpretation
CHAT_COMMAND("d", "", CFGFLAG_CHAT, ConDummy, this, "Creates your own Dummy if it doesn\'t exist")
CHAT_COMMAND("dummy_delete", "", CFGFLAG_CHAT, ConDummyDelete, this, "Removes your Dummy")
CHAT_COMMAND("delete", "", CFGFLAG_CHAT, ConDummyDelete, this, "Removes your Dummy")
CHAT_COMMAND("dd", "", CFGFLAG_CHAT, ConDummyDelete, this, "Removes your Dummy")
CHAT_COMMAND("dc", "", CFGFLAG_CHAT, ConDummyChange, this, "Swap you with your dummy")
CHAT_COMMAND("ds", "", CFGFLAG_CHAT, ConDummyChange, this, "Swap you with your dummy")
CHAT_COMMAND("dh", "?i[range]", CFGFLAG_CHAT, ConDummyHammerFly, this, "Your Dummy looks at you and hitting with hammer")
CHAT_COMMAND("dhf", "?i[range]", CFGFLAG_CHAT, ConDummyHammerFly, this, "Your Dummy looks at you and hitting with hammer")
CHAT_COMMAND("cd", "", CFGFLAG_CHAT, ConDummyControl, this, "Go to spectators and control your dummy")
CHAT_COMMAND("dcm", "", CFGFLAG_CHAT, ConDummyCopyMove, this, "Dummy copies all your movement. Smth like multiclient.")
CHAT_COMMAND("dhook", "", CFGFLAG_CHAT, ConDummyHook, this, "Dummy Hook Fly")
CHAT_COMMAND("daim", "", CFGFLAG_CHAT, ConDummyAim, this, "Dummy watching for you!")

//mkRace
CHAT_COMMAND("swap", "?r[playername]", CFGFLAG_CHAT, ConSwap, this, "Swap places with any player")
CHAT_COMMAND("r", "?s[d]", CFGFLAG_CHAT, ConRescue, this, "/r-rescue, \'/r d\' for dummy rescue.")
CHAT_COMMAND("rescue", "?s[d]", CFGFLAG_CHAT, ConRescue, this, "/r-rescue, \'/r d\' for dummy rescue.")
CHAT_COMMAND("dr", "?s[d]", CFGFLAG_CHAT, ConDisconnectRescue, this, "Rescue to location before disconnect, \'/dr d\' for dummy rescue.")
CHAT_COMMAND("disconnect_rescue", "?s[d]", CFGFLAG_CHAT, ConDisconnectRescue, this, "Rescue to location before disconnect, \'/dr d\' for dummy rescue.")

#undef CHAT_COMMAND
