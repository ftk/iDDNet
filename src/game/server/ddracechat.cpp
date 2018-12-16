/* (c) Shereef Marzouk. See "licence DDRace.txt" and the readme.txt in the root of the distribution for more information. */
#include "gamecontext.h"
#include <engine/engine.h>
#include <engine/shared/config.h>
#include <engine/shared/protocol.h>
#include <game/server/teams.h>
#include <game/server/gamemodes/DDRace.h>
#include <game/version.h>
#if defined(CONF_SQL)
#include <game/server/score/sql_score.h>
#endif

bool CheckClientID(int ClientID);

void CGameContext::ConCredits(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;

	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"iDDNet:re - DDNet with Dummy features combined by [SN] Snoop!");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"DDNet is run by the DDNet staff (DDNet.tw/staff)");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"Great maps and many ideas from the great community");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"Help and code by eeeee, HMH, east, CookieMichal, Learath2,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"Savander, laxa, Tobii, BeaR, Wohoo, nuborn, timakro, Shiki,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"trml, Soreu, hi_leute_gll, Lady Saavik, Chairn, heinrich5991,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"swick, oy, necropotame, Ryozuki, Redix, d3fault, marcelherd,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"BannZay, ACTom, SiuFuWong, PathosEthosLogos, TsFreddie,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"Jupeyy, noby, ChillerDragon, ZombieToad, weez15, z6zzz,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"Piepow, QingGo, RafaelFF, sctt & others.");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"Based on DDRace by the DDRace developers,");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "credits",
		"which is a mod of Teeworlds by the Teeworlds developers.");
}

void CGameContext::ConCMDList(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;

	if (pResult->NumArguments() == 0)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
			"~~~~~~~~~~~~~~~ CMDLIST ~~~~~~~~~~~~~~~");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
			"Dummy cmdlist: /cmdlist dummy");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
			"Race cmdlist: /cmdlist race");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
			"Chat cmdlist: /cmdlist chat");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
			"Other cmdlist: /cmdlist other");
	}
	else
	{
		const char *pArg = pResult->GetString(0);
		if (str_comp_nocase(pArg, "dummy") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"~~~~~~~~~~ DUMMY CMDLIST ~~~~~~~~~~");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/dummy, /d - Creates your own Dummy if it doesn\'t exist.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/dummy_del, /dummy_delete, /delete, /dd - Removes your Dummy.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/dummy_change, /dummy_swap, /dc, /ds - Swap you with your dummy.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/dummy_hammer, /dummy_hammerfly, /dh, /dhf - HammeFly.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/dhook - HookFly.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/daim - Dummy watching you.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/dummy_copy_move, /dcm - Dummy copies all your movement.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/control_dummy, /cd - Go to spectators and control your dummy.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/rescue d, /r d - Rescue for dummy.");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/disconnect_rescue d, /dr d - Disconnect rescue for dummy.");
		}
		if (str_comp_nocase(pArg, "race") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"~~~~~~~~~~ RACE CMDLIST ~~~~~~~~~~");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/pause, /spec, /save, /load");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/rank, /rankteam, /top5, /top5team");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/team, /lock, /showothers, /specteam");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/saytime, /saytimeall, /time, /timer");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/kill, /times, /points, /top5points");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/rescue, /r, /disconnect_rescue, /dr");
		}
		if (str_comp_nocase(pArg, "chat") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"~~~~~~~~~~ CHAT CMDLIST ~~~~~~~~~~");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/me, /dnd, /whisper, /w, /pm, /converse, /c");
		}
		if (str_comp_nocase(pArg, "other") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"~~~~~~~~~~ OTHER CMDLIST ~~~~~~~~~~");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/credits, /info, /help, /settings, /mapinfo");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cmdlist",
				"/emote, /eyeemote, /ninjajetpack, /timeout");
		}
	}
}

void CGameContext::ConInfo(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "info",
			"iDDNet Mod. Version: " GAME_VERSION);
#if defined( GIT_SHORTREV_HASH )
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "info",
			"Git revision hash: " GIT_SHORTREV_HASH);
#endif
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "info",
			"Official github page: github.com/SNSnoop/iDDNet");
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "info",
			"For more info: /cmdlist");
}

void CGameContext::ConHelp(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;

	if (pResult->NumArguments() == 0)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "help",
				"/cmdlist will show a list of all chat commands");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "help",
				"/help + any command will show you the help for this command");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "help",
				"Example /help settings will display the help about /settings");
	}
	else
	{
		const char *pArg = pResult->GetString(0);
		const IConsole::CCommandInfo *pCmdInfo =
				pSelf->Console()->GetCommandInfo(pArg, CFGFLAG_SERVER, false);
		if (pCmdInfo)
		{
			if (pCmdInfo->m_pParams)
			{
				char aBuf[256];
				str_format(aBuf, sizeof(aBuf), "Usage: %s %s", pCmdInfo->m_pName, pCmdInfo->m_pParams);
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "help", aBuf);
			}

			if (pCmdInfo->m_pHelp)
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "help", pCmdInfo->m_pHelp);
		}
		else
			pSelf->Console()->Print(
					IConsole::OUTPUT_LEVEL_STANDARD,
					"help",
					"Command is either unknown or you have given a blank command without any parameters.");
	}
}

void CGameContext::ConSettings(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;

	if (pResult->NumArguments() == 0)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				"to check a server setting say /settings and setting's name, setting names are:");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				"teams, cheats, collision, hooking, endlesshooking, me, ");
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				"hitting, oldlaser, timeout, votes, pause and scores");
	}
	else
	{
		const char *pArg = pResult->GetString(0);
		char aBuf[256];
		float ColTemp;
		float HookTemp;
		pSelf->m_Tuning.Get("player_collision", &ColTemp);
		pSelf->m_Tuning.Get("player_hooking", &HookTemp);
		if (str_comp(pArg, "teams") == 0)
		{
			str_format(aBuf, sizeof(aBuf), "%s %s",
					g_Config.m_SvTeam == 1 ?
							"Teams are available on this server" :
							(g_Config.m_SvTeam == 0 || g_Config.m_SvTeam == 3) ?
									"Teams are not available on this server" :
									"You have to be in a team to play on this server", /*g_Config.m_SvTeamStrict ? "and if you die in a team all of you die" : */
									"and all of your team will die if the team is locked");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings", aBuf);
		}
		else if (str_comp(pArg, "cheats") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvTestingCommands ?
						"Cheats are enabled on this server" :
						"Cheats are disabled on this server");
		}
		else if (str_comp(pArg, "collision") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				ColTemp ?
						"Players can collide on this server" :
						"Players can't collide on this server");
		}
		else if (str_comp(pArg, "hooking") == 0)
		{
			pSelf->Console()->Print( IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				HookTemp ?
						"Players can hook each other on this server" :
						"Players can't hook each other on this server");
		}
		else if (str_comp(pArg, "endlesshooking") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvEndlessDrag ?
						"Players hook time is unlimited" :
						"Players hook time is limited");
		}
		else if (str_comp(pArg, "hitting") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvHit ?
						"Players weapons affect others" :
						"Players weapons has no affect on others");
		}
		else if (str_comp(pArg, "oldlaser") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvOldLaser ?
						"Lasers can hit you if you shot them and they pull you towards the bounce origin (Like DDRace Beta)" :
						"Lasers can't hit you if you shot them, and they pull others towards the shooter");
		}
		else if (str_comp(pArg, "me") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvSlashMe ?
						"Players can use /me commands the famous IRC Command" :
						"Players can't use the /me command");
		}
		else if (str_comp(pArg, "timeout") == 0)
		{
			str_format(aBuf, sizeof(aBuf), "The Server Timeout is currently set to %d seconds", g_Config.m_ConnTimeout);
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings", aBuf);
		}
		else if (str_comp(pArg, "votes") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvVoteKick ?
						"Players can use Callvote menu tab to kick offenders" :
						"Players can't use the Callvote menu tab to kick offenders");
			if (g_Config.m_SvVoteKick)
			{
				str_format(aBuf, sizeof(aBuf),
						"Players are banned for %d minute(s) if they get voted off", g_Config.m_SvVoteKickBantime);
						
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
						g_Config.m_SvVoteKickBantime ?
								aBuf :
								"Players are just kicked and not banned if they get voted off");
			}
		}
		else if (str_comp(pArg, "pause") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvPauseable ?
						"/spec will pause you and your tee will vanish" :
						"/spec will pause you but your tee will not vanish");
		}
		else if (str_comp(pArg, "scores") == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
				g_Config.m_SvHideScore ?
						"Scores are private on this server" :
						"Scores are public on this server");
		}
		else
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "settings",
			"no matching settings found, type /settings to view them");
		}
	}
}

