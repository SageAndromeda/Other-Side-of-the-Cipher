/*
* Sage Hardiman
* 9/12/2024
* One-Time Pad encryption and Decryption
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::endl; using std::cin;
using std::string; using std::vector;

vector<int> getKey();
string getPlaintext(const int&);
string getCiphertext(const int&);
string edcrypt(const string&, const vector<int>&, const char&);

int main()
{
    cout << "Welcome to the one time pad encryptor." <<
        endl << "Would you like to Encrypt (E) or Decrypt (D)? ";
    string uInput;
    do {
        getline(cin, uInput);

        if ((uInput[0] != 'e') && (uInput[0] != 'd') &&
            (uInput[0] != 'D') && (uInput[0] != 'E')) {
            cout << "Invalid input. Please enter \"E\" to encrypt, or \"D\" to decrypt. ";
        }

    } while ((uInput[0] != 'e') && (uInput[0] != 'd') &&
        (uInput[0] != 'D') && (uInput[0] != 'E'));

    // Make sure you remove these excess comments afterwards.
    vector<int> thePad = getKey();
    string result;
    if ((uInput[0] == 'e') || (uInput[0] == 'E'))
        result = getPlaintext(thePad.size());
    else
        result = getCiphertext(thePad.size());
    result = edcrypt(result, thePad, uInput[0]);

    // Print result
    if ((uInput[0] == 'e') || (uInput[0] == 'E'))
        cout << "Here is your encrypted message: " << result;
    else
        cout << "Here is your decrypted message: " << result;
}


// Get the key phrase from the user.
// Convert it to a vector of numbers.
vector<int> getKey() {
    string strKey = "";
    bool alphaFlag = false;

    do {
        cout << "What is the key phrase for the one time pad? ";
        getline(cin, strKey);

        for (int i = 0; i < strKey.length(); ++i) {
            if (isalpha(strKey[i])) {
                alphaFlag = true;
                i = strKey.length() + 1;
            }
        }
        if (alphaFlag == false) {
            cout << "Invalid key. Please enter a string with at least one letter." << endl;
        }
    } while (alphaFlag == false);

    vector<int> keyVect;
    for (int i = 0; i < strKey.length(); ++i) {
        if ((isalpha(strKey[i])) && (isupper(strKey[i])))
            keyVect.push_back(int(strKey[i] - 'A'));
        else if ((isalpha(strKey[i])) && (islower(strKey[i])))
            keyVect.push_back(int(strKey[i] - 'a'));
    }

    return keyVect;
}


// Get the plaintext string from the user.
// It must have equal to or fewer letters than the key.
// Non-letters are not counted
string getPlaintext(const int& keyLen) {
    string plaintext;
    bool lenFlag = false;
    bool alphaFlag = false;

    do {
        cout << "What plaintext would you like to encrypt? ";
        getline(cin, plaintext);
        alphaFlag = false;
        lenFlag = false;

        // Check length 
        if (plaintext.length() > keyLen) {
            int numLetters = 0;
            for (int i = 0; i < plaintext.length(); ++i) {
                if (isalpha(plaintext[i])) {
                    ++numLetters;
                    alphaFlag = true;
                }

                if (numLetters > keyLen) {
                    i = plaintext.length() + 1;
                    cout << "The plaintext is too long. It must be " << keyLen << 
                        " or fewer letters long." << endl;
                    lenFlag = false;
                }
                else
                    lenFlag = true;
            }
        }
        else
            lenFlag = true;

        // Check for letters
        if (alphaFlag == false) {
            for (int i = 0; i < plaintext.length(); ++i) {
                if (isalpha(plaintext[i])) {
                    alphaFlag = true;
                    i = plaintext.length() + 1;
                }
            }
            if (alphaFlag == false) {
                cout << "The plaintext must include at least one letter." << endl;
            }
        }

    } while (lenFlag == false || alphaFlag == false);

    return plaintext;
}


// Get the ciphertext string from the user.
// It must have equal to or fewer letters than the key.
// Non-letters are not counted
string getCiphertext(const int& keyLen) {
    string ciphertext;
    bool lenFlag = false;
    bool alphaFlag = false;

    do {
        cout << "What ciphertext would you like to decrypt? ";
        getline(cin, ciphertext);
        alphaFlag = false;
        lenFlag = false;

        // Check length 
        if (ciphertext.length() > keyLen) {
            int numLetters = 0;
            for (int i = 0; i < ciphertext.length(); ++i) {
                if (isalpha(ciphertext[i])) {
                    ++numLetters;
                    alphaFlag = true;
                }

                if (numLetters > keyLen) {
                    i = ciphertext.length() + 1;
                    cout << "The ciphertext is too long. It must be " << keyLen <<
                        " or fewer letters long." << endl;
                    lenFlag = false;
                }
                else
                    lenFlag = true;
            }
        }
        else
            lenFlag = true;

        // Check for letters
        if (alphaFlag == false) {
            for (int i = 0; i < ciphertext.length(); ++i) {
                if (isalpha(ciphertext[i])) {
                    alphaFlag = true;
                    i = ciphertext.length() + 1;
                }
            }
            if (alphaFlag == false) {
                cout << "The ciphertext must include at least one letter." << endl;
            }
        }

    } while (lenFlag == false || alphaFlag == false);

    return ciphertext;
}


// Encrypt the message and return the result.
// Everything that is not a letter gets removed.
string edcrypt(const string& text, const vector<int>& thePad, const char& eORd) {
    // Convert the text to numbers
    vector<int> textVals;
    for (int i = 0; i < text.length(); ++i) {
        if ((isalpha(text[i])) && (isupper(text[i])))
            textVals.push_back(int(text[i] - 'A'));
        else if ((isalpha(text[i])) && (islower(text[i])))
            textVals.push_back(int(text[i] - 'a'));
    }
    
    string result = "";
    // Encrypt
    if ((eORd == 'e') || (eORd == 'E')) {
        for (int i = 0; i < textVals.size(); ++i)
            result += ('A' + ((textVals[i] + thePad[i]) % 26));
    }
    // Decrypt
    else {
        for (int i = 0; i < textVals.size(); ++i)
        {
            int changeVal = (textVals[i] - thePad[i]) % 26;
            if (changeVal < 0)
                changeVal = 26 - (changeVal * (-1));
            result += ('A' + changeVal);
        }
    }
    
    return result;
}

