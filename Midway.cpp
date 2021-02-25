#include "Midway.h"
//#include "Simulation.h"

Calculator::Calculator() {
  rows = 1;
  columns = 1;

  myArray = new char*[rows];
  CurrentGen = new int*[rows];
  FirstGen = new int*[rows];
  SecondGen = new int*[rows];

  // dynamically allocate memory of size N for each row
  for (int i = 0; i < rows; i++) {
      myArray[i] = new char[columns];
      SecondGen[i] = new int[columns];
      FirstGen[i] = new int[columns];
      CurrentGen[i] = new int[columns];

  }

  // assign values to allocated memory
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
          myArray[i][j] = 'x';
          SecondGen[i][j] = 0;
          FirstGen[i][j] = 0;
          CurrentGen[i][j] = 0;
      }
    }
          // print the 2D array
  for (int i = 0; i < rows; i++)
  {
      for (int j = 0; j < columns; j++)
          std::cout << myArray[i][j] << " ";


      std::cout << std::endl;
  }
}

Calculator::Calculator(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;

  myArray = new char*[rows];
  SecondGen = new int*[rows];
  FirstGen = new int*[rows];
  CurrentGen = new int*[rows];


  // dynamically allocate memory of size N for each row
  for (int i = 0; i < rows; i++) {
      myArray[i] = new char[columns];
      SecondGen[i] = new int[columns];
      FirstGen[i] = new int[columns];
      CurrentGen[i] = new int[columns];
  }
          // print the 2D array

}

Calculator::~Calculator() {
  for (int i = 0; i < rows; i++) {
      delete[] myArray[i];
      delete[] FirstGen[i];
      delete[] SecondGen[i];
      delete[] CurrentGen[i];
  }

  delete[] myArray;
}

void Calculator::DetermineStartingLocations() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      randomNum = ((double) rand() / (RAND_MAX));
      if (randomNum > 0.75) {
        myArray[i][j] = 'X';
      }
      else {
        myArray[i][j] = '-';
      }
    }
  }
  for (int i = 0; i < rows; i++)
  {
      for (int j = 0; j < columns; j++) {
         cout << myArray[i][j];
      }

      cout << endl;
  }

}

void Calculator::MirrorModeCalculator() {
  CentralChunk();
  M_EdgeCalculator();
}


void Calculator::CentralChunk() {
  for (int i = 1; i < rows - 1; ++i) {
    for (int j = 1; j < columns - 1; ++j) {
      numLocations = 0;
      if (myArray[i+1][j] == 'X') {
        numLocations++;
      }
      if (myArray[i+1][j-1] == 'X') {
        numLocations++;
      }
      if (myArray[i+1][j+1] == 'X') {
        numLocations++;
      }
      if (myArray[i][j+1] == 'X') {
        numLocations++;
      }
      if (myArray[i][j-1] == 'X') {
        numLocations++;
      }
      if (myArray[i-1][j] == 'X') {
        numLocations++;
      }
      if (myArray[i-1][j-1] == 'X') {
        numLocations++;
      }
      if (myArray[i-1][j+1] == 'X') {
        numLocations++;
      }
      CurrentGen[i][j] = numLocations;
    }
  }
}

void Calculator::M_EdgeCalculator() {
  CurrentGen[0][0] = M_TopLeft();
  CurrentGen[0][columns-1] = M_TopRight();
  CurrentGen[rows-1][0] = M_BottomLeft();
  CurrentGen[rows-1][columns-1] = M_BottomRight();
  for (int j = 1; j < columns - 1; ++j) {
    CurrentGen[0][j] = M_TopRow(j);
    CurrentGen[rows-1][j] = M_BottomRow(j);
  }

  for (int i = 1; i < rows - 1; ++i) {
    CurrentGen[i][0] = M_LeftSide(i);
    CurrentGen[i][columns-1] = M_RightSide(i);
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << CurrentGen[i][j];
    }
    cout << endl;
  }
}

int Calculator::M_TopLeft() {
  int topLeftNeighbors = 0;

  if (myArray[0][0] == 'X') {
    topLeftNeighbors += 3;
  }
  if (myArray[0][1] == 'X')
  {
    topLeftNeighbors += 2;
  }
  if (myArray[1][1] == 'X')
  {
    topLeftNeighbors++;
  }
  if (myArray[1][0] == 'X')
  {
    topLeftNeighbors += 2;
  }
  return topLeftNeighbors;
}

