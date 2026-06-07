// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    std::ofstream outFile("result/results.csv");
    outFile << "Length,AllOff,AllOn,Random\n";

    const int MAX_LENGTH = 100;

    for (int n = 2; n <= MAX_LENGTH; ++n) {
        Train train;
        for (int i = 0; i < n; ++i) {
            train.addCar(false);
        }
        train.resetState(false, false);
        train.getLength();
        int opsAllOff = train.getOpCount();
        train.resetState(true, false);
        train.getLength();
        int opsAllOn = train.getOpCount();
        int opsRandomTotal = 0;
        int randomRuns = 10;
        for(int i = 0; i < randomRuns; ++i) {
            train.resetState(false, true);
            train.getLength();
            opsRandomTotal += train.getOpCount();
        }
        int opsRandom = opsRandomTotal / randomRuns;
        outFile << n << "," << opsAllOff << "," << opsAllOn << "," << opsRandom << "\n";
    }
    outFile.close();
    return 0;
}
