#include <iostream>
#include <string>
using namespace std;

// just declaring functions 
bool letterQ(char l);
bool uppercaseQ(char l);
int lTOn(char l);
char nTOl(int n, bool upper);
string makeKey(string msg, string key);
string lockDiary(string text, string key);
string unlockDiary(string text, string key);

// main function 
int main() 
{
    int option;
    string message;
    string keyword;

    while (true) 
    {
        cout << "\nWelcome to the your secret diary cipher, hide your secrets or messages here!\n";
        
        cout << "\nSecret Diary Cipher\n";
        cout << "1. Lock the Diary (Encrypt)\n";
        cout << "2. Unlock the Diary (Decrypt)\n";
        cout << "3. Exit the Program\n";
        cout << "\nEnter option: ";
        cin >> option;

        if (option == 3) break;

        cout << "\nEnter your message (no spaces please!): ";
        cin >> message;

        cout << "\nEnter your password (letters only): ";
        cin >> keyword;

        if (option == 1) 
        {
        cout << "\nYour diary entry is now safely hidden and locked: " << lockDiary(message, keyword) << endl;
        } 
        else if (option == 2) 
        {
        cout << "\nHere is your diary entry unlocked: " << unlockDiary(message, keyword) << endl;
        } 
        else 
        {
            cout << "Sorry this option is invalid.\n";
        }
    }
    return 0;
}

// double check if letter inputed is a number
bool letterQ(char l) //-Letter?
{
    return (l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z');
}

// check if the letter is uppercase
bool uppercaseQ(char l) //-uppercase?
{
    return (l >= 'A' && l <= 'Z');
}

// function to convert the letters to numbers (0–25) (A = 0, Z = 25)
int lTOn(char l) // letter to num
{
    if (uppercaseQ(l)) return l - 'A';
    return l - 'a';
}

// function to convert numbers back to letters but encrypted/decrypted
char nTOl(int n, bool upper) // num to letter
{
    n = (n + 26) % 26;
    if (upper) 
    {
        return 'A' + n;
    } 
    else 
    {
        return 'a' + n;
    }
}

// function to make the keyword the same length as the message
string makeKey(string msg, string key) 
{
    string newKey = "";
    int y = 0;

    for (int i = 0; i<msg.size();i++) 
    {
        if (letterQ(msg[i])) 
        {
            char k = key[y % key.size()];
            if (k >= 'a' && k <= 'z') 
            {
                // converting to uppercase
                k = k - 'a' + 'A';  
            }
            newKey += k;
            y++;
        } 
        else 
        {
            newKey += '#';
        }
    }
    return newKey;
}

// function to lock the diary (encrypt)
string lockDiary(string text, string key) 
{
    string k = makeKey(text,key);
    string out = "";

    for (int i = 0; i<text.size();i++) 
    {
        if (!letterQ(text[i])) 
        {
            out += text[i];
        } 
        else 
        {
            int o = lTOn(text[i]);      // o = original letter number
            int kln = lTOn(k[i]);         // kln = key letter number
            int c = (o + kln) % 26;       // c = cipher (encrypted) letter number
            out += nTOl(c, uppercaseQ(text[i]));
        }
    }
    return out;
}

// function to unlock the diary (decrypt)
string unlockDiary(string text, string key) 
{
    string k = makeKey(text, key);
    string out = "";

    for (int i = 0; i < text.size(); i++) 
    {
        if (!letterQ(text[i])) 
        {
            out += text[i];
        }
        else 
        {
        int c = lTOn(text[i]);         // c = cipher (encrypted) letter number
        int kln = lTOn(k[i]);          // kln = key letter number
        int o = (c - kln + 26) % 26;   // o = original letter number
        out += nTOl(o, uppercaseQ(text[i]));
        }
    }
    return out;
}
