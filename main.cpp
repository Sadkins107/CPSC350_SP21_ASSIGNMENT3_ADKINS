#include "Midway.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    srand(time(0));
    int rows, columns;
    cin >> rows;
    cin >> columns;
    Calculator *arrayCreator = new Calculator(rows, columns);
    arrayCreator->DetermineStartingLocations();
    arrayCreator->DoughnutModeCalculator();
    return 0;
}
