/*
 * main.c
 *
 *  Created on: Jun 24, 2015
 *      Author: dchiu
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
	BST *tree = (BST *)malloc(sizeof(BST));
	tree->root = NULL;

	insert(tree, 1);
	insert(tree, 3);
	insert(tree, 30);
	insert(tree, 0);
	insert(tree, 2);

	printTreeInOrder(tree);

	if (search(tree, 1))
		printf("yay\n");
	if (search(tree, 3))
		printf("yay\n");
	if (search(tree, 30))
		printf("yay\n");
	if (search(tree, 0))
		printf("yay\n");
	if (search(tree, 2))
		printf("yay\n");
	if (search(tree, -1))
		printf("yay\n");
	if (search(tree, 20))
		printf("yay\n");

	freeTree(tree);
	return 0;
}
