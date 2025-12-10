# CIS-7-Final-Project
Discrete Structures Final

Project General Description

Secret Diary Cipher is a very simple program that lets a user lock (encrypt) or unlock (decrypt) their diary entries or short secret message using a password. It uses the Vigenère-style cipher to shift letters in the alphabet. And turns normal text into a coded version that can only be read with the correct password. 
The goal of the project is to make the encryprted messages easy for anyone to understand, even if they don’t understand how the cipher works. Instead of manually doing the shifting/converting letters to numbers or the math by hand, the program does it for you automatically. Overall, the purpose of the program is to give its users a simple way to protect/disguise their messages while also applying the concepts learned in discrete structures.

Programming Approaches

The program is made up of a lot of short helper functions that make the main code easier to understand. There are functions to check if a character is a letter, check if it’s uppercase, convert letters into numbers, convert numbers back into letters, and one that can create a repeated keyword that matches the length of the message given. There are a good amount of loops as well and they are used to go through each character, and the conditional statements to decide how each character should be handled. As I said in my documentation, the modular arithmetic is used to shift letters forward or backwards when encrypting/decrypting. The program uses cin for input and a very straightforward menu with three options so the user can choose whether they want to lock or unlock a diary entry/message or exit the program. It also keeps an uppercase letter uppercase after encryption or decryption if the user inputs one.

Authors
Simrah Kashif

Team Name
Team SK

Date Published
December 10th 2025

How to Use the Program 

1. Run the C++ file

2. Open the program in the terminal

3. You are shown the menu

4. Choose one of the three menu options:

1 - Lock (Encrypt) your diary entry

2 - Unlock (Decrypt) your diary entry

3 - Exit the program

5. The user enters a message (no spaces)

6. Enter your password (no #).

7. The program will show your encryptd/decrypted result.
