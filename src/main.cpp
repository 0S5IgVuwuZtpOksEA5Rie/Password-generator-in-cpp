#include "../src/main.h"

using namespace std;

string get_random_character(bool includeLetters)
{
    // create return variable
    string character;
    int randomNumber;

    // list of available characters
    string availableAlphanumericCharacters;
    availableAlphanumericCharacters = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_\\=+`~!@#$%^&*()[]{}|;:'\",.<>/?";

    // list of numbers
    string numericCharacters;
    numericCharacters = "1234567890";

    // select only numbers or every characters
    string usingCharacters;
    if (includeLetters == true)
    {
        usingCharacters = availableAlphanumericCharacters;
    }
    else
    {
        usingCharacters = numericCharacters;
    }

    // get random character and return it
    int lengthOfAvailableCharacters;
    lengthOfAvailableCharacters = usingCharacters.length();

    randomNumber = rand() % lengthOfAvailableCharacters;

    character = usingCharacters[randomNumber];

    return character;
}

// FIXME: This does not seem to be working properly
bool get_bool_from_yes_no(string output)
{
    char inputString;
    bool inputBool;

    inputBool = false;

    // make sure the user is understood
    bool understood;
    understood = false;
    // while does not understand
    while (understood == false)
    {
        // print to the console the question
        cout << output;
        cin >> inputString;

        // if legible put as inputBool
        if (inputString == 'y')
        {
            inputBool = true;
            understood = true;
        }
        else if (inputString == 'n')
        {
            inputBool = false;
            understood = true;
        }
        else
        {
            understood = false;
        }
    }

    return inputBool;
}

int main()
{
    // integer example so that it can be compared with inputs
    int integerExample;
    integerExample = 1;

    bool run;
    run = true;
    while (run == true)
    {
        // set seed to time to be more random
        srand((unsigned int)time(NULL));

        // create variable to differentiate between pin or password
        bool includeLetters;

        // is it a pin code
        includeLetters = get_bool_from_yes_no("include letters (y/n): ");

        // FIXME: From here...

        // length of passwords
        int lengthOfPasswords;

        // make sure the correct data type is inserted
        bool intEnteredLengthOfPasswords;
        intEnteredLengthOfPasswords = false;

        // while it is not
        while (intEnteredLengthOfPasswords == false)
        {
            cout << "length of password: ";
            cin >> lengthOfPasswords;
            if (bool(typeid(lengthOfPasswords).name()) == bool(typeid(integerExample).name()))
            {
                intEnteredLengthOfPasswords = true;
                cout << "lengthOfPasswords: " << bool(intEnteredLengthOfPasswords) << endl;
            }
            else
            {
                intEnteredLengthOfPasswords = false;
                cout << "lengthOfPasswords: " << bool(intEnteredLengthOfPasswords) << endl;
            }
        }

        // how many passwords
        int numberOfPasswords;

        // make sure the correct data type is inserted
        bool intEnteredNumberOfPasswords;
        intEnteredNumberOfPasswords = false;

        // while it is not
        while (intEnteredNumberOfPasswords == false)
        {
            cout << "number of passwords: ";
            cin >> numberOfPasswords;
            if (typeid(numberOfPasswords).name() == typeid(integerExample).name())
            {
                intEnteredNumberOfPasswords = true;
            }
            else
            {
                intEnteredNumberOfPasswords = false;
            }
        }

        // FIXME: ...To here

        cout << endl;

        // generate passwords
        // passwords
        for (int i = 0; i < numberOfPasswords; i += 1)
        {
            string password;
            // characters
            for (int j = 0; j < lengthOfPasswords; j += 1)
            {
                password += get_random_character(includeLetters);
            }
            cout << password << endl;
        }

        cout << endl;

        // close or rerun
        bool close;
        close = get_bool_from_yes_no("close(y/n): ");
        cout << "\n";

        if (close == true)
        {
            run = false;
        }
    }
    return 0;
}
