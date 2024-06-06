//Jay Bacchus
// Project 2A - MemoryGame.cpp
//Professor Tong Yi
//Implement constructors and destructor.

#include "MemoryGame.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
// Default constructor
MemoryGame::MemoryGame() {
   numPairs = 3;
   numSlots = 8;
   values = new string[numSlots];
   bShown = new bool[numSlots];

    for (int i = 0; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }
    //Three random ints
    int random1 = rand() % 1000;
    int random2 = rand() % 1000;
    int random3 = rand() % 1000;

    //  first int to the first two slots of values
    values[0] = to_string(random1);
    values[1] = to_string(random1);

    //  second int to the next two slots of values
    values[2] = to_string(random2);
    values[3] = to_string(random2);

    //  third int to the subsequent two slots of values
    values[4] = to_string(random3);
    values[5] = to_string(random3);
}
// Non-default constructor with numPairs and numSlots
MemoryGame::MemoryGame(int numPairs, int numSlots){
    if (numPairs <= 0 || numSlots <= 0 || numSlots < 2 * numPairs) {
        this->numPairs = 3;
        this->numSlots = 8;
    } else {
        this->numPairs = numPairs;
        this->numSlots = numSlots;
    }
    
    values = new string[numSlots];
    bShown = new bool[numSlots];
    for (int i = 0; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }

    // Generate numPairs random integers in [0, 999]
    for (int i = 0; i < numPairs; i++) {
        int random = rand() % 1000;

        // make numPairs random integers in [0, 999] and place each int in pairs in values

        values[2 * i] = to_string(random);
        values[2 * i + 1] = to_string(random);
    }
}
// Non-default constructor with array of words, size, and numSlots
MemoryGame::MemoryGame(string* words, int size, int numSlots){
    if (size <= 0 || numSlots <= 0 || numSlots < 2 * size) {
        // Adjust size and numSlots if they are invalid
        this->numPairs = size;
        this->numSlots = 2 * size;
    } else {
        this->numPairs = size;
        this->numSlots = numSlots;
    }
    
    // Allocate memory for values and bShown arrays
    values = new string[numSlots];
    bShown = new bool[numSlots];

 // Initialize each element of values array to empty string
    // and each element of bShown array to false
    for (int i = 0; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }

    // Place each word in pairs in values
    for (int i = 0; i < size; i++) {
        values[2 * i] = words[i];
        values[2 * i + 1] = words[i];
    }
}

//Destructor
MemoryGame::~MemoryGame() {
    // Deallocate memory for values and bShown arrays
    delete[] values;
    values = nullptr;

    delete[] bShown;
    bShown = nullptr;
}
void MemoryGame::randomize() {
    int size = numSlots;
    while(size>1){
        int randIndex = rand() % size--;
        swap(values[randIndex], values[size]);
    }

}


void MemoryGame::display() const { 
    cout << " "; //the first space
    for (int i = 0; i < numSlots; i++) {
    cout << setw(3) << i; //display index in 3 letter-width
    cout << setw(3) << " "; //display three spaces after index
    }
    cout << endl;
    cout << "+"; //the first +
//draw -----+ for (size) many times 
    for (int i = 0; i < numSlots; i++){
        cout << "-----+";
    }
    cout << endl;

    cout<<"|";
    for(int i =0; i< numSlots; i++){
        if (bShown[i]){ //index i is in 0 <= i < numSlots
            cout << setw(5) << values[i]; //display ith item in array values
    }else {
        cout << setw(5)<<""; //display empty string
    }
    cout<<"|";
    }
    cout<<endl;

    cout << "+"; //the first +
//draw -----+ for (size) many times 
    for (int i = 0; i < numSlots; i++){
        cout << "-----+";
    }
    cout << endl;
}

int MemoryGame::input() const{
    int newIndex;
    bool validIndex = false;
    int last_index_of_data_member_values = numSlots - 1;
    while(!validIndex){
        cout<<"Enter a unflipped card in [0, "<<last_index_of_data_member_values<<" ]: ";
        cin>>newIndex;
        cout<<newIndex<<endl;
    if(newIndex<0 || newIndex>last_index_of_data_member_values){
        cout<<"input is not in [0, "<< last_index_of_data_member_values<<"]. Re-enter: "<<endl;
    } else if(bShown[newIndex]){
        cout<<"The card is flipped already. Re-enter:";
    }else{
        validIndex = true; 
    }
}
    return newIndex;
}

void MemoryGame::play(){
    randomize();
    display();
    int pairsFound = 0;
    int round = 0;
    int first = 0;
    while(pairsFound < numPairs){
        round ++;
        cout<<"Round "<<round<<":"<<endl;
        int xIndex = input();

        if (round % 2 == 1 ){
            bShown[xIndex]=true;
            first = xIndex;
        }else{
            if (values[xIndex]==values[first]&&values[xIndex]!=""){
                bShown[xIndex]=true;
                pairsFound++;
            }else{
                bShown[first] = false;
            }
        }
    display();
    }
    cout<<"Congratulations! Found out all pairs in "<< round <<" rounds";
}