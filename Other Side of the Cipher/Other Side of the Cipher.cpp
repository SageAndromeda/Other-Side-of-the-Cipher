// Other Side of the Cipher
// Sage Hardiman
// 6-9-2024

/*
* This is the accompanying code to the poem "On or to the Other Side of the Cipher."
* It can encipher and decipher caesar, affine, and rail-fence ciphers.
*/


// Includes
#include <iostream>
#include <string>
#include <stdexcept>
using std::cout; using std::cin; using std::endl; using std::string;
using std::stoi; using std::invalid_argument;

// Function heads
void eCaesar(string&, const int&);
void dCaesar(string&, const int&);
void eAffine(string&, const int&, const int&);
void dAffine(string&, const int&, const int&);
void eRail(string&, const int&, const int&);
void dRail(string&, const int&, const int&);
bool tryInt(const string&, int&);

// 

// Main function
int main()
{
    cout << "Welcome!" << endl;

    // Loop to run until they quit:
    do {
        cout << "Hello, world!" << endl;
    }  while (true);

                        }



