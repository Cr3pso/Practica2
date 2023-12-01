//Import libraries
#include <stdio.h>
#include "cipher.h"
#include <string.h>

int main() { //definition of the main function
    // Definition of variables:
    char text[100]; //text variable with 100 of space
    char cipherText[100]; //cipherText variable with 100 of space
    int offset;
    int option;
    char key[50]; //key variable with 50 of space

    //Tell the user to pick an option
    printf("[1] Cesar cipher\n[2] Cesar decipher\n[3] Vigenere cipher\n[4] Vigenere decipher\n");
    printf("Choose an option: ");
    scanf("%d", &option); //save the mode in the option variable

    if (option == 1) { //if option 1 mode is picked
        printf("Write the text which you want to cipher: ");
        fflush(stdin); //to empty the exit buffer
        gets(text); //save the input of the user in the "text" variable
        printf("\nWrite the number of offsets: ");
        scanf("%d", &offset); //save the number of offsets typed by the user in the "offset" variable
        cesarCipher(text, offset); //call to the function "cesarCipher" so its executed and we pass it the "text" and "offset" variables
        return 0; //return exit status code
    }

    else if (option == 2) { //if option 2 mode is picked
        printf("Write the ciphertext: ");
        fflush(stdin); //to empty the exit buffer
        gets(cipherText); //save the input of the user in the "cipherText" variable
        printf("\nWrite the number of offsets: ");
        scanf("%d", &offset); //save the number of offsets typed by the user in the "offset" variable
        cesarDecipher(cipherText, offset); //call to the function "cesarDecipher" so its executed and we pass it the "cipherText" and "offset" variables
        return 0; //return exit status code
    }

    else if (option == 3) { //if option 3 mode is picked
        printf("Write the text which you want to cipher: ");
        fflush(stdin); //to empty the exit buffer
        gets(text); //save the input of the user in the "text" variable
        printf("Write the key to cipher the text: ");
        fflush(stdin); //to empty the exit buffer
        gets(key); //save the input of the user in the "key" variable
        vigenereCipher(text, key); //call to the function "vigenereCipher" so its executed and we pass it the "text" and "key" variables
    }
    else if (option == 4) { //if option 4 mode is picked
        printf("Write the ciphertext: ");
        fflush(stdin); //to empty the exit buffer
        gets(cipherText); //save the input of the user in the "cipherText" variable
        printf("Write the key to decipher the text: ");
        fflush(stdin); //to empty the exit buffer
        gets(key); //save the input of the user in the "key" variable
        vigenereDecipher(cipherText, key); //call to the function "vigenereDecipher" so its executed and we pass it the "cipherText" and "key" variables
    }
    else { //if a invalid option was chosen
        printf("[!] Invalid option");
    }

    return 0;
}