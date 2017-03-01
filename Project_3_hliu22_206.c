// Hongyuan Liu, G01042429
// CS 262, Lab Section 206
// Project 3

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUM_OF_SET 10

// Struct to hold a String and a next pointer
typedef struct node {
	char *data;
	struct node *next;
} node;

int strcmpa(char *s1, char *s2);
node * createSet();
void addStringToSet(node *head, char *data);
void removeStringFromSet(node *head, char *data);
void setUnion(node *headOp1, node *headOp2, node *headDest);
void setIntersec(node *headOp1, node *headOp2, node *headDest);
void setSymmetricDiff(node *headOp1, node *headOp2, node *headDest);
void copySet(node *headDest, node *headSrc);
void clearSet(node *head);
void printSet(node *head);

int main() {
	// 10 sets with 10 head pointers
	node *setHeads[NUM_OF_SET]; 
	// initilize sets with dummy nodes
	int i;
	for(i = 0; i < NUM_OF_SET; i++) {
		setHeads[i] = createSet();
	}

	int keepGoing = 1;
	int setChoice = 0;
	int setChoiceOp1 = 0;
	int setChoiceOp2 = 0;
	char choice = ' ';	
	char inputString[50];
	while(keepGoing) {
		printf("%-30s", "add string (a)");
		printf("remove string (r)\n");
		printf("%-30s", "union (u)");
		printf("intersection (i)\n");
		printf("%-30s", "symmetric difference (s)");
		printf("copy (c)\n");
		printf("%-30s", "clear (z)");
		printf("print set (p)\n");
		printf("quit (q)\n-> ");

		scanf(" %c", &choice);
		switch(choice) {
			case 'A':
			case 'a':
				// add a string to a set
				printf("set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printf("string: ");
				scanf("%s", inputString);
				addStringToSet(setHeads[setChoice], inputString);
				break;
			case 'R':
			case 'r':
				// remove a string from a set
				printf("set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printf("delete string: ");
				scanf("%s", inputString);
				removeStringFromSet(setHeads[setChoice], inputString);				
				break;
			case 'U':
			case 'u':
				// union of two set, and store it to destination set
				printf("destination set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printf("first operand: ");
				scanf("%d", &setChoiceOp1);
				while(setChoiceOp1 < 0 || setChoiceOp1 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp1);					
				}
				printf("second operand: ");
				scanf("%d", &setChoiceOp2);
				while(setChoiceOp2 < 0 || setChoiceOp2 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp2);					
				}
				setUnion(setHeads[setChoiceOp1], setHeads[setChoiceOp2], setHeads[setChoice]);				
				break;
			case 'I':
			case 'i':
				// intersection of two set, and store it to destination set			
				printf("destination set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printf("first operand: ");
				scanf("%d", &setChoiceOp1);
				while(setChoiceOp1 < 0 || setChoiceOp1 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp1);					
				}
				printf("second operand: ");
				scanf("%d", &setChoiceOp2);
				while(setChoiceOp2 < 0 || setChoiceOp2 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp2);					
				}
				setIntersec(setHeads[setChoiceOp1], setHeads[setChoiceOp2], setHeads[setChoice]);				
				break;
			case 'S':
			case 's':
				// symmetric difference of two set, and store it to destination set
				printf("destination set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printf("first operand: ");
				scanf("%d", &setChoiceOp1);
				while(setChoiceOp1 < 0 || setChoiceOp1 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp1);					
				}
				printf("second operand: ");
				scanf("%d", &setChoiceOp2);
				while(setChoiceOp2 < 0 || setChoiceOp2 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp2);					
				}
				setSymmetricDiff(setHeads[setChoiceOp1], setHeads[setChoiceOp2], setHeads[setChoice]);				
				break;
			case 'C':
			case 'c':
				// copy source set to destination set
				printf("destination set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printf("source: ");
				scanf("%d", &setChoiceOp1);
				while(setChoiceOp1 < 0 || setChoiceOp1 > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoiceOp1);					
				}
				copySet(setHeads[setChoice], setHeads[setChoiceOp1]);
				break;
			case 'Z':
			case 'z':
				// clear set
				printf("set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				clearSet(setHeads[setChoice]);
				break;
			case 'P':
			case 'p':
				// print set
				printf("set: ");
				scanf("%d", &setChoice);
				while(setChoice < 0 || setChoice > 9) {
					printf("Set number is in range 0 to 9: ");
					scanf("%d", &setChoice);					
				}
				printSet(setHeads[setChoice]);				
				break;
			case 'Q':
			case 'q': 
				// end of program
				keepGoing = 0;
				// clean up sets and free dummy nodes
				int i;
				for(i = 0; i < NUM_OF_SET; i++) {
					clearSet(setHeads[i]);
					free(setHeads[i]);
				}
				break;
			default:
				printf("The input choice is invalid.\n");
				break;
		}
		printf("\n");
	}
	return 0;
}

