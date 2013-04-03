// 501 Game using SFML for Graphical Display

// SFML stands for "Simple and Fast Multimedia Layer" and is a wrapper for OpenGL which focuses on user-friendliness and usability.
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include "statestack.h"

// State Function Prototypes
void Menu();
void Game();

// State Function Helpers
void Menu_Input();
void Menu_Draw(std::vector<sf::Sprite> drawList);

// Globals

// The draw vectors contain everything that needs to be drawn per state.
std::vector<sf::Sprite> drawList_Menu;
sf::RenderWindow* window;

int main()
{
    // Set up SFML Window
    window = new sf::RenderWindow(sf::VideoMode(1024,512), "501 Darts Game!");
    window->setFramerateLimit(60); // 60 FPS

    // Push initial states onto stack.
    State st;
    st.StatePointer = Menu;
    g_StateStack->states.push(st);

    // Load Dartboard Image -- DEBUG
    sf::Texture DartboardTexture;
    DartboardTexture.loadFromFile("gfx/board.bmp");
    sf::Sprite background;
    background.setTexture(DartboardTexture);

    // Put Dartboard image on draw lists.
    drawList_Menu.push_back(background);

    // Main Loop -- While the stack isn't empty and we haven't closed the window...
    while (window->isOpen())
    {
        // Close the window if the stack is empty.
        if(g_StateStack->states.empty())
        {
            window->close();
        }

        // Run the current state.
        g_StateStack->states.top().StatePointer();
    }

    return 0;
}

// States
void Menu()
{
    Menu_Input();
    Menu_Draw(drawList_Menu);
}




void Menu_Input()
{
    // Handle Input on Main Menu
    sf::Event event;
    while (window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            // Pop all states!
            for(int i = 0; i < g_StateStack->states.size(); i++)
            {
                g_StateStack->states.pop();
            }
        }
    }
}

void Menu_Draw(std::vector<sf::Sprite> drawList)
{
        // Clear Draw Buffer
        window->clear();
        // -- Any Drawable Items go Here
        for(int i = 0; i < drawList.size(); i++)
        {
            window->draw(drawList[i]);
        }
        window->display();
}
