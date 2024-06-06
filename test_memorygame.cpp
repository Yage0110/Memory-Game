// test_memorygame.cpp
#include <iostream>
#include <cassert>
#include "MemoryGame.hpp"

using namespace std;

void test_default_constructor() {
    MemoryGame game;
    assert(game.numSlots == 8);
    assert(game.numPairs == 3);
    cout << "Default constructor test passed!" << endl;
}

void test_param_constructor() {
    MemoryGame game(2, 10);
    assert(game.numSlots == 10);
    assert(game.numPairs == 2);
    cout << "Parameterized constructor test passed!" << endl;
}

void test_word_constructor() {
    string words[] = {"apple", "banana", "cherry"};
    MemoryGame game(words, 3, 8);
    assert(game.numSlots == 8);
    assert(game.numPairs == 3);
    cout << "Word constructor test passed!" << endl;
}

void test_display() {
    MemoryGame game;
    game.randomize();
    game.display();
    cout << "Display test passed!" << endl;
}

int main() {
    test_default_constructor();
    test_param_constructor();
    test_word_constructor();
    test_display();

    cout << "All tests passed!" << endl;

    return 0;
}