void CGameContext::ConRules(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	bool Printed = false;
	if (g_Config.m_SvDDRaceRules)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "rules",
				"Be nice.");
		Printed = true;
	}
	#define _RL(n) g_Config.m_SvRulesLine ## n
	char *pRuleLines[] = {
		_RL(1), _RL(2), _RL(3), _RL(4), _RL(5),
		_RL(6), _RL(7), _RL(8), _RL(9), _RL(10),
	};
	for(unsigned i = 0; i < sizeof(pRuleLines) / sizeof(pRuleLines[0]); i++)
	{
		if(pRuleLines[i][0])
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD,
				"rules", pRuleLines[i]);
			Printed = true;
		}
	}
	if (!Printed)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "rules",
				"No Rules Defined, Kill em all!!");
	}
}

void ToggleSpecPause(IConsole::IResult *pResult, void *pUserData, int PauseType)
{
	if(!CheckClientID(pResult->m_ClientID))
		return;

	CGameContext *pSelf = (CGameContext *) pUserData;
	IServer* pServ = pSelf->Server();
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer)
		return;

	int PauseState = pPlayer->IsPaused();
	if(PauseState > 0)
	{
		char aBuf[128];
		str_format(aBuf, sizeof(aBuf), "You are force-paused for %d seconds.", (PauseState - pServ->Tick()) / pServ->TickSpeed());
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "spec", aBuf);
	}
	else if(pResult->NumArguments() > 0)
	{
		if(-PauseState == PauseType && pPlayer->m_SpectatorID != pResult->m_ClientID && pServ->ClientIngame(pPlayer->m_SpectatorID) && !str_comp(pServ->ClientName(pPlayer->m_SpectatorID), pResult->GetString(0)))
		{
			pPlayer->Pause(CPlayer::PAUSE_NONE, false);
		}
		else
		{
			pPlayer->Pause(PauseType, false);
			pPlayer->SpectatePlayerName(pResult->GetString(0));
		}
	}
	else if(-PauseState == PauseType)
	{
		pPlayer->Pause(CPlayer::PAUSE_NONE, false);
	}
	else if(-PauseState != PauseType)
	{
		pPlayer->Pause(PauseType, false);
	}
}

void ToggleSpecPauseVoted(IConsole::IResult *pResult, void *pUserData, int PauseType)
{
	if(!CheckClientID(pResult->m_ClientID))
		return;

	CGameContext *pSelf = (CGameContext *) pUserData;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer)
		return;

	int PauseState = pPlayer->IsPaused();
	if(PauseState > 0)
	{
		IServer* pServ = pSelf->Server();
		char aBuf[128];
		str_format(aBuf, sizeof(aBuf), "You are force-paused for %d seconds.", (PauseState - pServ->Tick()) / pServ->TickSpeed());
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "spec", aBuf);
	}
	else if(-PauseState == PauseType)
	{
		pPlayer->Pause(CPlayer::PAUSE_NONE, false);
	}
	else if(!pSelf->m_VoteCloseTime || (!pSelf->m_VoteKick && !pSelf->m_VoteSpec) || (pPlayer->IsPaused() && pPlayer->m_SpectatorID == pSelf->m_VoteVictim) || pResult->m_ClientID == pSelf->m_VoteVictim)
	{
		pPlayer->Pause(PauseType, false);
	}
	else
	{
		pPlayer->Pause(PauseType, false);
		pPlayer->m_SpectatorID = pSelf->m_VoteVictim;
	}
}

void CGameContext::ConToggleSpec(IConsole::IResult *pResult, void *pUserData)
{
	ToggleSpecPause(pResult, pUserData, g_Config.m_SvPauseable ? CPlayer::PAUSE_SPEC : CPlayer::PAUSE_PAUSED);
}

void CGameContext::ConToggleSpecVoted(IConsole::IResult *pResult, void *pUserData)
{
	ToggleSpecPauseVoted(pResult, pUserData, g_Config.m_SvPauseable ? CPlayer::PAUSE_SPEC : CPlayer::PAUSE_PAUSED);
}

void CGameContext::ConTogglePause(IConsole::IResult *pResult, void *pUserData)
{
	ToggleSpecPause(pResult, pUserData, CPlayer::PAUSE_PAUSED);
}

void CGameContext::ConTogglePauseVoted(IConsole::IResult *pResult, void *pUserData)
{
	ToggleSpecPauseVoted(pResult, pUserData, CPlayer::PAUSE_PAUSED);
}

void CGameContext::ConTeamTop5(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

#if defined(CONF_SQL)
	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		if(pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	if (g_Config.m_SvHideScore)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "teamtop5",
				"Showing the team top 5 is not allowed on this server.");
		return;
	}

	if (pResult->NumArguments() > 0)
		pSelf->Score()->ShowTeamTop5(pResult, pResult->m_ClientID, pUserData,
				pResult->GetInteger(0));
	else
		pSelf->Score()->ShowTeamTop5(pResult, pResult->m_ClientID, pUserData);

#if defined(CONF_SQL)
	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

void CGameContext::ConTop5(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

#if defined(CONF_SQL)
	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		if(pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	if (g_Config.m_SvHideScore)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "top5",
				"Showing the top 5 is not allowed on this server.");
		return;
	}

	if (pResult->NumArguments() > 0)
		pSelf->Score()->ShowTop5(pResult, pResult->m_ClientID, pUserData,
				pResult->GetInteger(0));
	else
		pSelf->Score()->ShowTop5(pResult, pResult->m_ClientID, pUserData);

#if defined(CONF_SQL)
	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

#if defined(CONF_SQL)
void CGameContext::ConTimes(IConsole::IResult *pResult, void *pUserData)
{
	if(!CheckClientID(pResult->m_ClientID)) return;
	CGameContext *pSelf = (CGameContext *)pUserData;

	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		if(pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;

	if(g_Config.m_SvUseSQL)
	{
		CSqlScore *pScore = (CSqlScore *)pSelf->Score();
		CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
		if(!pPlayer)
			return;

		if(pResult->NumArguments() == 0)
		{
			pScore->ShowTimes(pPlayer->GetCID(),1);
		}
		else if(pResult->NumArguments() < 3)
		{
			if (pResult->NumArguments() == 1)
			{
				if(pResult->GetInteger(0) != 0)
					pScore->ShowTimes(pPlayer->GetCID(),pResult->GetInteger(0));
				else
					pScore->ShowTimes(pPlayer->GetCID(), (str_comp(pResult->GetString(0), "me") == 0) ? pSelf->Server()->ClientName(pResult->m_ClientID) : pResult->GetString(0),1);
			}
			else if (pResult->GetInteger(1) != 0)
			{
				pScore->ShowTimes(pPlayer->GetCID(), (str_comp(pResult->GetString(0), "me") == 0) ? pSelf->Server()->ClientName(pResult->m_ClientID) : pResult->GetString(0),pResult->GetInteger(1));
			}
		}
		else
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "times", "/times needs 0, 1 or 2 parameter. 1. = name, 2. = start number");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "times", "Example: /times, /times me, /times Hans, /times \"Papa Smurf\" 5");
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "times", "Bad: /times Papa Smurf 5 # Good: /times \"Papa Smurf\" 5 ");
		}

		if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
			pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery = pSelf->Server()->Tick();
	}
}
#endif

void CGameContext::ConDND(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer)
		return;

	if(pPlayer->m_DND)
	{
		pPlayer->m_DND = false;
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dnd", "You will receive global chat and server messages");
	}
	else
	{
		pPlayer->m_DND = true;
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dnd", "You will not receive any further global chat and server messages");
	}
}

