# Memory Game Project

## Overview

This project implements a memory game where the player needs to find matching pairs of hidden cards. Three constructors are provided to initialize the game with different parameters.

## Files Included

- **MemoryGame.hpp:** Header file defining the MemoryGame class.
- **MemoryGame.cpp:** Source file containing the implementation of the MemoryGame class constructors, destructor, and methods.
- **MemoryGameClient.cpp:** Client program to test the MemoryGame class functionalities.
- **test_memorygame.cpp:** Test file to validate the functionality of the game.

## MemoryGame Class

### Constructors

#### Default Constructor

```cpp
MemoryGame();
//Initializes the game with 3 pairs of random integers in the range [0, 999] placed in 8 blocks.
```
#### Parameterized Constructor

```cpp
Copy code
MemoryGame(int numPairs, int numSlots);
//Initializes the game with numPairs pairs of random integers in the range [0, 999] placed in numSlots blocks.
```
#### Word Constructor

```cpp
Copy code
MemoryGame(string* words, int size, int numSlots);
//Initializes the game with size pairs of words from the words array, placed in numSlots blocks.
```
### Methods
```cpp
void play();

//Starts the game and manages player input.

void display() const;

//Displays the current state of the game board.

void randomize();

//Randomizes the layout of elements in the values array.

int input() const;

//Takes user input for selecting a card.

~MemoryGame();

//Destructor to deallocate memory used by values and bShown arrays.
```
### Client Program (MemoryGameClient.cpp)

```cpp
// MemoryGameClient.cpp
#include <iostream>
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
```
### Testing

The `test_memorygame.cpp` file includes test cases to validate the functionality of the game. It tests the default constructor, parameterized constructor, word constructor, and the display method.

### Installation

Clone the repository:
```bash
git clone https://github.com/Yage0110/Memory-Game.git
```
#### Navigate to the project directory:
```bash
cd MemoryGame
```
#### Compile and run:
```bash
g++ MemoryGame.cpp MemoryGameClient.cpp -o MemoryGame
./MemoryGame
```
#### Compilation Instructions

To compile and run the Memory Game project, follow these steps:

```bash
g++ MemoryGame.cpp MemoryGameClient.cpp -o MemoryGame
./MemoryGame
```
#### Author

Agyei Bacchus

#### Acknowledgments

Professor Tong Yi
