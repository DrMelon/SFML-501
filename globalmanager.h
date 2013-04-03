#ifndef GLOBALMANAGER_H_INCLUDED
#define GLOBALMANAGER_H_INCLUDED

// The Global Manager is a singleton - only one instance exists, but it is common to the entire program.

#include <SFML/Graphics.hpp>


class GlobalManager
{
public:
    static GlobalManager& Instance()
    {
        static GlobalManager singleton;
        return singleton;
    }
    // Global Variables
    sf::RenderWindow* window;

private:
    GlobalManager() {};
    GlobalManager(const GlobalManager&);             // Prevent Copying;
    GlobalManager& operator=(const GlobalManager&); // Prevent Assignment

};

// Initializing Singleton
static GlobalManager* g_GlobalManager = &GlobalManager::Instance();

#endif // GLOBALMANAGER_H_INCLUDED