void CGameContext::ConMap(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	if (g_Config.m_SvMapVote == 0)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "map",
				"Admin has disabled /map");
		return;
	}

	if (pResult->NumArguments() <= 0)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "map", "Example: /map adr3 to call vote for Adrenaline 3. This means that the map name must start with 'a' and contain the characters 'd', 'r' and '3' in that order");
		return;
	}

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		if(pPlayer->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	pSelf->Score()->MapVote(pResult->m_ClientID, pResult->GetString(0));

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		pPlayer->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

void CGameContext::ConMapInfo(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		if(pPlayer->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	if (pResult->NumArguments() > 0)
		pSelf->Score()->MapInfo(pResult->m_ClientID, pResult->GetString(0));
	else
		pSelf->Score()->MapInfo(pResult->m_ClientID, g_Config.m_SvMap);

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		pPlayer->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

void CGameContext::ConTimeout(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	const char* pTimeout = pResult->NumArguments() > 0 ? pResult->GetString(0) : pPlayer->m_TimeoutCode;

	for(int i = 0; i < pSelf->Server()->MaxClients(); i++)
	{
		if (i == pResult->m_ClientID) continue;
		if (!pSelf->m_apPlayers[i]) continue;
		if (str_comp(pSelf->m_apPlayers[i]->m_TimeoutCode, pTimeout)) continue;
		if (pSelf->Server()->SetTimedOut(i, pResult->m_ClientID)) {
			if (pSelf->m_apPlayers[i]->GetCharacter())
				pSelf->SendTuningParams(i, pSelf->m_apPlayers[i]->GetCharacter()->m_TuneZone);
			return;
		}
	}

	pSelf->Server()->SetTimeoutProtected(pResult->m_ClientID);
	str_copy(pPlayer->m_TimeoutCode, pResult->GetString(0), sizeof(pPlayer->m_TimeoutCode));
}

void CGameContext::ConSave(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

#if defined(CONF_SQL)
	if(!g_Config.m_SvSaveGames)
	{
		pSelf->SendChatTarget(pResult->m_ClientID, "Save-function is disabled on this server");
		return;
	}

	if(g_Config.m_SvUseSQL)
		if(pPlayer->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;

	int Team = ((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.m_Core.Team(pResult->m_ClientID);

	const char* pCode = pResult->GetString(0);
	char aCountry[5];
	if(str_length(pCode) > 3 && pCode[0] >= 'A' && pCode[0] <= 'Z' && pCode[1] >= 'A'
		&& pCode[1] <= 'Z' && pCode[2] >= 'A' && pCode[2] <= 'Z')
	{
		if(pCode[3] == ' ')
		{
			str_copy(aCountry, pCode, 4);
			pCode = pCode + 4;
		}
		else if(str_length(pCode) > 4 && pCode[4] == ' ')
		{
			str_copy(aCountry, pCode, 5);
			pCode = pCode + 5;
		}
		else
		{
			str_copy(aCountry, g_Config.m_SvSqlServerName, sizeof(aCountry));
		}
	}
	else
	{
		str_copy(aCountry, g_Config.m_SvSqlServerName, sizeof(aCountry));
	}

	char aValidServerNames[sizeof(g_Config.m_SvSqlValidServerNames)];
	str_copy(aValidServerNames, g_Config.m_SvSqlValidServerNames, sizeof(aValidServerNames));
	char *p = strtok(aValidServerNames, ",");;

	while(p)
	{
		if(str_comp(p, aCountry) == 0)
		{
			pSelf->Score()->SaveTeam(Team, pCode, pResult->m_ClientID, aCountry);

			if(g_Config.m_SvUseSQL)
				pPlayer->m_LastSQLQuery = pSelf->Server()->Tick();

			return;
		}

		p = strtok(NULL, ",");
	}

	char aBuf[128];
	str_format(aBuf, sizeof(aBuf), "Unknown server name '%s'.", aCountry);
	pSelf->SendChatTarget(pResult->m_ClientID, aBuf);

#endif
}

void CGameContext::ConLoad(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

#if defined(CONF_SQL)
	if(!g_Config.m_SvSaveGames)
	{
		pSelf->SendChatTarget(pResult->m_ClientID, "Save-function is disabled on this server");
		return;
	}

	if(g_Config.m_SvUseSQL)
		if(pPlayer->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	if (pResult->NumArguments() > 0)
		pSelf->Score()->LoadTeam(pResult->GetString(0), pResult->m_ClientID);
	else
		return;

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		pPlayer->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

void CGameContext::ConTeamRank(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		if(pPlayer->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	if (pResult->NumArguments() > 0)
		if (!g_Config.m_SvHideScore)
			pSelf->Score()->ShowTeamRank(pResult->m_ClientID, pResult->GetString(0),
					true);
		else
			pSelf->Console()->Print(
					IConsole::OUTPUT_LEVEL_STANDARD,
					"teamrank",
					"Showing the team rank of other players is not allowed on this server.");
	else
		pSelf->Score()->ShowTeamRank(pResult->m_ClientID,
				pSelf->Server()->ClientName(pResult->m_ClientID));

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		pPlayer->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

void CGameContext::ConRank(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		if(pPlayer->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;
#endif

	if (pResult->NumArguments() > 0)
		if (!g_Config.m_SvHideScore)
			pSelf->Score()->ShowRank(pResult->m_ClientID, pResult->GetString(0),
					true);
		else
			pSelf->Console()->Print(
					IConsole::OUTPUT_LEVEL_STANDARD,
					"rank",
					"Showing the rank of other players is not allowed on this server.");
	else
		pSelf->Score()->ShowRank(pResult->m_ClientID,
				pSelf->Server()->ClientName(pResult->m_ClientID));

#if defined(CONF_SQL)
	if(g_Config.m_SvUseSQL)
		pPlayer->m_LastSQLQuery = pSelf->Server()->Tick();
#endif
}

void CGameContext::ConLockTeam(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	int Team = ((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.m_Core.Team(pResult->m_ClientID);

	bool Lock = ((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.TeamLocked(Team);

	if (pResult->NumArguments() > 0)
		Lock = !pResult->GetInteger(0);

	if(Team <= TEAM_FLOCK || Team >= TEAM_SUPER)
	{
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"print",
				"This team can't be locked");
		return;
	}

	if(pSelf->ProcessSpamProtection(pResult->m_ClientID))
		return;

	char aBuf[512];
	if(Lock)
	{
		((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.SetTeamLock(Team, false);

		str_format(aBuf, sizeof(aBuf), "'%s' unlocked your team.", pSelf->Server()->ClientName(pResult->m_ClientID));

		for (int i = 0; i < MAX_CLIENTS; i++)
			if (((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.m_Core.Team(i) == Team)
				pSelf->SendChatTarget(i, aBuf);
	}
	else if(!g_Config.m_SvTeamLock)
	{
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"print",
				"Team locking is disabled on this server");
	}
	else
	{
		((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.SetTeamLock(Team, true);

		str_format(aBuf, sizeof(aBuf), "'%s' locked your team. After the race started killing will kill everyone in your team.", pSelf->Server()->ClientName(pResult->m_ClientID));

		for (int i = 0; i < MAX_CLIENTS; i++)
			if (((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.m_Core.Team(i) == Team)
				pSelf->SendChatTarget(i, aBuf);
	}
}

void CGameContext::ConInviteTeam(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	CGameControllerDDRace *pController = (CGameControllerDDRace *)pSelf->m_pController;
	const char *pName = pResult->GetString(0);

	if(g_Config.m_SvTeam == 0 || g_Config.m_SvTeam == 3)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
				"Admin has disabled teams");
		return;
	}

	if(!g_Config.m_SvInvite)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "invite", "Admin has disabled invites");
		return;
	}

	int Team = pController->m_Teams.m_Core.Team(pResult->m_ClientID);
	if(Team > TEAM_FLOCK && Team < TEAM_SUPER)
	{
		int Target = -1;
		for(int i = 0; i < MAX_CLIENTS; i++)
		{
			if(!str_comp(pName, pSelf->Server()->ClientName(i)))
			{
				Target = i;
				break;
			}
		}

		if(Target < 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "invite", "Player not found");
			return;
		}

		if(pController->m_Teams.IsInvited(Team, Target))
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "invite", "Player already invited");
			return;
		}

		if(pSelf->m_apPlayers[pResult->m_ClientID] && pSelf->m_apPlayers[pResult->m_ClientID]->m_LastInvited + g_Config.m_SvInviteFrequency * pSelf->Server()->TickSpeed() > pSelf->Server()->Tick())
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "invite", "Can't invite this quickly");
			return;
		}

		pController->m_Teams.SetClientInvited(Team, Target, true);
		pSelf->m_apPlayers[pResult->m_ClientID]->m_LastInvited = pSelf->Server()->Tick();

		char aBuf[512];
		str_format(aBuf, sizeof aBuf, "'%s' invited you to team %d.", pSelf->Server()->ClientName(pResult->m_ClientID), Team);
		pSelf->SendChatTarget(Target, aBuf);

		str_format(aBuf, sizeof aBuf, "'%s' invited '%s' to your team.", pSelf->Server()->ClientName(pResult->m_ClientID), pSelf->Server()->ClientName(Target));;
		for (int i = 0; i < MAX_CLIENTS; i++)
			if (((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.m_Core.Team(i) == Team)
				pSelf->SendChatTarget(i, aBuf);
	}
	else
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "invite", "Can't invite players to this team");
}

void CGameContext::ConJoinTeam(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	CGameControllerDDRace *pController = (CGameControllerDDRace *)pSelf->m_pController;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	if (pSelf->m_VoteCloseTime && pSelf->m_VoteCreator == pResult->m_ClientID && (pSelf->m_VoteKick || pSelf->m_VoteSpec))
	{
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"join",
				"You are running a vote please try again after the vote is done!");
		return;
	}
	else if (g_Config.m_SvTeam == 0 || g_Config.m_SvTeam == 3)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
				"Admin has disabled teams");
		return;
	}
	else if (g_Config.m_SvTeam == 2 && pResult->GetInteger(0) == 0 && pPlayer->GetCharacter() && pPlayer->GetCharacter()->m_LastStartWarning < pSelf->Server()->Tick() - 3 * pSelf->Server()->TickSpeed())
	{
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"join",
				"You must join a team and play with somebody or else you can\'t play");
		pPlayer->GetCharacter()->m_LastStartWarning = pSelf->Server()->Tick();
	}

	if (pResult->NumArguments() > 0)
	{
		if (pPlayer->GetCharacter() == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
					"You can't change teams while you are dead/a spectator.");
		}
		else
		{
			if (pPlayer->m_Last_Team
					+ pSelf->Server()->TickSpeed()
					* g_Config.m_SvTeamChangeDelay
					> pSelf->Server()->Tick())
			{
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
						"You can\'t change teams that fast!");
			}
			else if(pResult->GetInteger(0) > 0 && pResult->GetInteger(0) < MAX_CLIENTS && pController->m_Teams.TeamLocked(pResult->GetInteger(0)) && !pController->m_Teams.IsInvited(pResult->GetInteger(0), pResult->m_ClientID))
			{
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
						g_Config.m_SvInvite ?
						"This team is locked using /lock. Only members of the team can unlock it using /lock." :
						"This team is locked using /lock. Only members of the team can invite you or unlock it using /lock.");
			}
			else if(pResult->GetInteger(0) > 0 && pResult->GetInteger(0) < MAX_CLIENTS && pController->m_Teams.Count(pResult->GetInteger(0)) >= g_Config.m_SvTeamMaxSize)
			{
				char aBuf[512];
				str_format(aBuf, sizeof(aBuf), "This team already has the maximum allowed size of %d players", g_Config.m_SvTeamMaxSize);
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join", aBuf);
			}
			else if (((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.SetCharacterTeam(
					pPlayer->GetCID(), pResult->GetInteger(0)))
			{
				char aBuf[512];
				str_format(aBuf, sizeof(aBuf), "%s joined team %d",
						pSelf->Server()->ClientName(pPlayer->GetCID()),
						pResult->GetInteger(0));
				pSelf->SendChat(-1, CGameContext::CHAT_ALL, aBuf);
				pPlayer->m_Last_Team = pSelf->Server()->Tick();
			}
			else
			{
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
						"You cannot join this team at this time");
			}
		}
	}
	else
	{
		char aBuf[512];
		if (!pPlayer->IsPlaying())
		{
			pSelf->Console()->Print(
					IConsole::OUTPUT_LEVEL_STANDARD,
					"join",
					"You can't check your team while you are dead/a spectator.");
		}
		else
		{
			str_format(
					aBuf,
					sizeof(aBuf),
					"You are in team %d",
					((CGameControllerDDRace*) pSelf->m_pController)->m_Teams.m_Core.Team(
							pResult->m_ClientID));
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "join",
					aBuf);
		}
	}
}

void CGameContext::ConMe(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	char aBuf[256 + 24];

	str_format(aBuf, 256 + 24, "'%s' %s",
			pSelf->Server()->ClientName(pResult->m_ClientID),
			pResult->GetString(0));
	if (g_Config.m_SvSlashMe)
		pSelf->SendChat(-2, CGameContext::CHAT_ALL, aBuf, pResult->m_ClientID);
	else
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"me",
				"/me is disabled on this server, admin can enable it by using sv_slash_me");
}

void CGameContext::ConConverse(IConsole::IResult *pResult, void *pUserData)
{
	// This will never be called
}

void CGameContext::ConWhisper(IConsole::IResult *pResult, void *pUserData)
{
	// This will never be called
}

void CGameContext::ConSetEyeEmote(IConsole::IResult *pResult,
		void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;
	if(pResult->NumArguments() == 0) {
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"emote",
				(pPlayer->m_EyeEmote) ?
						"You can now use the preset eye emotes." :
						"You don't have any eye emotes, remember to bind some. (until you die)");
		return;
	}
	else if(str_comp_nocase(pResult->GetString(0), "on") == 0)
		pPlayer->m_EyeEmote = true;
	else if(str_comp_nocase(pResult->GetString(0), "off") == 0)
		pPlayer->m_EyeEmote = false;
	else if(str_comp_nocase(pResult->GetString(0), "toggle") == 0)
		pPlayer->m_EyeEmote = !pPlayer->m_EyeEmote;
	pSelf->Console()->Print(
			IConsole::OUTPUT_LEVEL_STANDARD,
			"emote",
			(pPlayer->m_EyeEmote) ?
					"You can now use the preset eye emotes." :
					"You don't have any eye emotes, remember to bind some. (until you die)");
}

void CGameContext::ConEyeEmote(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (g_Config.m_SvEmotionalTees == -1)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "emote",
				"Server admin disabled emotes.");
		return;
	}

	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	if (pResult->NumArguments() == 0)
	{
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"emote",
				"Emote commands are: /emote surprise /emote blink /emote close /emote angry /emote happy /emote pain");
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"emote",
				"Example: /emote surprise 10 for 10 seconds or /emote surprise (default 1 second)");
	}
	else
	{
			if(pPlayer->m_LastEyeEmote + g_Config.m_SvEyeEmoteChangeDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
				return;

			if (!str_comp(pResult->GetString(0), "angry"))
				pPlayer->m_DefEmote = EMOTE_ANGRY;
			else if (!str_comp(pResult->GetString(0), "blink"))
				pPlayer->m_DefEmote = EMOTE_BLINK;
			else if (!str_comp(pResult->GetString(0), "close"))
				pPlayer->m_DefEmote = EMOTE_BLINK;
			else if (!str_comp(pResult->GetString(0), "happy"))
				pPlayer->m_DefEmote = EMOTE_HAPPY;
			else if (!str_comp(pResult->GetString(0), "pain"))
				pPlayer->m_DefEmote = EMOTE_PAIN;
			else if (!str_comp(pResult->GetString(0), "surprise"))
				pPlayer->m_DefEmote = EMOTE_SURPRISE;
			else if (!str_comp(pResult->GetString(0), "normal"))
				pPlayer->m_DefEmote = EMOTE_NORMAL;
			else
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD,
						"emote", "Unknown emote... Say /emote");

			int Duration = 1;
			if (pResult->NumArguments() > 1)
				Duration = pResult->GetInteger(1);

			pPlayer->m_DefEmoteReset = pSelf->Server()->Tick()
							+ Duration * pSelf->Server()->TickSpeed();
			pPlayer->m_LastEyeEmote = pSelf->Server()->Tick();
	}
}

