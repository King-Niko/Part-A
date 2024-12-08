// Nicholas Walling
// CIS 1202 101
// December 8, 2024
// Exceptions, Templates, & STL Part A
// A program that uses try/catch blocks using the stdexception library to call a function
// with different starts and offsets.

#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception for invalid character
class InvalidCharacterException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Invalid starting character.";
    }
};

// Custom exception for inlaid range (out of bounds)
class InvalidRangeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Invalid range for the character.";
    }
};

char character(char start, int offset)
{

}

int main()
{
    // Driver ... test ...

    return 0;
}