/* -------------------------------------------
Name: Stefan Djurkic
/* -------------------------------------------
Name: Stefan Djurkic
Email: stefandjurkic@gmail.com
Website: stefandjurkic.com
Date: 12/20/2017
File: contactsHelpers.c
Purpose: This file contains the implementations for functions that manipulate i/o in relation to the contact struct
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5
#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n') // empty execution code block on purpose
	{
		;
	}
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int Value;

	while (NL != '\n')
	{
		scanf(" %d%c", &Value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return Value;
}

// getIntInRange:
int getIntInRange(int param1, int param2)
{
	int para1;
	para1 = getInt();
	
	while (para1 < param1 || para1 > param2)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", param1, param2);
		
		para1 = getInt();
	}
	return para1;
}

// yes:
int yes(void)
{
	char val;        // var for y or n
	char afterVal;   // check for enter
	int result = -1; // set default
	do {
		scanf("%c%c", &val, &afterVal);

		if (val == 'y' || val == 'Y') 
		{
			result = 1;
		}
		else if (val == 'n' || val == 'N') 
		{
			result = 0;
		}
		else 
		{
			result = -1;
		}
		if (afterVal != '\n' || result == -1) 
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}	
	} while (afterVal != '\n' || result == -1);
	return result;
}

// menu:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by last name\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	int input = getIntInRange(0, 6);
	return input;
}

// ContactManagerSystem:
void ContactManagerSystem(void)
{
	int varExit = 0; /*Declare exit variable*/

	/*Default struct*/
	struct Contact people[MAXCONTACTS] = { { {  "Rick",  {'\0'},  "Grimes"  },{ 11,"Trailer Park", 0,"King City","A7A 2J2"},{"4161112222","4162223333","4163334444"} },
											{{"Maggie","R.","Greene"},{ 55,"Hightop House", 0,"Bolton","A9A 3K3"}, {"9051112222","9052223333","9053334444"} },
											{{"Morgan","A.","Jones"},{ 77,"Cottage Lane", 0,"Peterborough","C7C 9Q9"}, {"7051112222","7052223333","7053334444"} },
											{{"Sasha",{'\0'},"Williams"},{ 55,"Hightop House", 0,"Bolton","A9A 3K3"},{"9052223333","9052223333","9054445555"} },};
	while (varExit == 0) /*while out exit variable is equivalent to zero display the menu*/
	{
		switch (menu()) /*Depending on the menu return value which corresponds to input, switch to one of the following*/
		{
		case 1: 
			/*Display contacts*/
			printf("\n");
			displayContacts(people, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:		
			/*Add a contact*/
			printf("\n");
			addContact(people, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:		
			/*Update a contact*/
			printf("\n");
			printf("Enter the cell number for the contact: ");
			updateContact(people, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:	
			/*Delete a contact*/
			printf("\n");
			printf("Enter the cell number for the contact: ");
			deleteContact(people, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			/*Search for a contact*/
			printf("\n");
			searchContacts(people, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:		
			/*Sort contacts*/
			printf("\n");
			sortContacts(people, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			/*Exit program*/
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			int answer = yes();
			if (answer == 1) 
			{
				printf("\n");
				printf("Contact Management System: terminated\n");
				varExit = 1; //break the loop
				break;
			}
			else if (answer == 0) 
			{
				printf("\n");
				break;
			}
		default: break;
		}
	}
}

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[11])
{
	int needInput = 1;
	while (needInput == 1) {
	
		scanf(" %10s", telNum);
		clearKeyboard();
		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
			
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contact[], int size, const char cellNum[])
{
	int index = -1;

	for (int i = 0; i < size && index == -1; i++) {
	
		if (strcmp(contact[i].numbers.cell, cellNum) == 0) 
		{
			index = i;
		}
	}
	return index;
}

// displayContactHeader
void displayContactHeader(void) 
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int size) 
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", size);
}

// displayContact::
void displayContact(const struct Contact *contact) 
{
	int len = strlen(contact->name.middleInitial);

	printf(" %s ", contact->name.firstName );
	
	if (len != 0) 
	{
		printf("%s ", contact->name.middleInitial);
	}
	
	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) { printf("Apt# %d, ", contact->address.apartmentNumber); }
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size) 
{
	int i, newsize = size;
	displayContactHeader();
	char empty[50] = { '\0' };

	for (i = 0; i < size; i++) 
	{
		if (strcmp(contact[i].numbers.cell, empty) > 0 || strcmp(contact[i].numbers.cell, empty) < 0)
		{
			displayContact(&contact[i]);
			

		}
		else {
			newsize -= 1;
		}
	}
	displayContactFooter(newsize);	
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size) 
{	
	int index;
	char zStorage[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(zStorage);
	printf("\n");
	index = findContactIndex(contact, size, zStorage);
	if (index != -1) 
	{
		displayContact(&contact[index]); 
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}

// addContact:0
void addContact(struct Contact contact[], int size) 
{
	int notFull = 0; /*Variable that is turned to 1 if we add a contact and 0 if no contacts were added*/
	
	for (int i = 0; i < size; i++) 
	{
		int len = strlen(contact[i].numbers.cell);

		if (len == 0)
		{
			getContact(&contact[i]);
			printf("--- New contact added! ---\n");
			notFull = 1;
		}
	}	
	if (notFull != 1) { printf("*** ERROR: The contact list is full! ***\n");  } /*check our notFull variable for a 1 value and if one is not present we display an error msg*/	
}

// updateContact:
void updateContact(struct Contact contact[], int size) 
{
	char zStorage[11];
	int index;
	char empty[50] = { '\0' };

	getTenDigitPhone(zStorage);
	index = findContactIndex(contact, size, zStorage);
	if (index == -1) 
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else 
	{
		printf("\n");
		printf("Contact found:\n");
		displayContact(&contact[index]);
		printf("\n");
		strcpy(contact[index].numbers.home, empty);
		strcpy(contact[index].numbers.business, empty);
		strcpy(contact[index].numbers.cell, empty);
		contact[index].address.apartmentNumber = 0;	
		getReplaceContact(&contact[index]);
		printf("--- Contact Updated! ---\n");	
	}
}

// deleteContact:
void deleteContact(struct Contact contact[], int size) 
{
	char empty[50] = { '\0' };
	char zStorage[11];
	int index;
	getTenDigitPhone(zStorage);
	index = findContactIndex(contact, size, zStorage);
	if (index == -1) 
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
		if (index != -1) 
		{
			printf("\n");
			printf("Contact found:\n");
			displayContact(&contact[index]);
			printf("\n");
			printf("CONFIRM: Delete this contact? (y or n): ");
			if (yes() == 1) 
			{
				// Make sure all information is set to empty
				strcpy(contact[index].name.firstName, empty);
				strcpy(contact[index].name.lastName, empty);
				strcpy(contact[index].name.middleInitial, empty);
				strcpy(contact[index].numbers.home, empty);
				strcpy(contact[index].numbers.business, empty);
				strcpy(contact[index].numbers.cell, empty);
				contact[index].address.apartmentNumber = 0;
				printf("--- Contact deleted! ---\n");
			}

		}
}

// sortContacts:
/*Sort the contact list by number*/
void sortContacts(struct Contact contact[], int size) 
{
	struct Contact tempC; /*Declare a temporary struct*/
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < (size - 1 - i); j++)
		{
			if ( strcmp(contact[j].name.lastName, contact[j + 1].name.lastName) > 0)
			{
				tempC = contact[j]; /*copy the struct*/
				contact[j] = contact[j + 1];
				contact[j + 1] = tempC;
			}
		}
	}
}