#include "functions.h"
#include <array>
#include <fstream>
#include <iostream>
using namespace std;

void fillArrayFromFile(int intArr[], int arrLength) {
  ifstream inFS;
  int newNum, iterator = 0;
  string filename;
  cout << "Target file name >>> ";
  cin >> filename;

  inFS.open(filename);
  while (inFS.is_open() && !inFS.eof() && iterator < arrLength) {
    inFS >> newNum;
    intArr[iterator] = newNum;
    iterator++;
    newNum = 0;
  }
  inFS.close();
  for (; iterator < arrLength; iterator++) {
    intArr[iterator] = 0;
  }
}

void findValueInIntArr(int intArr[], int arrLength) {
  int targetNum;
  cout << "Value to search? >>> ";
  cin >> targetNum;
  int result = -1;
  for (int i = 0; i < arrLength - 1; i++) {
    if (intArr[i] == targetNum)
      result = i;
  }
  if (result != -1)
    cout << "Found " << targetNum << " at index " << result << "." << endl;
  else
    cout << targetNum << " not found in array." << endl;
}

void changeValueAtIntArrIndex(int intArr[], int arrLength) {
  try {
    int targetNum, targetIndex;
    cout << "Index? >>> ";
    cin >> targetIndex;
    cout << "New value? >>> ";
    cin >> targetNum;
    if (targetIndex >= arrLength)
      throw invalid_argument("Index out of range.");
    cout << "Old Value: " << intArr[targetIndex] << endl;
    intArr[targetIndex] = targetNum;
    cout << "New Value: " << intArr[targetIndex] << endl;
  } catch (invalid_argument x) {
    cout << x.what() << endl;
  }
}

void addNewIntAtEndOfIntArray(int intArr[], int arrLength) {
  int newVal;
  try {
    for (int i = 0; i < arrLength; i++) {
      if (intArr[i] == 0) {
        cout << "New value? >>> ";
        cin >> newVal;
        intArr[i] = newVal;
        return;
      }
    }
    throw invalid_argument("Array is full.");
  } catch (invalid_argument x) {
    cout << x.what() << endl;
  }
}

void replaceWithZeroOrRemoveAtIndexOfIntArray(int intArr[], int arrLength) {
  int choice = -1;
  cout << "0. Replace a value at index with 0." << endl;
  cout << "1. Remove a value at index." << endl;
  cout << "Choice >>> ";
  cin >> choice;
  while (!checkIntForValidValue(0, 1, choice)) {
    cout << "Choice >>> ";
    cin >> choice;
  }
  int index;
  cout << "Index? >>> ";
  cin >> index;
  while (!checkIntForValidValue(0, arrLength - 1, index)) {
    cout << "Index? >>> ";
    cin >> index;
  }
  intArr[index] = 0;
  if (choice == 0) {
    cout << "Swapped value at index " << index << " with 0." << endl;
  } else {
    int currIndex = index;
    while (currIndex + 1 < arrLength) {
      intArr[currIndex] = intArr[currIndex + 1];
      currIndex++;
    }
    intArr[arrLength - 1] = 0;
  }
}

bool checkIntForValidValue(int startNumInclusive, int endNumInclusive, int targetNum) {
  if (startNumInclusive <= targetNum && targetNum <= endNumInclusive) {
    return true;
  }
  cout << "Invalid input. Try again." << endl;
  return false;
}

void displayMenu() {
  cout << "\n======[Array Editor]======" << endl;
  cout << "1. Check if a certain integer exists in the array." << endl;
  cout << "2. Modify a value at an index." << endl;
  cout << "3. Add a new value at the end of the array." << endl;
  cout << "4. Remove value at index (0 or delete)." << endl;
  cout << "5. Display the array." << endl;
  cout << "6. End program." << endl;
}

void printArray(int intArr[], int arrLength) {
  cout << "{" << intArr[0];
  for (int i = 1; i < arrLength; i++) {
    cout << ", " << intArr[i];
  }
  cout << "}" << endl;
}

void mainLoop() {
  int arrLength = 50;
  int *intArr = new int[arrLength];
  fillArrayFromFile(intArr, arrLength);

  int choice = 0;
  while (choice != 6) {
    displayMenu();
    cout << "Choice >>> ";
    cin >> choice;
    while (!checkIntForValidValue(1, 6, choice)) {
      cout << "Choice >>> ";
      cin >> choice;
    }
    if (choice == 1) {
      findValueInIntArr(intArr, arrLength);
    } else if (choice == 2) {
      changeValueAtIntArrIndex(intArr, arrLength);
    } else if (choice == 3) {
      addNewIntAtEndOfIntArray(intArr, arrLength);
    } else if (choice == 4) {
      replaceWithZeroOrRemoveAtIndexOfIntArray(intArr, arrLength);
    } else if (choice == 5) {
      printArray(intArr, arrLength);
    } else if (choice == 6) {
      cout << "Terminated." << endl;
    }
  }
}