void CGameContext::ConNinjaJetpack(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;
	if (pResult->NumArguments())
		pPlayer->m_NinjaJetpack = pResult->GetInteger(0);
	else
		pPlayer->m_NinjaJetpack = !pPlayer->m_NinjaJetpack;
}

void CGameContext::ConShowOthers(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;
	if (g_Config.m_SvShowOthers)
	{
		if (pResult->NumArguments())
			pPlayer->m_ShowOthers = pResult->GetInteger(0);
		else
			pPlayer->m_ShowOthers = !pPlayer->m_ShowOthers;
	}
	else
		pSelf->Console()->Print(
				IConsole::OUTPUT_LEVEL_STANDARD,
				"showotherschat",
				"Showing players from other teams is disabled by the server admin");
}

void CGameContext::ConShowAll(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	if (pResult->NumArguments())
	{
		if (pPlayer->m_ShowAll == (bool)pResult->GetInteger(0))
			return;

		pPlayer->m_ShowAll = pResult->GetInteger(0);
	}
	else
	{
		pPlayer->m_ShowAll = !pPlayer->m_ShowAll;
	}

	if (pPlayer->m_ShowAll)
		pSelf->SendChatTarget(pResult->m_ClientID, "You will now see all tees on this server, no matter the distance");
	else
		pSelf->SendChatTarget(pResult->m_ClientID, "You will no longer see all tees on this server");
}

