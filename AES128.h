#pragma once

/*
C++ class for 128-bit AES encryption/decryption.

deulis@gmail.com

Original source from: https://github.com/ceceww/aes
I just rewrite and modify it to put it in a class style
*/


class AES128
{
public:
	//The key is a 128 bits (16 bytes) length
	void SetKey(unsigned char inputKey[16]);

	//WARNING: The message and encryptedMessage pointer must have the same capacity and it size MUST be multiples of 16.
	//Maybe you need to pad zeros to the messagem to achieve a 16 multiple value of length.
	//The block parameters is the number of 16 bytes blocks.
	void Encrypt(unsigned char* message, unsigned char* encryptedMessage, int blocks = 1);
	
	//WARNING: The message and encryptedMessage pointer must have the same capacity and it size MUST be multiples of 16.
	//The block parameters is the number of 16 bytes blocks.
	void Decrypt(unsigned char* encryptedMessage, unsigned char* message, int blocks = 1);

private:
	
	void EncryptBlock(unsigned char* message, unsigned char* encryptedMessage);
	void DecryptBlock(unsigned char* encryptedMessage, unsigned char* decryptedMessage);
	void KeyExpansionCore(unsigned char* in, unsigned char i);	
	void AddRoundKey(unsigned char* state, unsigned char* roundKey);
	void SubBytesEncryption(unsigned char* state);
	void ShiftRowsEncryption(unsigned char* state);
	void MixColumns(unsigned char* state);
	void RoundEncrytion(unsigned char* state, unsigned char* key);
	void FinalRound(unsigned char* state, unsigned char* key);


	void SubRoundKey(unsigned char* state, unsigned char* roundKey);
	void InverseMixColumns(unsigned char* state);
	void ShiftRowsDescrytion(unsigned char* state);
	void SubBytesDescrytion(unsigned char* state);
	void RoundDescription(unsigned char* state, unsigned char* key);
	void InitialRound(unsigned char* state, unsigned char* key);	   	 
	
	unsigned char expandedKeys[176];

	// Encryption: Forward Rijndael S-box 
	static const unsigned char s[];

	// Encryption: Multiply by 2 for MixColumns
	static const unsigned char mul2[];

	// Encryption: Multiply by 3 for MixColumns
	static const unsigned char mul3[];

	// Used in KeyExpansion
	static const unsigned char rcon[];

	// Decryption: Inverse Rijndael S-box
	static const unsigned char inv_s[];

	// Decryption: Multiply by 9 for InverseMixColumns
	static const unsigned char mul9[];

	// Decryption: Multiply by 11 for InverseMixColumns
	static const unsigned char mul11[];

	// Decryption: Multiply by 13 for InverseMixColumns
	static const unsigned char mul13[];

	// Decryption: Multiply by 14 for InverseMixColumns
	static const unsigned char mul14[];
};

