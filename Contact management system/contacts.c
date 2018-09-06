/* -------------------------------------------
Name: Stefan Djurkic
Email: stefandjurkic@gmail.com
Website: stefandjurkic.com
Date: 12/20/2017
File: contacts.c
Purpose: This file contains the implementations of various return/get functions
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name *nm)
{
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]%*c", (*nm).firstName);

	//  MIDDLE
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) 
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %s", (*nm).middleInitial);
		clearKeyboard();
	}
	// LASTNAME
	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]%*c", (*nm).lastName);
}

// getAddress:
void getAddress(struct Address *ad)
{
	int inside;
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	inside = getIntInRange(0, 9999999);
	(*ad).streetNumber = inside;
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]%*c", (*ad).street);

	// APARTMENT
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1) 
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &(*ad).apartmentNumber);
		clearKeyboard();
	}
	//  POSTAL CODE
	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]%*c", (*ad).postalCode);

	// CITY
	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]%*c", (*ad).city);
}


// getNumbers:
void getNumbers(struct Numbers *nu)
{
	// Contact Numbers Input:
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone((*nu).cell);

	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes() == 1) 
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone((*nu).home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");

	if (yes() == 1) 
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone((*nu).business);
	}
}

/*getContact & replace functions*/ 
void getContact(struct Contact *stored)
{
	getName(&(*stored).name);

	getAddress(&(*stored).address);

	getNumbers(&(*stored).numbers);
}

// new function to meet assignment printf and confirmation requirements
// the old getContact is still used as well.
void getReplaceContact(struct Contact stored[])
{
	printf("Do you want to update the name? (y or n): ");
	if (yes() == 1)
	{
		getName(&(stored)->name);
    }
	printf("Do you want to update the address? (y or n): ");
	if (yes() == 1) 
	{	
		getAddress(&(stored)->address);
	}
	printf("Do you want to update the numbers? (y or n): ");
	if (yes() == 1) 
	{
        getNumbers(&(stored)->numbers);
	}
}