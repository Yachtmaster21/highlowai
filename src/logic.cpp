#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int findMiddle(int upper, int lower) {
    float halfNumber{(float(upper) + float(lower)) / 2};    //find the exact middle number
    srand(time(0));     //seed the random number generator
    int upOrDown{rand() % 50};
    if (upOrDown >= 25) {   //round the number up or down
        return int(std::ceil(halfNumber));
    } else {
        return int(std::floor(halfNumber));
    }
}

std::string askNumber(int asked, int older) {
    if (asked != older) {
    std::string letter;
    std::cout << "Is your number " << asked << "?\n";
    std::cout << "(H)igher, (L)ower, (C)orrect, (Q)uit (answer in a capital letter): ";
    std::cin >> letter;
    std::cout << "\n";
    return letter;
    } else {
        return "try";   //if the number has already been asked try again
    }
}

int playGame() {
    std::string inputLetter;
    bool numberFound{false};
    int oldNumber{0};
    int middleNumber;
    int outputNumber{0};
    int upperRange{100};
    int lowerRange{0};
    while (numberFound == false) {
        middleNumber = findMiddle(upperRange, lowerRange);
        inputLetter = askNumber(middleNumber, oldNumber);
        if (inputLetter == "H") {
            lowerRange = middleNumber;  //set the lower range if the number is higher
            outputNumber++;     //increment the turn counter
        } else if (inputLetter == "L") {
            upperRange = middleNumber;  //set the upper range if the number is lower
            outputNumber++;
        } else if (inputLetter == "C") {
            numberFound = true; //break out of the loop
            std::cout << "The number is " << middleNumber << '\n';
        } else if (inputLetter == "Q") {
            return 100;         //tell the main function the user exited
        } else if (inputLetter == "try") {
            if (outputNumber > 10) {
                return 200;     //tell the main function the user has cheated
            }
        } else {
            return 150;         //tell the main function the user has mistyped
        }
    }
    return outputNumber;    //tell the main function how many turns it took
}