void CGameContext::ConSpecTeam(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	if (pResult->NumArguments())
		pPlayer->m_SpecTeam = pResult->GetInteger(0);
	else
		pPlayer->m_SpecTeam = !pPlayer->m_SpecTeam;
}

bool CheckClientID(int ClientID)
{
	if (ClientID < 0 || ClientID >= MAX_CLIENTS)
		return false;
	return true;
}

void CGameContext::ConSayTime(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	int ClientID;
	char aBufname[MAX_NAME_LENGTH];

	if (pResult->NumArguments() > 0)
	{
		for(ClientID = 0; ClientID < MAX_CLIENTS; ClientID++)
			if (str_comp(pResult->GetString(0), pSelf->Server()->ClientName(ClientID)) == 0)
				break;

		if(ClientID == MAX_CLIENTS)
			return;

		str_format(aBufname, sizeof(aBufname), "%s's", pSelf->Server()->ClientName(ClientID));
	}
	else
	{
		str_copy(aBufname, "Your", sizeof(aBufname));
		ClientID = pResult->m_ClientID;
	}

	CPlayer *pPlayer = pSelf->m_apPlayers[ClientID];
	if (!pPlayer)
		return;
	CCharacter* pChr = pPlayer->GetCharacter();
	if (!pChr)
		return;
	if(pChr->m_DDRaceState != DDRACE_STARTED)
		return;

	char aBuftime[64];
	int IntTime = (int)((float)(pSelf->Server()->Tick() - pChr->m_StartTime)
			/ ((float)pSelf->Server()->TickSpeed()));
	str_format(aBuftime, sizeof(aBuftime), "%s time is %s%d:%s%d",
			aBufname,
			((IntTime / 60) > 9) ? "" : "0", IntTime / 60,
			((IntTime % 60) > 9) ? "" : "0", IntTime % 60);
	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "time", aBuftime);
}

void CGameContext::ConSayTimeAll(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;
	CCharacter* pChr = pPlayer->GetCharacter();
	if (!pChr)
		return;
	if(pChr->m_DDRaceState != DDRACE_STARTED)
		return;

	char aBuftime[64];
	int IntTime = (int)((float)(pSelf->Server()->Tick() - pChr->m_StartTime)
			/ ((float)pSelf->Server()->TickSpeed()));
	str_format(aBuftime, sizeof(aBuftime),
			"%s\'s current race time is %s%d:%s%d",
			pSelf->Server()->ClientName(pResult->m_ClientID),
			((IntTime / 60) > 9) ? "" : "0", IntTime / 60,
			((IntTime % 60) > 9) ? "" : "0", IntTime % 60);
	pSelf->SendChat(-1, CGameContext::CHAT_ALL, aBuftime, pResult->m_ClientID);
}

void CGameContext::ConTime(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;
	CCharacter* pChr = pPlayer->GetCharacter();
	if (!pChr)
		return;

	char aBuftime[64];
	int IntTime = (int)((float)(pSelf->Server()->Tick() - pChr->m_StartTime)
			/ ((float)pSelf->Server()->TickSpeed()));
	str_format(aBuftime, sizeof(aBuftime), "Your time is %s%d:%s%d",
				((IntTime / 60) > 9) ? "" : "0", IntTime / 60,
				((IntTime % 60) > 9) ? "" : "0", IntTime % 60);
	pSelf->SendBroadcast(aBuftime, pResult->m_ClientID);
}

static const char s_aaMsg[3][128] = {"game/round timer.", "broadcast.", "both game/round timer and broadcast."};

void CGameContext::ConSetTimerType(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;

	if (!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	char aBuf[128];

	if(pResult->NumArguments() > 0)
	{
		int OldType = pPlayer->m_TimerType;

		if(str_comp_nocase(pResult->GetString(0), "gametimer") == 0)
		{
			if(pPlayer->m_ClientVersion >= VERSION_DDNET_GAMETICK)
				pPlayer->m_TimerType = CPlayer::TIMERTYPE_GAMETIMER;
			else
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "timer", "gametimer is not supported by your client.");
		}
		else if(str_comp_nocase(pResult->GetString(0), "broadcast") == 0)
			pPlayer->m_TimerType = CPlayer::TIMERTYPE_BROADCAST;
		else if(str_comp_nocase(pResult->GetString(0), "both") == 0)
		{
			if(pPlayer->m_ClientVersion >= VERSION_DDNET_GAMETICK)
				pPlayer->m_TimerType = CPlayer::TIMERTYPE_GAMETIMER_AND_BROADCAST;
			else
			{
				pPlayer->m_TimerType = CPlayer::TIMERTYPE_BROADCAST;
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "timer", "gametimer is not supported by your client.");
			}
		}
		else if(str_comp_nocase(pResult->GetString(0), "none") == 0)
			pPlayer->m_TimerType = CPlayer::TIMERTYPE_NONE;
		else if(str_comp_nocase(pResult->GetString(0), "cycle") == 0)
		{
			if(pPlayer->m_ClientVersion >= VERSION_DDNET_GAMETICK)
			{
				if(pPlayer->m_TimerType < CPlayer::TIMERTYPE_NONE)
					pPlayer->m_TimerType++;
				else if(pPlayer->m_TimerType == CPlayer::TIMERTYPE_NONE)
					pPlayer->m_TimerType = CPlayer::TIMERTYPE_GAMETIMER;
			}
			else
			{
				if(pPlayer->m_TimerType < CPlayer::TIMERTYPE_NONE)
					pPlayer->m_TimerType = CPlayer::TIMERTYPE_NONE;
				else if(pPlayer->m_TimerType == CPlayer::TIMERTYPE_NONE)
					pPlayer->m_TimerType = CPlayer::TIMERTYPE_BROADCAST;
			}
		}
		else
		{
			str_format(aBuf, sizeof(aBuf), "Unknown \"%s\" parameter. Accepted values: gametimer, broadcast, both, none, cycle", pResult->GetString(0));
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "timer", aBuf);
			return;
		}

		if((OldType == CPlayer::TIMERTYPE_BROADCAST || OldType == CPlayer::TIMERTYPE_GAMETIMER_AND_BROADCAST) && (pPlayer->m_TimerType == CPlayer::TIMERTYPE_GAMETIMER || pPlayer->m_TimerType == CPlayer::TIMERTYPE_NONE))
			pSelf->SendBroadcast("", pResult->m_ClientID);
	}

	if(pPlayer->m_TimerType <= CPlayer::TIMERTYPE_GAMETIMER_AND_BROADCAST && pPlayer->m_TimerType >= CPlayer::TIMERTYPE_GAMETIMER)
		str_format(aBuf, sizeof(aBuf), "Timer is displayed in %s", s_aaMsg[pPlayer->m_TimerType]);
	else if(pPlayer->m_TimerType == CPlayer::TIMERTYPE_NONE)
		str_format(aBuf, sizeof(aBuf), "Timer isn't displayed.");

	pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "timer", aBuf);
}
void CGameContext::ConProtectedKill(IConsole::IResult *pResult, void *pUserData){
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;
	CCharacter* pChr = pPlayer->GetCharacter();
	if (!pChr)
		return;

	int CurrTime = (pSelf->Server()->Tick() - pChr->m_StartTime) / pSelf->Server()->TickSpeed();
	if(g_Config.m_SvKillProtection != 0 && CurrTime >= (60 * g_Config.m_SvKillProtection) && pChr->m_DDRaceState == DDRACE_STARTED)
	{
			pPlayer->KillCharacter(WEAPON_SELF);

			//char aBuf[64];
			//str_format(aBuf, sizeof(aBuf), "You killed yourself in: %s%d:%s%d",
			//		((CurrTime / 60) > 9) ? "" : "0", CurrTime / 60,
			//		((CurrTime % 60) > 9) ? "" : "0", CurrTime % 60);
			//pSelf->SendChatTarget(pResult->m_ClientID, aBuf);
	}
}

