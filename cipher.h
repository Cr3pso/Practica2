/*
  * Student name 1: Luis Enrique
  * Student name 2: Mario De Juan
  * Work: Practice 2
  * Creation date: 11/06/2023
  * Document objective: Implement and define encryption function headers
  */

#ifndef PRACTICA2_CIPHER_H
#define PRACTICA2_CIPHER_H

/*
  * This function converts the original message to encrypted (cesar) depending on the offset that was chosen
  * Parameters:
  * - text: Text entered by the user to encrypt with a maximum of 100 letters
  * - offset: Number of times scrolled forward to encrypt
  * Print: The function prints the message ciphered
  * Return: The function returns an exit status code or an error status code
  */

char cesarCipher(char text[], int offset);

/*
  * This function converts the encrypted message (cesar) to its original form
  * Parameters:
  * - text: The text encrypted by the previous function
  * - offset: Number of times scrolled back to decrypt
 * Print: The function prints the message ciphered
 * Return: The function returns an exit status code or an error status code
 */

char cesarDecipher(char text[], int offset);

/*
  * This function converts the original message to encrypted depending on the key entered (vigenere)
  * Parameters:
  * - text: The text that the user wants to encrypt with a maximum of 100 letters
  * - key: The key used to encrypt the text with a maximum of 50 letters
 * Print: The function prints the message ciphered
 * Return: The function returns an exit status code or an error status code
 */

char vigenereCipher(char text[], char key[]);

/*
  * This function converts the encrypted message (vigenere) to its original form using the same key that was used to encrypt it
  * Parameters:
  * - text: The text encrypted by the previous function
  * - key: The key used to cipher the text
 * Print: The function prints the original message deciphered
 * Return: The function returns an exit status code or an error status code
 */

char vigenereDecipher(char cipherText[], char key[]);


#endif //PRACTICA2_CIPHER_H