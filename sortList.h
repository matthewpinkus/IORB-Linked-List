typedef struct iorb {
	int base_pri;
	struct iorb *link;
	int filler;
} IORB;

IORB* sortList(IORB *head, int (*prio)(int)) {
	IORB **ppNew = &head;	// Used to traverse list
	IORB **ppLesser;		// Double pointer to smallest priority
	IORB **ppCurr;			// Double pointer to current node in list 
	IORB *pCurr;			// Pointer to the current node in list
	IORB *pTemp;			// Used for swapping IORB head and link 

	// List is empty
	if (head == NULL)
		return (head);

	// Traversal through list using Selection Sort Algorithm
	while ((*ppNew)->link != NULL) {
		ppLesser = ppNew;			// IORB to be checked
		ppCurr = &((*ppNew)->link);	// Next IORB in list to check against

		// Traversal through list
		while ((pCurr = *ppCurr) != NULL) {
			// Stops when a lesser priority value is found, assigns that IORB to ppLesser
			if (prio(pCurr->base_pri) < prio((*ppLesser)->base_pri))
				ppLesser = ppCurr;
			ppCurr = &((*ppCurr)->link);
		}

		// IORB is not itself
		if (*ppNew != *ppLesser) {
			// Swapping IORB pointers
			pTemp = *ppNew;
			*ppNew = *ppLesser;
			*ppLesser = pTemp;

			// Swapping IORB links
			pTemp = (*ppNew)->link;
			(*ppNew)->link = (*ppLesser)->link;
			(*ppLesser)->link = pTemp;
		}
		// Next IORB traversal
		ppNew = &((*ppNew)->link);
	}
	printf("List sorted.\n\n");
	return (head);
}
