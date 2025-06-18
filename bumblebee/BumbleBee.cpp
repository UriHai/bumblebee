#include <iostream>
#include <cmath>

#include "UserInput.h"

const unsigned int FIRST_PRIME = 2;

using std::cout;
using std::endl;

/**
 * @brief Check wether a number is prime
 *
 * @param num	[IN]	The number to check
 * @return true if num is prime, false otherwise
 */
bool isPrime(unsigned int num) {
    unsigned int divisor = FIRST_PRIME;
    if (num <= 1) {
        return false;
    }

    // Iterate over all possible divisors (from 2 to half of the original
    // number). If there is a divisor such that num % divisor equals 0 - return
    // false. If no such divisor was found, return true.
    for (divisor = FIRST_PRIME; divisor < num / 2 + 1; divisor++) {
        if (num % divisor == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief fill array with prime numbers
 * 
 * @param primeNumbers                  [OUT]       The array
 * @param numberOfPrimesToFind          [IN]        The number of primes to find i.e the array's length
 */
void fillPrimes(unsigned int* const primeNumbers, unsigned int numberOfPrimesToFind) {
    unsigned int numberOfPrimesFound = 0;
    unsigned int currentNumber = FIRST_PRIME;
    bool isCurrentNumberPrime = true;

    while (numberOfPrimesFound < numberOfPrimesToFind) {
        isCurrentNumberPrime = isPrime(currentNumber);
        if (isCurrentNumberPrime) {
            primeNumbers[numberOfPrimesFound] = currentNumber;
            numberOfPrimesFound++;
        }
        currentNumber++;
    }
}

/**
 * @brief Print primes array
 * 
 * @param primeNumbers                  [IN]        The array
 * @param length                        [IN]        The array's length
 */
void printPrimesArray(const unsigned int* const primeNumbers, unsigned int length) {
    unsigned int i = 0;

    cout << "Here are the first " << length << " prime numbers" << endl;
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
    delete[] primeNumbers;

    return 0;
}