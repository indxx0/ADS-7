// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (!first) return;
    Car* current = first->next;
    while (current != first) {
        Car* nextCar = current->next;
        delete current;
        current = nextCar;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    first->light = true;
    countOp = 0;

    int k = 1;
    Car* current = first->next;
    countOp++;

    while (true) {
        if (current->light) {
            current->light = false;
            for (int i = 0; i < k; ++i) {
                current = current->prev;
                countOp++;
            }

            if (!current->light) {
                current->light = true;
                return k;
            }

            for (int i = 0; i < k; ++i) {
                current = current->next;
                countOp++;
            }
        }
        current = current->next;
        k++;
        countOp++;
    }
}

int Train::getOpCount() {
    return countOp;
}
