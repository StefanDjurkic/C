/* -------------------------------------------
Name: Stefan Djurkic
Email: stefandjurkic@gmail.com
Website: stefandjurkic.com
Date: 12/20/2017
File: contactsHelpers.h
Purpose: This file contains the prototypes for functions that manipulate i/o in relation to the contact struct
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#include "contacts.h"

// clearKeyboard: Clears the standard input buffer
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int, int);

// yes:
int yes(void);

// menu:
int menu(void);

// ContactManagerSystem:
void ContactManagerSystem(void);

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char[11]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact[], int, const char[]);

// displayContactHeader
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int);

// displayContact:
void displayContact(const struct Contact*);

// displayContacts:
void displayContacts(const struct Contact[], int);

// searchContacts:
void searchContacts(const struct Contact[], int);

// addContact:
void addContact(struct Contact[], int);

// updateContact:
void updateContact(struct Contact[], int);

// deleteContact:
void deleteContact(struct Contact[], int);

// sortContacts:
void sortContacts(struct Contact[], int);

