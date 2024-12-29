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


// Main function
int main()
{
    cout << "Welcome!" << endl;

    char runWhile = 'A';
    string uInput = "";

    // Loop to run until they quit:
    do {
        cout << "Would you like to (E)ncrypt, (D)ecrypt, or (Q)uit? ";
        getline(cin, uInput); // use getline() instaed of cin

        runWhile = uInput[0];
        string theText = "";

        // Encrypt
        /* Consider moving encryption/decryption code to separate functions */
        if ((runWhile == 'e') || (runWhile == 'E')) {
            cout << "What would you like to encipher? ";
            getline(cin, theText);


            // Second do while runs until they pick an encryption or quit.
            char quitInner ='*';
            do {
                cout << "What form of cipher would you like to encrypt with? (C)aesar, (A)ffine, or (R)ail Fence? ";
                string uInput;
                getline(cin, uInput);

                // Call Ceaser encryption
                if ((uInput[0] == 'C') || (uInput[0] == 'c')) {
                    cout << "What is the key? ";
                    /* get key as int
                        // make sure to error check */
                    int key;

                    // Call encryption func:
                    eCaesar(theText, key);

                    // set runWhile to break:
                    quitInner = 'Q';
                }

                // Call Affine or Rail Fence encryption
                else if ((uInput[0] == 'R') || (uInput[0] == 'r') ||
                    (uInput[0] == 'F') || (uInput[0] == 'f')) {
                
                    cout << "What is the a key? ";
                    // get keys as ints
                        // make sure to error check
                    int aKey;

                    cout << "What is the b key? ";
                    /* get key as int
                        // make sure to error check */
                    int bKey;
                    /* get key as int
                        // make sure to error check */

                    // Call appropriate function:
                    // 'A' or 'a' for Affine, and 'R', 'r', 'F', and 'f' for Rail Fence
                    if ((uInput[0] == 'A') || (uInput[0] == 'a')) {
                        eAffine(theText, aKey, bKey);
                    }
                    else {
                        eRail(theText, aKey, bKey);
                    }

                    // set quitInner to break:
                    quitInner = 'Q';
                } // end else if that runs Rail

                // Call Affine encryption
                else if ((uInput[0] == 'A') || (uInput[0] == 'a')) {
                    cout << "What is the a key? ";
                    int aKey = 0;
                    string keyInput;

                    do {
                        getline(cin, keyInput);
                        while (!tryInt(keyInput, aKey))
                        {
                            std::cout << "Bad entry; please enter an integer for the key.";
                            cout << "What is the a key? ";
                            getline(cin, keyInput);
                        }

                        if (((aKey % 2) != 0) && ((aKey % 13) != 0)) {
                            std::cout << "Bad entry; please enter an integer coprime with 26 (i.e. not divisible by 2 or 13).";
                        }

                    } while (((aKey % 2) != 0) && ((aKey % 13) != 0));

                    cout << "What is the b key? ";
                    int bKey;
                    getline(cin, keyInput);
                    while (!tryInt(keyInput, bKey))
                    {
                        std::cout << "Bad entry; please enter an integer for the key.";
                        cout << "What is the b key? ";
                        getline(cin, keyInput);
                    }

                    eAffine(uInput, aKey, bKey);

                    quitInner = 'Q';
                }

                // Another quit dialogue
                else if ((uInput[0] == 'Q') || (uInput[0] == 'q')) {
                    quitInner = 'Q';
                    runWhile == 'Q';
                    cout << "Quitting...\nHave a nice day!" << endl;
                }

                // If they don't quit or input a cipher, try again
                else {
                    cout << "Invalid input. Please enter 'C', 'A', 'R', or 'Q'." << endl;
                }

            // Check this and all otehr while conditions
            } while ((runWhile != 'Q') && (runWhile != 'q') && (quitInner != 'Q'));

        } // End encryption

        // Decrypt
        else if ((runWhile == 'd') || (runWhile == 'D')) {
            cout << "What would you like to encipher? ";
            /* Get text with getline() and store in theText */


            // Second do while runs until they pick an encryption or quit.
            char quitInner = 'B';
            do {
                cout << "What form of cipher would you like to encrypt with? (C)aesar, (A)ffine, or (R)ail Fence? ";
                /* get input with getline() */

                // Call Ceaser encryption
                if ((uInput[0] == 'C') || (uInput[0] == 'c')) {
                    cout << "What is the key? ";
                    /* get key as int
                        // make sure to error check */
                    int key;

                    // Call encryption func:
                    eCaesar(theText, key);

                    // set quitInner to break:
                    quitInner = 'Q';
                }

                // Call Rail Fence encryption
                else if ((uInput[0] == 'R') || (uInput[0] == 'r') ||
                    (uInput[0] == 'F') || (uInput[0] == 'f')) {

                    cout << "What is the a key? ";
                    // get keys as ints
                        // make sure to error check
                        // if uInput == 'A' || uInput == 'a', check that it's not coprime
                    int aKey;

                    cout << "What is the b key? ";
                    /* get key as int
                        // make sure to error check */
                    int bKey;
                    /* get key as int
                        // make sure to error check */

                    eRail(theText, aKey, bKey);

                    quitInner = 'Q';
                } // end else if that runs ail

                // Call Affine decryption
                else if ((uInput[0] == 'A') || (uInput[0] == 'a')) {
                    cout << "What is the a key? ";
                    int aKey = 0;
                    string keyInput;

                    do {
                        getline(cin, keyInput);
                        while (!tryInt(keyInput, aKey))
                        {
                            std::cout << "Bad entry; please enter an integer for the key.";
                            cout << "What is the a key? ";
                            getline(cin, keyInput);
                        }

                        if (((aKey % 2) != 0) && ((aKey % 13) != 0)) {
                            std::cout << "Bad entry; please enter an integer coprime with 26 (i.e. not divisible by 2 or 13).";
                        }

                    } while (((aKey % 2) != 0) && ((aKey % 13) != 0));

                    cout << "What is the b key? ";
                    int bKey;
                    getline(cin, keyInput);
                    while (!tryInt(keyInput, bKey))
                    {
                        std::cout << "Bad entry; please enter an integer for the key.";
                        cout << "What is the b key? ";
                        getline(cin, keyInput);
                    }

                    dAffine(theText, aKey, bKey);

                    quitInner = 'Q';
                }

                // Another quit dialogue
                else if ((uInput[0] == 'Q') || (uInput[0] == 'q')) {
                    quitInner = 'Q';
                    runWhile == 'Q';
                    cout << "Quitting...\nHave a nice day!" << endl;
                }

                // If they don't quit or input a cipher, try again
                else {
                    cout << "Invalid input. Please enter 'C', 'A', 'R', or 'Q'." << endl;
                }

            } while ((runWhile != 'Q') && (runWhile != 'q') && (quitInner != 'Q'));

        } // End decryption
        

        // Quit 
        else if ((runWhile == 'q') || (runWhile == 'Q')) {
            cout << "Quitting...\nHave a nice day!" << endl;
        }

        // Wrong input
        else {
            cout << "Invalid input. Please enter 'E', 'D', or 'Q'." << endl;
        }

        // Loop condition
    }  while ((runWhile != 'Q') && (runWhile != 'q'));

}


// Funciton Definitions:
// Could make these pointers so we aren't copying massive strings
// 
// Encrypt Caesar
void eCaesar(string& plaintext, const int& key) {
    cout << "eCeaser" << endl;
}

// Decrypt Caesar:
void dCaesar(string& ciphertext, const int& key) {
    cout << "dCeaser" << endl;
}

// Encrypt affine
// For this one, you may want to get integers assoicated w/ each letter
    // and operate on those
    // before adding them to 'A' or 'a'
    // So you don't have problems with character arithmetic overflow
void eAffine(string& ciphertext, const int& aKey, const int& bKey) {
    cout << "eAffine" << endl;
}

// Decrypt affine
void dAffine(string& ciphertext, const int& aKey, const int& bKey) {
    cout << "dAffine" << endl;
}

// Encrypt rail
void eRail(string& ciphertext, const int& aKey, const int& bKey) {
    cout << "eRail" << endl;
}

// Decrypt rail
void dRail(string& ciphertext, const int& aKey, const int& bKey) {
    cout << "dRail" << endl;
}

// Check that input is an int
bool tryInt(const string& input, int& key) {
    try {
        key = stoi(input);
    }
    catch (invalid_argument) {
        return false;
    }
    return true;
}
