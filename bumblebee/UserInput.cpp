#include "UserInput.h"

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// Ignore all characters in stdin up to and including
void ignoreLine() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }

/**
 * @brief Check if extraction failed and clear stdin if so
 *
 * @return wether the extraction failed
 */
bool clearFailedExtraction() {
    if (!cin) {
        cin.clear();
        return true;
    }

    return false;
}

/**
 * @brief Check whether stdin has unextracted input
 *
 * @return whether stdin has unextracted input
 */
bool hasUnextractedInput() { return !cin.eof() && cin.peek() != '\n'; }

unsigned int getPositiveInteger() {
    int number = 0;
    unsigned int positiveInteger = 0;
    while (true) {
        cout << "Enter how many prime number you would like me to find: ";
        cin >> number;
        // clearFailedExtraction() will return true if std::cin.fail() (or
        // simply !std::cin) i.e. if the extraction failed
        if (clearFailedExtraction() || hasUnextractedInput()) {
            ignoreLine();
            cout << "Invalid input. Please try again" << endl;
            continue;
        }

        if (number <= 0) {
            cout << "Number must be positive!" << endl;
            continue;
        }

        positiveInteger = static_cast<unsigned int>(number);
        return positiveInteger;
    }
}