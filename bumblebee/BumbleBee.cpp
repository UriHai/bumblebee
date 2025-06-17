#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::sqrt;
using std::streamsize;

/**
 * @brief Check wether a number is prime
 *
 * @param num	[IN]	The number to check
 * @return true if num is prime, false otherwise
 */
bool isPrime(unsigned int num) {
    unsigned int divisor = 2;
    if (num <= 1) {
        return false;
    }

    // Iterate over all possible divisors (from 2 to half of the original
    // number). If there is a divisor such that num % divisor equals 0 - return
    // false. If no such divisor was found, return true.
    for (divisor = 2; divisor < num / 2 + 1; divisor++) {
        if (num % divisor == 0) {
            return false;
        }
    }
    return true;
}

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

/**
 * @brief Input a positive integer
 *
 * @return the integer
 */
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

/**
 * @brief fill array with prime numbers
 * 
 * @param primeNumbers                  [OUT]       The array
 * @param numberOfPrimesToFind          [IN]        The number of primes to find 
 */
void fillPrimes(unsigned int* const primeNumbers, unsigned int numberOfPrimesToFind) {
    unsigned int numberOfPrimesFound = 0;
    unsigned int current = 2;
    bool isCurrentNumberPrime = false;

    while (numberOfPrimesFound < numberOfPrimesToFind) {
        isCurrentNumberPrime = isPrime(currentNumber);
        while (isCurrentNumberPrime) }
}

/**
 * @brief Print primes array
 * 
 * @param primeNumbers                  [IN]        The array
 * @param length                        [IN]        The array's length
 */
void printPrimesArray(const unsigned int* const primeNumbers, unsigned int length) {
    unsigned int i = 0;

    cout << "Here are the first " << length << "prime numbers" << endl;
    for (i = 0; i < length - 1; i++) {
        cout << primeNumbers[i] << ", ";
    }
    cout << primeNumbers[length - 1] << endl;
}

int main() {
    int numberOfPrimesToFind = getPositiveInteger();
    unsigned int* primeNumbers = new unsigned int[numberOfPrimesToFind];
    fillPrimes(primeNumbers, numberOfPrimesToFind);
    printPrimesArray(primeNumbers, numberOfPrimesToFind);
    delete primeNumbers;

    return 0;
}