void CGameContext::ConModhelp(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;

	if(!CheckClientID(pResult->m_ClientID))
		return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer)
		return;

	if(pPlayer->m_pPostJson)
	{
		pSelf->SendChatTarget(pResult->m_ClientID, "Your last request hasn't finished processing yet, please slow down.");
		return;
	}

	int CurTick = pSelf->Server()->Tick();
	if(pPlayer->m_ModhelpTick != -1)
	{
		int TickSpeed = pSelf->Server()->TickSpeed();
		int NextModhelpTick = pPlayer->m_ModhelpTick + g_Config.m_SvModhelpDelay * TickSpeed;
		if(NextModhelpTick > CurTick)
		{
			char aBuf[128];
			str_format(aBuf, sizeof(aBuf), "You must wait %d seconds before you can execute this command again.",
				(NextModhelpTick - CurTick) / TickSpeed);
			pSelf->SendChatTarget(pResult->m_ClientID, aBuf);
			return;
		}
	}

	pPlayer->m_ModhelpTick = CurTick;

	char aBuf[512];
	str_format(aBuf, sizeof(aBuf), "Moderator help is requested by '%s' (ID: %d):",
			pSelf->Server()->ClientName(pResult->m_ClientID),
			pResult->m_ClientID);

	// Send the request to all authed clients.
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(pSelf->m_apPlayers[i] && pSelf->Server()->ClientAuthed(i))
		{
			pSelf->SendChatTarget(i, aBuf);
			pSelf->SendChatTarget(i, pResult->GetString(0));
		}
	}
	if(g_Config.m_SvModhelpUrl[0])
	{
		bool ModeratorPresent = false;
		for(int i = 0; i < MAX_CLIENTS; i++)
		{
			if(pSelf->m_apPlayers[i] && pSelf->Server()->ClientAuthed(i))
			{
				ModeratorPresent = true;
				break;
			}
		}

		char aJson[512];
		char aPlayerName[64];
		char aMessage[128];
		str_format(aJson, sizeof(aJson), "{\"port\":%d,\"moderator_present\":%s,\"player_id\":%d,\"blacklisted\":%s,\"player_name\":\"%s\",\"message\":\"%s\"}",
			g_Config.m_SvPort,
			JsonBool(ModeratorPresent),
			pResult->m_ClientID,
			!pSelf->Server()->DnsblWhite(pResult->m_ClientID) ? "true" : "false",
			EscapeJson(aPlayerName, sizeof(aPlayerName), pSelf->Server()->ClientName(pResult->m_ClientID)),
			EscapeJson(aMessage, sizeof(aMessage), pResult->GetString(0)));
		pSelf->Engine()->AddJob(pPlayer->m_pPostJson = std::make_shared<CPostJson>(g_Config.m_SvModhelpUrl, false, aJson));
	}
}

#if defined(CONF_SQL)
void CGameContext::ConPoints(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		if(pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;

	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if (!pPlayer)
		return;

	if (pResult->NumArguments() > 0)
		if (!g_Config.m_SvHideScore)
			pSelf->Score()->ShowPoints(pResult->m_ClientID, pResult->GetString(0),
					true);
		else
			pSelf->Console()->Print(
					IConsole::OUTPUT_LEVEL_STANDARD,
					"points",
					"Showing the global points of other players is not allowed on this server.");
	else
		pSelf->Score()->ShowPoints(pResult->m_ClientID,
				pSelf->Server()->ClientName(pResult->m_ClientID));

	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery = pSelf->Server()->Tick();
}
#endif

#if defined(CONF_SQL)
void CGameContext::ConTopPoints(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;

	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		if(pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery + g_Config.m_SvSqlQueriesDelay * pSelf->Server()->TickSpeed() >= pSelf->Server()->Tick())
			return;

	if (g_Config.m_SvHideScore)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "toppoints",
				"Showing the global top points is not allowed on this server.");
		return;
	}

	if (pResult->NumArguments() > 0)
		pSelf->Score()->ShowTopPoints(pResult, pResult->m_ClientID, pUserData,
				pResult->GetInteger(0));
	else
		pSelf->Score()->ShowTopPoints(pResult, pResult->m_ClientID, pUserData);

	if(pSelf->m_apPlayers[pResult->m_ClientID] && g_Config.m_SvUseSQL)
		pSelf->m_apPlayers[pResult->m_ClientID]->m_LastSQLQuery = pSelf->Server()->Tick();
}
#endif

// iDDNet
void CGameContext::ConDummy(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;
	int ClientID = pResult->m_ClientID;
	if(!g_Config.m_SvDummies)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dummy", "Dummies are disabled on the server. Set in config sv_dummies 1 to enable.");
		return;
	}
	CPlayer *pPlayer = pSelf->m_apPlayers[ClientID];
	if(!pPlayer)
		return;
	if(pPlayer->m_HasDummy)
	{
		if(!g_Config.m_SvDummy && !g_Config.m_SvDummyTpBeforeStart)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dummy", "Teleporting dummy to owner is disabled on the server. Set in config sv_dummy 1 to enable.");
			return;
		}

		if (pPlayer->GetCharacter() == 0)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "spec", "You can't teleport dummy while you are dead/a spectator.");
			return;
		}

		int DummyID = pPlayer->m_DummyID;

		CCharacter* pChr = pPlayer->GetCharacter();
		CCharacter* pDummyChr = pSelf ->m_apPlayers[DummyID]->GetCharacter();

		if(!g_Config.m_SvDummy && g_Config.m_SvDummyTpBeforeStart)
			if(pChr->m_DDRaceState != DDRACE_NONE)
				return;

		if(!CheckClientID(DummyID) || !pSelf ->m_apPlayers[DummyID] || !pSelf ->m_apPlayers[DummyID]->m_IsDummy)
		{
			pPlayer->m_HasDummy = false;
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dummy", "Your dummy not found, sorry. Try to reconnect.");
			return;
		}

		if(pPlayer->GetTeam()!=TEAM_SPECTATORS && !pPlayer->IsPaused() &&
		   pChr && pDummyChr &&
		   pSelf->m_apPlayers[DummyID]->GetTeam()!=TEAM_SPECTATORS)
		{
			if(pPlayer->m_Last_Dummy + pSelf->Server()->TickSpeed() * g_Config.m_SvDummyDelay/2 <= pSelf->Server()->Tick())
			{
				if(!pChr->IsGrounded())
				{
					pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dummy", "You can\'t teleport dummy in air.");
					return;
				}
				CPlayerRescueState state = GetPlayerState(pChr);
				ApplyPlayerState(state, pDummyChr, true);
				pSelf->CreatePlayerSpawn(pDummyChr->Core()->m_Pos);
				pPlayer->m_Last_Dummy = pSelf->Server()->Tick();			
			}
			else
				pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dummy", "You can\'t /dummy that often.");
		}
	}
	else //hasn't dummy
	{
		//find free slot
		int free_slot_id = -1;
		for(int i = 0; i < g_Config.m_SvMaxClients; i++)
		{
			if(free_slot_id >=0) continue;
			if(!pSelf->m_apPlayers[i]) free_slot_id = i;
		}
		if(free_slot_id == -1)
		{
			pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dummy", "Dummy was\'t created due to absence of free slots. Ask admin to set in config sv_dummies 1 and restart server, or just kick anybody ;)");
			return;
		}
		char dummy_name[512],dummy_clan[512];
		str_format(dummy_name, sizeof(dummy_name), "[D] %s", pSelf->Server()->ClientName(ClientID));
		str_copy(dummy_clan, pSelf->Server()->ClientClan(ClientID), MAX_CLAN_LENGTH);
		pSelf->NewDummy(free_slot_id, //id
						pPlayer->m_TeeInfos.m_UseCustomColor, //custom color
						pPlayer->m_TeeInfos.m_ColorFeet, //body color
						pPlayer->m_TeeInfos.m_ColorBody, //feet color
						pPlayer->m_TeeInfos.m_SkinName, //skin
						dummy_name, //name
						dummy_clan, //clan
						pSelf->Server()->ClientCountry(ClientID));
		if(pSelf->m_apPlayers[free_slot_id])
		{
			pPlayer->m_HasDummy = true;
			pPlayer->m_DummyID = free_slot_id;
			//dummy keeps owner's id in CPlayer::m_DummyID, sry for mess ;)
			pSelf->m_apPlayers[free_slot_id]->m_DummyID = ClientID;
		}
	}
}