int strcmpa(char *s1, char *s2) {
	while (*s1 && tolower(*s1) == tolower(*s2)) {
		s1++;
		s2++;
	}
	return tolower(*s1) - tolower(*s2);
}

// Finish
node * createSet() {
	node *head = malloc(sizeof(node)); // Allocate memory for a new node which is dummy node
	if(!head) {
		printf("Error allocating memory for head!\n");
		exit(0);
	}	
	head -> next = NULL; // dummy node has no next element yet
	head -> data = NULL;
	return head;
}

// Finish
void addStringToSet(node *head, char *data) {
	node *ptr = head; // ptr points to what head points to
	while(ptr -> next) {
		int compare = strcmpa(ptr -> next -> data, data);
		if(compare == 0) {
			// the node has same string as data
			// set do not allow duplicates, skip add 
			return;
		} else if(compare > 0) {
			// the node has a string > data
			// found the position to add node
			break;
		}
		// string data in the node is < data
		// advance to next node
		ptr = ptr -> next;
	}

	// allocate memory for a new node, newPtr points to it
	node *newPtr = malloc(sizeof(node));
	if(!newPtr) {
		printf("Error allocating memory for newPtr!\n");
		exit(0);
	}

	// allocate memory for the string in the new node
	newPtr -> data = malloc(strlen(data) + 1);
	if(!(newPtr -> data)) {
		printf("Error allocating memory for string in newPtr!\n");
		exit(0);
	}
	// the new node will have data as its String
	strcpy(newPtr -> data, data);
	// the new node's next is the next of the node that ptr points to
	newPtr -> next = ptr -> next;
	// the node ptr points to now has the new node as its next
	ptr -> next = newPtr;
}

// Finish
void removeStringFromSet(node *head, char *data) {
	node *ptr = head;
	while(ptr -> next) {
		int compare = strcmpa(data, ptr -> next -> data);
		if(compare == 0) {
			// found it
			// killNode points to the node to remove
			node *killNode = ptr -> next;
			// killData points to String data in node
			char *killData = killNode -> data;
			// remove the node from set by bypassing it
			ptr -> next = ptr -> next -> next;
			// free the String data
			free(killData);
			// free the node killNode points to
			free(killNode);
			return; 
		}
		ptr = ptr -> next;
	}
}

// Finish
void setUnion(node *headOp1, node *headOp2, node *headDest) {
	node *ptr = NULL;

	// create new sets for copying
	node *headOp1Cp = createSet();
	node *headOp2Cp = createSet();	

	// copy set Op1 to Op1Cp
	// copy set Op2 to Op2Cp
	copySet(headOp1Cp, headOp1);
	copySet(headOp2Cp,headOp2);

	// clear destination set
	clearSet(headDest); 

	// add all strings of set Op1Cp to destination set
	ptr = headOp1Cp -> next;
	while(ptr) {
		addStringToSet(headDest, ptr -> data);
		ptr = ptr -> next;
	}

	// add all strings of set Op2Cp to destination set
	ptr = headOp2Cp -> next;
	while(ptr) {
		addStringToSet(headDest, ptr -> data);
		ptr = ptr -> next;
	}

	// clear the copy sets and free the dummy nodes
	clearSet(headOp1Cp);
	clearSet(headOp2Cp);
	free(headOp1Cp);
	free(headOp2Cp);
}

