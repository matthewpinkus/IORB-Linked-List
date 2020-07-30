#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sortList.h"

int prio(int p) {
	return 100 - p;
}
/* Function to create a new node and fill it with passed values */
IORB* makeNode(int f, int p) {
	IORB *temp = (IORB*) malloc(sizeof(IORB));
	temp->filler = f;
	temp->base_pri = p;
	temp->link = NULL;
	return temp;
}

/* Function to build a list with 10 items in it */
void buildList(IORB **head) {
	for (int i = 0; i < 10; i++) {
		int r = rand() % 99;
		IORB *temp = makeNode(i, r);

		// List is empty
		if (*head == NULL)
			*head = temp;
		else {
			// Otherwise, add new node
			temp->link = *head;
			*head = temp;
		}

		printf(
				"Description: this is i/o request %d, Base Priority: %d Priority: %d\n",
				temp->filler, temp->base_pri, prio(temp->base_pri));
	}

	printf("Building list complete.\n\n");
}

/* Function to free memory allocated to IORB nodes */
void freeList(IORB* head) {
	IORB *temp;
	while (head != NULL) {
		temp = head;
		head = head->link;
		free(temp);
	}
}

/* Function to display the list in ascending order */
void displayListAsc(IORB *head) {
	while (head->link != NULL) {
		printf(
				"Description: this is i/o request %d, Base Priority: %d Priority: %d\n",
				head->filler, head->base_pri, prio(head->base_pri));
		head = head->link;
	}
}

/* Recursive function to display the list in descending order */
void displayListDesc(IORB *head) {
	if (head->link == NULL)
		return;

	displayListDesc(head->link);
	printf(
			"Description: this is i/o request %d, Base Priority: %d Priority: %d\n",
			head->filler, head->base_pri, prio(head->base_pri));
}

int main() {
	srand(time(NULL));
	IORB *head = makeNode(0, 0);
	int choice;
	do {
		printf(
				"Please enter your choice:\n0) Exit\n1) Build List\n2) Sort List\n3) Display List(ascending)\n4) Display List(descending)\n");
		fflush(stdout);
		scanf("%d", &choice);
		printf("Your choice: %d\n", choice);

		switch (choice) {
		case 1:
			buildList(&head);
			break;
		case 2:
			head = sortList(head, prio);
			break;
		case 3:
			displayListAsc(head);
			break;
		case 4:
			displayListDesc(head);
			break;
		}
	} while (choice != 0);
	printf("Freeing list and terminating...\n");
	freeList(head);
	return 0;
}

