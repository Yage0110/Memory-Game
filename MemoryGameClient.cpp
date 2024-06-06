//File name: /Users/laptopuser/Downloads/memoryGame/MemoryGameClient.cpp
//name: Tong Yi
//email: ty680@hunter.cuny.edu
#include <iostream>
#include <string>
#include "MemoryGame.hpp"
using namespace std;

int main() {
    MemoryGame game;
    for (int i = 0; i < game.numSlots; i++)
        cout << "\"" << game.values[i] << "\"" << " ";
    cout << endl;

    MemoryGame game2(2, 10);
    for (int i = 0; i < game2.numSlots; i++)
        cout << "\"" << game2.values[i] << "\"" << " ";
    cout << endl;

    return 0;
}