// Finish
void setIntersec(node *headOp1, node *headOp2, node *headDest) {
	node *ptr1 = NULL;
	node *ptr2 = NULL;

	// create new sets for copying
	node *headOp1Cp = createSet();
	node *headOp2Cp = createSet();	

	// copy set Op1 to Op1Cp
	// copy set Op2 to Op2Cp
	copySet(headOp1Cp, headOp1);
	copySet(headOp2Cp,headOp2);

	// clear destination set
	clearSet(headDest);

	ptr1 = headOp1Cp -> next;
	ptr2 = headOp2Cp -> next;
	// compare each string of headOp1Cp 
	// with each string of headOp2Cp
	while(ptr1) {
		while(ptr2) {
			// if string from headOp1Cp is the same as string from headOp2Cp
			// add the string to destination set
			// break because we want headOp1Cp to advance to next string
			if(strcmpa(ptr2 -> data, ptr1 -> data) == 0) {
				addStringToSet(headDest, ptr2 -> data);
				break;
			}
			// advance to next strings for headOp2Cp
			ptr2 = ptr2 -> next;
		}
		// advance to next strings for headOp1Cp
		// headOp1Cp restart from the begining
		ptr1 = ptr1 -> next;
		ptr2 = headOp2Cp -> next;
	}

	// clear the copy sets and free the dummy nodes
	clearSet(headOp1Cp);
	clearSet(headOp2Cp);
	free(headOp1Cp);
	free(headOp2Cp);
}

// Finish
void setSymmetricDiff(node *headOp1, node *headOp2, node *headDest) {
	node *ptr = NULL;

	// create new sets for union and intersect
	node *headUnion = createSet();
	node *headIntersec = createSet();	

	// get union of set Op1 and Op2
	// get intersect of set Op1 and Op2
	setUnion(headOp1, headOp2, headUnion);
	setIntersec(headOp1, headOp2, headIntersec);

	// clear destination set
	clearSet(headDest);

	// add all strings of union set to destination set
	ptr = headUnion -> next;
	while(ptr) {
		addStringToSet(headDest, ptr -> data);
		ptr = ptr -> next;
	}

	// remove all strings of intersect set from destination set
	// so that we can get a result of symmetric difference set
	ptr = headIntersec -> next;
	while(ptr) {
		removeStringFromSet(headDest, ptr -> data);
		ptr = ptr -> next;
	}

	// clear the copy sets and free the dummy nodes
	clearSet(headUnion);
	clearSet(headIntersec);
	free(headUnion);
	free(headIntersec);
}

// Finish
void copySet(node *headDest, node *headSrc) {
	// if copy a set to itself, don't do anything
	if(headDest == headSrc) {
		return;
	}
	// clear the destination set
	clearSet(headDest);
	// ptr points to first node of source set
	node *ptr = headSrc -> next;
	while(ptr) {
		// traverse the source set to add each element to the destination set
		addStringToSet(headDest, ptr -> data);
		ptr = ptr -> next;
	}
}

// Finish
void clearSet(node *head) {
	// Two pointers, killNode points to the node
	// at the previous position of 
	// the node that ptr points to.
	// both start at the first element
	node *ptr = head -> next;
	node *killNode = head -> next;
	while(ptr) {
		// ptr points to next node
		ptr = ptr -> next;
		// killData points to String data in node
		char *killData = killNode -> data;
		// free the String data
		free(killData);
		// free the node killNode points to
		free(killNode);
		// advance killNode to points to what ptr points to
		killNode = ptr;
	}
	// pointer that point to first element now is NULL
	head -> next = NULL;
}

// Finish
void printSet(node *head) {
	printf("{");
	// ptr points the node that is after the dummy node
	// which is the first element node
	node *ptr = head -> next;
	while(ptr && ptr -> next) {
		// traverse the set to print each element except the last element
		printf("%s, ", ptr -> data);
		ptr = ptr -> next;
	}
	// print last element
	if(ptr) {
		printf("%s", ptr -> data);
	}
	printf("}\n");
}