void CGameContext::ConDummyDelete(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	int DummyID = pPlayer->m_DummyID;
	if(!pPlayer->m_HasDummy || !pSelf->m_apPlayers[DummyID] || !pSelf->m_apPlayers[DummyID]->m_IsDummy)
		return;
	pSelf->Server()->DummyLeave(DummyID, "Normal quit");
	pPlayer->m_HasDummy = false;
	pPlayer->m_DummyID = -1;
}

// iDDNet  
void CGameContext::CondbgDummy(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	if (!CheckClientID(pResult->m_ClientID))
		return;
	int ClientID = pResult->m_ClientID;
	CPlayer *pPlayer = pSelf->m_apPlayers[ClientID];
	if(!pPlayer)
		return;
	for(int i = 0; i < g_Config.m_SvMaxClients; i++)
	{
		if(pSelf->m_apPlayers[i])
			continue;
		pSelf->NewDummy(i, true);
		return;
	}
}

void CGameContext::CondbgDummyDelete(IConsole::IResult *pResult, void *pUserData)  
{  
	CGameContext *pSelf = (CGameContext *) pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	for(int i = 0; i < g_Config.m_SvMaxClients; i++)
	{
		//if(!pPlayer->m_HasDummy || !pSelf->m_apPlayers[i] || !pSelf->m_apPlayers[i]->m_IsDummy)
		if(pSelf->m_apPlayers[i])
			if(pSelf->m_apPlayers[i]->m_IsDummy && pSelf->m_apPlayers[i]->m_DummyID == -1)
			{
				pSelf->Server()->DummyLeave(i, "Console quit");
				return;
			}
	}
}

void CGameContext::ConRescue(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	int TargetID;
	if(g_Config.m_SvDummies && pSelf->m_apPlayers[pResult->m_ClientID]->m_HasDummy && str_comp_nocase(pResult->GetString(0), "d") == 0)
		TargetID = pPlayer->m_DummyID;
	else
		TargetID = pResult->m_ClientID;

	CCharacter* pChr = pSelf->m_apPlayers[TargetID]->GetCharacter();

	if(!g_Config.m_SvRescue)
	{
		pSelf->SendChatTarget(pResult->m_ClientID, "Rescue is not activated.");
		return;
	}

	if(!pChr || !pChr->IsAlive() || pChr->m_FreezeTime == 0)
		return;

	if(pChr->m_SavedPos == vec2(0,0))
	{
		pSelf->SendChatTarget(pResult->m_ClientID, "No position saved!");
		return;
	}

	if(pChr->m_DeepFreeze && !g_Config.m_SvRescueDeep)
	{
		pSelf->SendChatTarget(pResult->m_ClientID, "You are deepfreezed, undeepfreeze first!");
		return;
	}

	// reset players' hook
	for(int i = 0; i < MAX_CLIENTS; i++)
	{
		if(pSelf->m_apPlayers[i])
		{
			CCharacter* pChr2 = pSelf->m_apPlayers[i]->GetCharacter();
			//who hooks me?
			if(pChr2 && pChr2->Core()->m_HookedPlayer == TargetID)
			{
				//Release hook
				pChr2->Core()->m_HookedPlayer = -1;
				pChr2->Core()->m_HookState = HOOK_RETRACTED;
				pChr2->Core()->m_HookPos = pChr2->Core()->m_Pos;
			}
		}
	}
	if(g_Config.m_SvRescueEffects)
	{
		//Blood effect
		pChr->GameServer()->CreateDeath(pChr->m_Pos, TargetID);
		//Spawn effect
		pChr->GameServer()->CreatePlayerSpawn(pChr->m_SavedPos);
	}
	//Teleport player
	pChr->Core()->m_Pos = pChr->m_PrevPos = pChr->m_Pos = pChr->m_SavedPos;
	pChr->Core()->m_Vel = vec2(0.f, 0.f); // reset momentum

	//RescueFlags
	pSelf->ApplyRescueFlags(TargetID, pChr);

	if(pChr->m_DeepFreeze && g_Config.m_SvRescueDeep)
		pChr->m_DeepFreeze = false;

	// if(pChr->m_FreezeTime && pChr->m_TileIndex != TILE_FREEZE && pChr->m_TileFIndex != TILE_FREEZE && pChr->Core()->m_Pos == pChr->m_SavedPos)
	// {
		pChr->UnFreeze();
	// }
}

void CGameContext::ConSwap(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	const int ClientID = pResult->m_ClientID;

	if(!CheckClientID(ClientID))
		return;

	if(!g_Config.m_SvSwap)
	{
		pSelf->SendChatTarget(ClientID, "Swap is not activated");
		return;
	}

	int ToSwap = -1;

	for(int Victim = 0; Victim < MAX_CLIENTS; Victim++)
		if (str_comp_nocase(pResult->GetString(0), pSelf->Server()->ClientName(Victim)) == 0)
			ToSwap = Victim;

	if(ToSwap == ClientID || ToSwap == -1)
		return;

	pSelf->m_aSwapRequest[ClientID] = ToSwap;

	if(pSelf->m_apPlayers[ToSwap]->m_IsDummy)
		return;

	if(pSelf->ProcessSpamProtection(ClientID)) // dont spam
		return;

	char aBuf[256];
	// check if ToSwap agrees
	if(pSelf->m_aSwapRequest[ToSwap] != ClientID)
	{
		// send  notification to ToSwap
		str_format(aBuf, sizeof(aBuf), "%s wants to swap places with you. Type \'/swap %s\' to accept.",
			   pSelf->Server()->ClientName(ClientID), pSelf->Server()->ClientName(ClientID));
		pSelf->SendChatTarget(ToSwap, aBuf);
		
		str_format(aBuf, sizeof(aBuf), "Requst sent to %s.",
			   pSelf->Server()->ClientName(ToSwap));
		pSelf->SendChatTarget(ClientID, aBuf);
	}
	else
	{
		// ToSwap agreed
		CCharacter * pChar1 = pSelf->GetPlayerChar(ClientID);
		CCharacter * pChar2 = pSelf->GetPlayerChar(ToSwap);
		if(!pChar1 || !pChar2 || pChar1->Team() != pChar2->Team())
		{
			// one is not alive or not in the same team
			const char * pStr = "Can\'t swap!";
			pSelf->SendChatTarget(ToSwap, pStr);
			pSelf->SendChatTarget(ClientID, pStr);
			return;
		}

		CPlayerRescueState state1 = GetPlayerState(pChar1),
			state2 = GetPlayerState(pChar2);
		
		// swap
		ApplyPlayerState(state2, pChar1, false);
		ApplyPlayerState(state1, pChar2, false);
		
		str_format(aBuf, sizeof(aBuf), "%s swapped with %s.",
			   pSelf->Server()->ClientName(ToSwap),
			   pSelf->Server()->ClientName(ClientID));
		pSelf->SendChat(-1, CGameContext::CHAT_ALL, aBuf);
		// reset swap requests
		pSelf->m_aSwapRequest[ToSwap] = -1;
		pSelf->m_aSwapRequest[ClientID] = -1;
	}
}