int Calculator::M_TopRight() {
  int topRightNeighbors = 0;

  if (myArray[0][columns-1] == 'X') {
    topRightNeighbors += 3;
  }
  if (myArray[0][columns-2] == 'X')
  {
    topRightNeighbors += 2;
  }
  if (myArray[1][columns-2] == 'X')
  {
    topRightNeighbors++;
  }
  if (myArray[1][columns-1] == 'X')
  {
    topRightNeighbors += 2;
  }
  return topRightNeighbors;
}


int Calculator::M_BottomLeft() {
  int bottomLeftNeighbors = 0;

  if (myArray[rows-1][0] == 'X') {
    bottomLeftNeighbors += 3;
  }
  if (myArray[rows-2][0] == 'X')
  {
    bottomLeftNeighbors += 2;
  }
  if (myArray[rows-2][1] == 'X')
  {
    bottomLeftNeighbors++;
  }
  if (myArray[rows-1][1] == 'X')
  {
    bottomLeftNeighbors += 2;
  }
  return bottomLeftNeighbors;
}

int Calculator::M_BottomRight() {
  int bottomRightNeighbors = 0;

  if (myArray[rows-1][columns-1] == 'X') {
    bottomRightNeighbors += 3;
  }
  if (myArray[rows-1][columns-2] == 'X')
  {
    bottomRightNeighbors += 2;
  }
  if (myArray[rows-2][columns-2] == 'X')
  {
    bottomRightNeighbors++;
  }
  if (myArray[rows-2][columns-1] == 'X')
  {
    bottomRightNeighbors += 2;
  }
  return bottomRightNeighbors;
}

int Calculator::M_TopRow(int j) {
  int neighborCount = 0;

  if (myArray[0][j] == 'X') {
    neighborCount++;
  }
  if (myArray[0][j-1] == 'X') {
    neighborCount += 2;
  }
  if (myArray[1][j-1] == 'X') {
    neighborCount++;
  }
  if (myArray[1][j] == 'X') {
    neighborCount++;
  }
  if (myArray[1][j+1] == 'X') {
    neighborCount++;
  }
  if (myArray[0][j+1] == 'X') {
    neighborCount += 2;
  }
  return neighborCount;
}

int Calculator::M_BottomRow(int j) {
  int neighborCount = 0;

  if (myArray[rows-1][j] == 'X') {
    neighborCount++;
  }
  if (myArray[rows-1][j-1] == 'X') {
    neighborCount += 2;
  }
  if (myArray[rows-2][j-1] == 'X') {
    neighborCount++;
  }
  if (myArray[rows-2][j] == 'X') {
    neighborCount++;
  }
  if (myArray[rows-2][j+1] == 'X') {
    neighborCount++;
  }
  if (myArray[rows-1][j+1] == 'X') {
    neighborCount += 2;
  }
  return neighborCount;
}

int Calculator::M_LeftSide(int i) {
  int neighborCount = 0;

  if (myArray[i][0] == 'X') {
    neighborCount++;
  }
  if (myArray[i-1][0] == 'X') {
    neighborCount += 2;
  }
  if (myArray[i-1][1] == 'X') {
    neighborCount++;
  }
  if (myArray[i][1] == 'X') {
    neighborCount++;
  }
  if (myArray[i+1][1] == 'X') {
    neighborCount++;
  }
  if (myArray[i+1][0] == 'X') {
    neighborCount += 2;
  }
  return neighborCount;
}

int Calculator::M_RightSide(int i) {
  int neighborCount = 0;

  if (myArray[i][columns-1] == 'X') {
    neighborCount++;
  }
  if (myArray[i-1][columns-1] == 'X') {
    neighborCount += 2;
  }
  if (myArray[i-1][columns-2] == 'X') {
    neighborCount++;
  }
  if (myArray[i][columns-2] == 'X') {
    neighborCount++;
  }
  if (myArray[i+1][columns-2] == 'X') {
    neighborCount++;
  }
  if (myArray[i+1][columns-1] == 'X') {
    neighborCount += 2;
  }
  return neighborCount;
}
