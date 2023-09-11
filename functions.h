#include <array>
#include <iostream>
using namespace std;

// Given the integer array and its length, read data from filename given by user and
// fill the rest of the index with 0.
void fillArrayFromFile(int intArr[], int arrLength);

// Searches through the array one by one to find the value specificed by user. Default
// result is -1, meaning there are no values found within the array. Other positive numbers
// indicate the value exists in that index.
void findValueInIntArr(int intArr[], int arrLength);

// Changes value at specified index by the user, with the value given by the user. Old
// value is temporarily stored within the function to display the changes.
void changeValueAtIntArrIndex(int intArr[], int arrLength);

// adds new int at the end of the array by searching backwards to find an index with
// a nonzero value, then add a value specified by user one after the index. If a zero
// could not be found before encountering a nonzero number, throws / catches invalid_
// argument error, and prints message.
void addNewIntAtEndOfIntArray (int intArr[], int arrLength);

// Gives user two choices: replace with zero, or delete at specified index. Replacing with zero
// replaces the value at given index with zero. Deleting at index removes the value by setting
// it equal to the value one index ahead, and repeat until reaching the end of the array.
// Ends with replacing the last index of the array with 0.
void replaceWithZeroOrRemoveAtIndexOfIntArray (int intArr[], int arrLength);

// Decides if targetNum is in between the range given by other two parameters (inclusive).
// Print message if false. Will return boolean value.
bool checkIntForValidValue (int startNumInclusive, int endNumInclusive, int targetNum);

// Displays the menu for the user interface.
void displayMenu();

// Shows the user the contents of the array. Printed arrays are formatted to 
// newline every 10 indexes.
void printArray(int intArr[], int arrLength);

// Main Loop. Manages user interaction.
void mainLoop();