void CGameContext::ConDummyChange(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;

	if(!CheckClientID(pResult->m_ClientID))
		return;
	int ClientID = pResult->m_ClientID;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer)
		return;
	CCharacter * pChar1 = pSelf->GetPlayerChar(ClientID);
	CCharacter * pChar2 = pSelf->GetPlayerChar(pPlayer->m_DummyID);
	if(!pChar1 || !pChar2 || pChar1->Team() != pChar2->Team() || !pPlayer->m_HasDummy)
		return;

	if(pPlayer->m_Last_DummyChange + pSelf->Server()->TickSpeed() * g_Config.m_SvDummyChangeDelay/2 <= pSelf->Server()->Tick())
	{
		CPlayerRescueState state1 = GetPlayerState(pChar1),
		state2 = GetPlayerState(pChar2);
		// swap
		ApplyPlayerState(state2, pChar1, false);
		ApplyPlayerState(state1, pChar2, true);
	}
	else
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dc", "You can\'t /dummy_change that often.");
}
void CGameContext::ConDummyHammerFly(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	int ClientID = pResult->m_ClientID;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer) return;
	if (!g_Config.m_SvDummyHammer)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhf", "Control dummy is not activated on the server. Set in config sv_dummy_hammer 1 to enable.");
		return;
	}
	if(pPlayer->m_HasDummy == false || !CheckClientID(pPlayer->m_DummyID) || !pSelf->m_apPlayers[pPlayer->m_DummyID] || !pSelf->m_apPlayers[pPlayer->m_DummyID]->m_IsDummy)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhf", "You don\'t have dummy.Type '/d' in chat to get it.");
		return;
	}
	int DummyID = pPlayer->m_DummyID;
	if(!pSelf->GetPlayerChar(DummyID))
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhf", "Dummy is not alive yet. Wait when i spawn again and retry.");
		return;
	}
	CCharacter *pDumChr = pSelf->GetPlayerChar(DummyID);

	if (pResult->NumArguments() > 0 && pResult->GetInteger(0) >= 0)
		pDumChr->m_HammerFlyRange = pResult->GetInteger(0);
	else
		pDumChr->m_HammerFlyRange = 83;
	if(g_Config.m_SvDummyBroadcast == 1)
		if(pDumChr->m_DoHammerFly)
			pSelf->SendBroadcast("Dummy HammerFly: Disabled", ClientID);
		else
			pSelf->SendBroadcast("Dummy HammerFly: Enabled ", ClientID);
	pDumChr->m_DoHammerFly = (pDumChr->m_DoHammerFly==true)?(pDumChr->m_DoHammerFly==false):(pDumChr->m_DoHammerFly=true);

}
void CGameContext::ConDummyHook(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	int ClientID = pResult->m_ClientID;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer) return;
	if (!g_Config.m_SvDummyHook)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhook", "Control dummy is not activated on the server. Set in config sv_dummy_hook 1 to enable.");
		return;
	}
	if(pPlayer->m_HasDummy == false || !CheckClientID(pPlayer->m_DummyID) || !pSelf->m_apPlayers[pPlayer->m_DummyID] || !pSelf->m_apPlayers[pPlayer->m_DummyID]->m_IsDummy)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhook", "You don\'t have dummy.Type '/d' in chat to get it.");
		return;
	}
	int DummyID = pPlayer->m_DummyID;
	if(!pSelf->GetPlayerChar(DummyID))
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhook", "Dummy is not alive yet. Wait when i spawn again and retry.");
		return;
	}
	CCharacter *pDumChr = pSelf->GetPlayerChar(DummyID);
	if(g_Config.m_SvDummyBroadcast)
		if(pDumChr->m_DoHookFly)
			pSelf->SendBroadcast("Dummy HookFly: Disabled", ClientID);
		else
			pSelf->SendBroadcast("Dummy HookFly: Enabled ", ClientID);
	pDumChr->m_DoHookFly = (pDumChr->m_DoHookFly==true)?(pDumChr->m_DoHookFly==false):(pDumChr->m_DoHookFly=true);
}

void CGameContext::ConDummyAim(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	int ClientID = pResult->m_ClientID;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer) return;
	if(pPlayer->m_HasDummy == false || !CheckClientID(pPlayer->m_DummyID) || !pSelf->m_apPlayers[pPlayer->m_DummyID] || !pSelf->m_apPlayers[pPlayer->m_DummyID]->m_IsDummy)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhook", "You don\'t have dummy.Type '/d' in chat to get it.");
		return;
	}
	int DummyID = pPlayer->m_DummyID;
	if(!pSelf->GetPlayerChar(DummyID))
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dhook", "Dummy is not alive yet. Wait when i spawn again and retry.");
		return;
	}
	CCharacter *pDumChr = pSelf->GetPlayerChar(DummyID);
	if(g_Config.m_SvDummyBroadcast == 1)
		if(pDumChr->m_DoAim)
			pSelf->SendBroadcast("Dummy Aim: Disabled", ClientID);
		else
			pSelf->SendBroadcast("Dummy Aim: Enabled ", ClientID);
	pDumChr->m_DoAim = (pDumChr->m_DoAim==true)?(pDumChr->m_DoAim==false):(pDumChr->m_DoAim=true);
}

void CGameContext::ConDummyControl(IConsole::IResult *pResult, void *pUserData)
{
	// NOTE: /cd = /dcm+/pause
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer) return;
	if (!g_Config.m_SvControlDummy)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cd", "Control dummy is not activated on the server. Set in config sv_control_dummy 1 to enable.");
		return;
	}
	if(pPlayer->m_HasDummy == false || !CheckClientID(pPlayer->m_DummyID) || !pSelf->m_apPlayers[pPlayer->m_DummyID] || !pSelf->m_apPlayers[pPlayer->m_DummyID]->m_IsDummy)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "cd", "You don\'t have dummy.Type '/d' in chat to get it.");
		return;
	}
	if(!pPlayer->IsPaused() && pSelf->m_apPlayers[pPlayer->m_DummyID]->m_DummyCopiesMove)
		ConTogglePause(pResult,pUserData);
	else if(pPlayer->IsPaused() && !pSelf->m_apPlayers[pPlayer->m_DummyID]->m_DummyCopiesMove)
		ConDummyCopyMove(pResult,pUserData);
	else
	{
		ConDummyCopyMove(pResult,pUserData);
		ConTogglePause(pResult,pUserData);
	}
}

void CGameContext::ConDummyCopyMove(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *)pUserData;
	if(!CheckClientID(pResult->m_ClientID)) return;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];
	if(!pPlayer) return;
	if (!g_Config.m_SvDummyCopyMove)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dcm", "Dummy copy move command is not activated on the server. Set in config sv_dummy_copy_move 1 to enable.");
		return;
	}
	if(pPlayer->m_HasDummy == false || !CheckClientID(pPlayer->m_DummyID) || !pSelf->m_apPlayers[pPlayer->m_DummyID] || !pSelf->m_apPlayers[pPlayer->m_DummyID]->m_IsDummy)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dcm", "You don\'t have dummy.Type '/d' in chat to get it.");
		return;
	}
	int DummyID = pPlayer->m_DummyID;
	if(pPlayer->GetTeam()==TEAM_SPECTATORS || pSelf->m_apPlayers[DummyID]->GetTeam()==TEAM_SPECTATORS)
	{
		pSelf->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "dcm", "Enter the game to use this command");
		return;
	}
	if(g_Config.m_SvDummyBroadcast == 1)
		if(pSelf->m_apPlayers[DummyID]->m_DummyCopiesMove)
			pSelf->SendBroadcast("Dummy Copy Moves: Disabled", pResult->m_ClientID);
		else
			pSelf->SendBroadcast("Dummy Copy Moves: Enabled ", pResult->m_ClientID);
	pSelf->m_apPlayers[DummyID]->m_DummyCopiesMove = (pSelf->m_apPlayers[DummyID]->m_DummyCopiesMove)?false:true;
	if(!pSelf->m_apPlayers[DummyID]->m_DummyCopiesMove) //to avoid chat emote
		pSelf->m_apPlayers[DummyID]->m_PlayerFlags = 0;
}

void CGameContext::ConDisconnectRescue(IConsole::IResult *pResult, void *pUserData)
{
	CGameContext *pSelf = (CGameContext *) pUserData;
	CPlayer *pPlayer = pSelf->m_apPlayers[pResult->m_ClientID];

	int TargetID;
	if(g_Config.m_SvDummies && pSelf->m_apPlayers[pResult->m_ClientID]->m_HasDummy && str_comp_nocase(pResult->GetString(0), "d") == 0)
		TargetID = pPlayer->m_DummyID;
	else
		TargetID = pResult->m_ClientID;

	CCharacter * pChar = pSelf->GetPlayerChar(TargetID);

	if(!pChar)
		return;

	std::map<std::string, CPlayerRescueState>::iterator iterator = pSelf->m_SavedPlayers.find(pSelf->Server()->ClientName(TargetID));
	if(iterator == pSelf->m_SavedPlayers.end())
		return;

	CPlayerRescueState& state = iterator->second;
	if(state.Pos == vec2(0.f, 0.f))
		return;
	ApplyPlayerState(state, pChar, true);
	pSelf->m_SavedPlayers.erase(iterator);
}

