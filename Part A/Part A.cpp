// Nicholas Walling
// CIS 1202 101
// December 8, 2024
// Exceptions, Templates, & STL Part A
// A program that uses try/catch blocks utilizing the std::exception library to call a function
// with different start and offset values.

#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception for invalid character
class invalidCharacterException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Invalid starting character.";
    }
};

// Custom exception for inlaid range (out of bounds)
class invalidRangeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Invalid range for the character.";
    }
};

// Character function
char character(char start, int offset)
{
    // Check if start character is a valid letter
    if (!isalpha(start))
    {
        throw invalidCharacterException();
    }

    // Check if the result of the offset leads to a valid character
    char result = (start + offset);

    // If it's out of bounds for alphabet letters, throw exception
    if ((isupper(start) && (result < 'A' || result > 'Z')) ||
        (islower(start) && (result < 'a' || result > 'z')))
    {
        throw invalidRangeException();
    }

    // Return the resulting character
    return result;
}

int main()
{
    // Test case 1
    try
    {
        cout << "character('a', 1) = ";
        cout << character('a', 1) << endl; // should retrun 'b'
        cout << "character('a', -1) = ";
        cout << character('a', -1) << endl; // should throw exception
    }
    catch (const exception& e)
    {
        cout << e.what() << endl << endl;
    }

    // Test case 2
    try
    {
        cout << "character('Z', -1) = ";
        cout << character('Z', -1) << endl; // should return 'Y'
        cout << "character('?', 5) = ";
        cout << character('?', 5) << endl; // should throw exception
    }
    catch (const exception& e)
    {
        cout << e.what() << endl << endl;
    }

    // Test case 3
    try
    {
        cout << "character('A', 32) = ";
        cout << character('A', 32) << endl; // should throw exception
    }
    catch (const exception& e)
    {
        cout << e.what() << endl << endl;
    }

    return 0;
}