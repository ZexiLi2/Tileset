// Tailset.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TileMap.h"
#include <vector>
#include <fstream> 
#include <sstream>

using namespace std;
using namespace sf;
/* number reference
0 stone
1 grass
2 water
3 grass + lilly of the valley
4 grassy grass
5 vertical road
6 horizontal road
7 -10 turning road
11 mountain house
*/


int main()
{
    //
    srand(time(NULL));
    cout << "A quin nivell vols anar? (1, 2, 3, 4)" << endl;
    int mapSelector;
    cin >> mapSelector;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 320), "Tilemap");
    int level[160];
    // define the level with an array of tile indices
    /*const int level[] =
    {
    0, 0, 0, 0, 0, 0, 0, 1, 4, 1, 3, 4, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 4, 7, 6, 6, 6, 8, 0, 0, 0,
    0, 1, 7, 6, 6, 6, 6, 6, 10, 1, 1, 3, 5, 0, 0, 0,
    0, 1, 5, 4, 3, 1, 4, 1, 1, 1, 1, 1, 5, 1, 0, 0,
    1, 1, 5, 1, 1, 1, 2, 2, 2, 1, 4, 1, 5, 4, 11, 0,
    4, 1, 5, 1, 2, 2, 12, 2, 4, 1, 1, 4, 9, 6, 6, 6,
    3, 7, 10, 4, 2, 2, 2, 2, 3, 1, 1, 1, 4, 1, 1, 0,
    1, 5, 3, 1, 1, 12, 2, 2, 2, 2, 1, 1, 4, 1, 0, 0,
    1, 5, 1, 3, 1, 4, 2, 2, 2, 12, 2, 4, 1, 4, 0, 0,
    6, 10, 1, 0, 0, 1, 1, 1, 2, 2, 1, 4, 0, 0, 0, 0,
    };*/

    // Random map selector
    // selecciona un nombre al atzar entre 1, 2, 3 i 4 (hi ha 4 tilemaps)
    //int randomMapSelector = rand() % 4 + 1;   
    ifstream file;
    int i = 0;
    
    switch (mapSelector)
    {
    case 1: //si resultat random és igual a 1, obre mapa 1
        file.open("level.txt");
        while (file >> level[i])
        {
            i++;
        }
        break;
    case 2: //si resultat random és igual a 2, obre mapa 2
        file.open("level2.txt");
        while (file >> level[i])
        {
            i++;
        }
        break;
    case 3: //si resultat random és igual a 3, obre mapa 3
        file.open("level3.txt");
        while (file >> level[i])
        {
            i++;
        }
        break;
    case 4: //si resultat random és igual a 4, obre mapa 4
        file.open("level4.txt");
        while (file >> level[i])
        {
            i++;
        }
        break;

    }
    
    // Create the tilemap from the level definition
    TileMap map;
    if (!map.load("graphics/tailset-tailmap2.png", sf::Vector2u(32, 32), level, 16, 10))
        return -1;

    // Save the level to a .txt file
    /*ofstream outFile("level2.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < sizeof(level) / sizeof(level[0]); ++i)
        {
            outFile << level[i] << (i % 16 == 15 ? "\n" : " "); // New line every 16 elements
        }
        outFile.close();
    }
    else
    {
        cerr << "Unable to open file for writing." << endl;
    }
    */
    // Run the main loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Draw the map
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
