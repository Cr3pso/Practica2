//to make the implementation of functions
#include <stdio.h>
#include "cipher.h" //for old compilers
#include <string.h>

/*
  * Student name 1: Mario De Juan
  * Student name 2: Luis Enrique
  * Work: Práctica 2
  * Creation date: 11/06/2023
  * Objective of the document: Implement the functions of the cipher.h library
 */

char cesarCipher(char text[], int offset){ //char type function, recieving text[] and offset variables
    int length = strlen(text); // Set a length to the text

    for (int i = 0; i < length; i++){ //"i" gets the value from 0 to the number of characters in the text, and for each value of "i" the following is executed
        if (text[i] >= 'A' && text[i] <= 'Z'){ //if the character is in the cappital letters alphabet then
            text[i] = (text[i] - 'A' + offset + 26) % 26 + 'A'; //changes the letter to the one ciphered making sure that doesn't pass from the 26 letters from the alphabet
        }
        else if (text[i] >= 'a' && text[i] <= 'z'){ //if not, then if the character is in the lower case alphabet then
            text[i] = (text[i] - 'a' + offset + 26) % 26 + 'a'; //changes the letter to the one ciphered making sure that doesn't pass from the 26 letters from the alphabet
        }
        else if (text[i] != ' ' && (text[i] >= 0 && text[i] <= 9)){ //if not, then if the character is a space or a number then
            printf("[!] Invalid character detected");
            return -1; // returns error status code
        }
    }
    printf("-> %s", text); //prints the text ciphered
    return 0; //returns exit status code
}

char cesarDecipher(char text[], int offset){ //char type function, recieving cipherText[] and offset variables
    int length = strlen(text);

    for (int i = 0; i < length; i++){ //"i" gets the value from 0 to the number of characters in the text, and for each value of "i" the following is executed
        if (text[i] >= 'A' && text[i] <= 'Z'){ //if the character is in the cappital letters alphabet then
            text[i] = (text[i] - 'A' - offset + 26) % 26 + 'A'; //changes the letter ciphered to the original letter making sure that doesn't pass from the 26 letters from the alphabet
        }
        else if (text[i] >= 'a' && text[i] <= 'z'){ //if not, then if the character is in the lower case alphabet then
            text[i] = (text[i] - 'a' - offset + 26) % 26 + 'a'; //changes the letter ciphered to the original letter making sure that doesn't pass from the 26 letters from the alphabet
        }
        else if (text[i] != ' ' && (text[i] >= 0 && text[i] <= 9)){ //if not, then if the character is a space or a number then
            printf("[!] Invalid character detected");
            return -1; // returns error status code
        }
    }

    printf("-> %s", text); //prints the text deciphered
    return 0; //returns exit status code
}

char vigenereCipher(char text[], char key[]){ //char type function, recieving text[] and key[] variables
    int textLength = strlen(text) -1; // Set a length to the text
    int keyLength = strlen(key) -1; // Set a length to the key

    for (int i = 0, j = 0; i < textLength; i++) { // the variable "i" to read the spaces of the text and the variable "j" to read the spaces of the key. For each value of "i", the following is executed, where after it increments its value
        if(text[i] >= 'A' && text[i] <= 'Z'){ //if the character is in the capital letters alphabet then
            text[i] = (text[i] - 'A' + key[j % keyLength] + 26 - 'a') % 26 + 'A'; //applies the key to the letter and removes the letter "A" so that it starts from 0 and adds 26 which are the spaces from "A" to "Z" and then makes the module of 26 so that it does not go out of that range and "A" that was removed previously is added to put the equivalent encrypted letter
            j++; // To advance to the next character of the key, add 1 to the variable "j"
        } else if (text[i] >= 'a' && text[i] <= 'z'){ // if not, then if character is a lower case letter
            text[i] = (text[i] - 'a' + key[j % keyLength] + 26 - 'a') % 26 + 'a'; //applies the key to the letter and removes the letter "a" so that it starts from 0 and adds 26 which are the spaces from "A" to "Z" and then makes the module of 26 so that it does not go out of that range and "A" that was removed previously is added to put the equivalent encrypted letter
            j++; // To advance to the next character of the key, add 1 to the variable "j"
        }else if(text[i] == ' '){ // Does not encrypt spaces if it is
        } else if (text[i] >= '0' && text[i] <= '9'){ // Does not encrypt the numbers if it is
        } else{ //if any of the conditions before is true then
            return -1; // returns error status code
        }
    }
    printf("\n-> %s", text); //prints the text ciphered
    return 0; //returns exit status code
}

char vigenereDecipher(char cipherText[], char key[]){ //char type function, recieving cipherText[] and offset variables
    int textLength = strlen(cipherText) -1; // Set a length to the ciphered text
    int keyLength = strlen(key) -1; // Set a length to the key

    for (int i = 0, j = 0; i < textLength; i++) { // the variable "i" to read the spaces of the text and the variable "j" to read the spaces of the key. For each value of "i", the following is executed, where after it increments its value
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z'){ //if the character is in the cappital letters alphabet then
            cipherText[i] = (cipherText[i] - 'A' - key[j % keyLength] + 26 + 'a') % 26 + 'A'; //takes away the key of the letter and removes the letter "A" so that it starts from 0 and adds 26 which are the spaces from "A" to "Z" and then makes the module of 26 so that it does not go out of that range and "A" that was removed previously is added to put the equivalent encrypted letter
            j++; // To advance to the next character of the key, add 1 to the variable "j"
        } else if (cipherText[i] >= 'a' && cipherText[i] <= 'z'){ //if not, then if the character is in the lower case alphabet then
            cipherText[i] = (cipherText[i] - 'a' - key[j % keyLength] + 26 + 'a') % 26 + 'a'; //takes away the key of the letter and removes the letter "a" so that it starts from 0 and adds 26 which are the spaces from "A" to "Z" and then makes the module of 26 so that it does not go out of that range and "A" that was removed previously is added to put the equivalent encrypted letter
            j++; // To advance to the next character of the key, add 1 to the variable "j"
        }else if(cipherText[i] == ' '){ // Does not encrypt spaces if it is
        } else if (cipherText[i] >= '0' && cipherText[i] <= '9'){ // Does not encrypt the numbers if it is
        } else{ //if any of the conditions before is true then
            return -1; // returns error status code
        }
    }
    printf("\n-> %s", cipherText); //prints the text deciphered
    return 0; //returns exit status code
}