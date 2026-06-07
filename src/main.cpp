// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    Train train;
    train.addCar(false);
    train.addCar(true);
    train.addCar(false);
    train.addCar(false);
    train.addCar(true);
    train.addCar(false);
    int length = train.getLength();
    int ops = train.getOpCount();
    std::cout << "Train lenght: " << length << std::endl;
    std::cout << "Num of steps" << ops << std::endl;
  
    return 0;
}
