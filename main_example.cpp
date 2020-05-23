#include <iostream>
#include "AES128.h"

using namespace std;

int main()
{
	//Random key
	unsigned char key[] = { 0xEC, 0xFD, 0x08, 0xB0, 0x5D, 0x51, 0x3B, 0x81, 0x48, 0x69, 0x80, 0x1F, 0x23, 0xE7, 0x0B, 0xC7 };
	AES128 aes;
	aes.SetKey(key);

	//message example
	unsigned char message[] = { 0x73, 0x02, 0x21, 0x17, 0x44, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	cout << "Original message in hex:" << endl;
	for (int i = 0; i < 16; i++) {
		cout << hex << (int)message[i];
		cout << " ";
	}
	cout << endl;
	cout << endl;

	unsigned char encryptedMessage[16];

	//Encrypt the message 
	aes.Encrypt(message, encryptedMessage);

	   
	cout << "Encrypted message in hex:" << endl;
	for (int i = 0; i < 16; i++) {
		cout << hex << (int)encryptedMessage[i];
		cout << " ";
	}
	cout << endl;
	cout << endl;


	unsigned char DencryptedMessage[16]; //should be equal to original one :)

	//Decrypt the message
	aes.Decrypt(encryptedMessage, DencryptedMessage);

	cout << "Final message in hex:" << endl;
	for (int i = 0; i < 16; i++) {
		cout << hex << (int)DencryptedMessage[i];
		cout << " ";
	}
	cout << endl;
	cout << endl;

	return 0;
}

