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
    void DoughnutModeCalculator();
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
    void D_EdgeCalculator();
    int D_TopLeft();
    int D_TopRight();
    int D_BottomLeft();
    int D_BottomRight();
    int D_TopRow(int j);
    int D_BottomRow(int j);
    int D_LeftSide(int i);
    int D_RightSide(int i);

};

#endif
