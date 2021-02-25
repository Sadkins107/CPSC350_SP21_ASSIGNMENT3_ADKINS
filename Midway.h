#ifndef ARRAY_CREATOR_H
#define ARRAY_CREATOR_H

#include <iostream>
//#include "Simulation.h"

using namespace std;

class Calculator {
  public:
    Calculator();
    Calculator(int rows, int columns);
    ~Calculator();
    void DetermineStartingLocations();
    void MirrorModeCalculator();
    char** myArray;
    int** CurrentGen;
    int** SecondGen;
    int** FirstGen;

  private:
    int rows;
    int columns;
    int numLocations = 0;
    double randomNum;
    void CentralChunk();
    void M_EdgeCalculator();
    int M_TopLeft();
    int M_TopRight();
    int M_BottomLeft();
    int M_BottomRight();
    int M_TopRow(int j);
    int M_BottomRow(int j);
    int M_LeftSide(int i);
    int M_RightSide(int i);

};

#endif
