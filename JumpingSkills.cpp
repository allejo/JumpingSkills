/*
JumpingSkills
    Copyright (C) 2015 Vladimir "allejo" Jimenez

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "bzfsAPI.h"
#include "plugin_utils.h"

class JumpingSkills : public bz_Plugin, public bz_CustomSlashCommandHandler
{
public:
    virtual const char* Name () {return "Jumping Skills";}
    virtual void Init (const char* config);
    virtual void Event (bz_EventData *eventData);
    virtual void Cleanup (void);

    virtual bool SlashCommand (int playerID, bz_ApiString, bz_ApiString, bz_APIStringList*);
};

BZ_PLUGIN(JumpingSkills)

void JumpingSkills::Init (const char* commandLine)
{
    // Register our events with Register()
    Register(bz_eGameEndEvent);

    // Register our custom slash commands
    bz_registerCustomSlashCommand("d", this);
}

void JumpingSkills::Cleanup (void)
{
    Flush(); // Clean up all the events

    // Clean up our custom slash commands
    bz_removeCustomSlashCommand("d");
}

void JumpingSkills::Event (bz_EventData *eventData)
{
    switch (eventData->eventType)
    {
        case bz_eGameEndEvent: // This event is called each time a game ends
        {
            bz_shutdown();
        }
        break;

        default: break;
    }
}


bool JumpingSkills::SlashCommand(int playerID, bz_ApiString command, bz_ApiString /*message*/, bz_APIStringList *params)
{
    if (command == "d")
    {
        bz_killPlayer(playerID, false);

        return true;
    }
}
