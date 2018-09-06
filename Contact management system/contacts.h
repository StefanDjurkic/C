#ifndef CONTACTS_H_
#define CONTACTS_H_
/* -------------------------------------------
Name: Stefan Djurkic
Email: stefandjurkic@gmail.com
Website: stefandjurkic.com
Date: 12/20/2017
File: contacts.h
Purpose: This file contains the contact structs and function prototypes for various return functions
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
// Place your code here...
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char city[41];
	char postalCode[12];
};

// Structure type Numbers declaration
// Place your code here...
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// Place your code here...
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// Get and store from standard input the values for Name
void getName(struct Name*);

// Get and store from standard input the values for Address
void getAddress(struct Address*);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers*);

// Get and store from standard input the values for a Contact
void getContact(struct Contact *);

// Get and replace a contact
void getReplaceContact(struct Contact[]);


#endif
