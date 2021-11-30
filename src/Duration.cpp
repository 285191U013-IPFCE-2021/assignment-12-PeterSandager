#include "Duration.hpp"
#include <assert.h>

// Public constructor method setting time = 0, alarm = -1 and 'alarmHasBeenSet' = false.
Duration::Duration()
{
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false; // Alarm has not been set at first
};

// Second public constructor method taking the integer argument t and setting time = t.
Duration::Duration(int t)
{
    assert(t >= 0);
    time = t;
    alarm = -1;
    alarmHasBeenSet = false;
}

int Duration::getDuration()
{
    return time;
}

// Tick increments time by 1
bool Duration::tick()
{
    time++;
    return checkAndUpdateAlarm();
}

// Second tick incrementing time by the value dt
bool Duration::tick(int dt)
{
    assert(dt > 0);
    time = time + dt;

    return checkAndUpdateAlarm();
}

void Duration::setAlarm(int t)
{
    // No assert for test purposes. Although the provided CMake file gives me errors, so I can't build as of right now.
    // Only set alarm to a time value in the future
    if (t > time)
    {
        alarm = t;
        alarmHasBeenSet = true;
    }

    return;
}

bool Duration::checkAndUpdateAlarm()
{
    // alarm goes off
    if (time >= alarm)
    {
        // alarm is reset to default value
        alarm = -1;

        // alarm has been reset, alarmHasBeenSet-attribute must also reset
        alarmHasBeenSet = false;
        return true;
    }
    // alarm does not go off
    return false;
}

bool Duration::HasAlarmBeenSet()
{
    return alarmHasBeenSet;
}
