/*
 * bst.c
 *
 *  Created on: Jun 24, 2015
 *      Author: dchiu
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/**
 * Creates a new BSTNode holding val, then inserts val into tree rooted at root
 * @param root	Pointer to a binary search tree
 * @param key	Key to be inserted
 */
void insert(BST *tree, int key)
{
	//create and initialize new node
	BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
	newNode->val = key;
	newNode->left = NULL;
	newNode->right = NULL;

	//find node to attach newNode
	if (tree->root == NULL)
	{
		tree->root = newNode;
	}
	else
	{
		//loop to find parent
		BSTNode *currentNode = tree->root;
		BSTNode *parentNode = NULL;
		while (currentNode != NULL)
		{
			parentNode = currentNode;
			if (key > currentNode->val)
			{
				currentNode = currentNode->right; //descend down right subtree
			}
			else
			{
				currentNode = currentNode->left; //descend down left subtree
			}
		}
		//link up newNode
		if (key > parentNode->val)
		{
			parentNode->right = newNode;
		}
		else
		{
			parentNode->left = newNode;
		}
	}
}

/**
 * Searches for the given search key
 * @param tree	Pointer to a binary search tree
 * @param searchKey	Search key
 * @return Pointer to the BSTNode on success, NULL otherwise
 */
BSTNode *search(BST *tree, int searchKey)
{
	if (tree->root != NULL)
	{
		BSTNode *currentNode = tree->root;
		while (currentNode != NULL)
		{
			if (searchKey == currentNode->val)
				return currentNode;
			else if (searchKey > currentNode->val)
				currentNode = currentNode->right; //descend down right subtree
			else
				currentNode = currentNode->left; //descend down left subtree
		}
	}
	return NULL;
}

/**
 * Prints tree in ascending order
 * @param tree Pointer to the tree
 */
void printTreeInOrder(BST *tree)
{
	inOrder(tree->root);
}

/**
 * Helper function to print tree in ascending order
 * @param root Pointer to the root of the tree
 */
void inOrder(BSTNode *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d\n", root->val);
		inOrder(root->right);
	}
}

/**
 * Frees up space allocated by BST
 * @param tree Pointer to the tree
 */
void freeTree(BST *tree)
{
	freeTreeNode(tree->root);
}

void freeTreeNode(BSTNode *node)
{
	if (node != NULL)
	{
		if (node->left == NULL && node->right == NULL) //leaf
		{
			printf("Freeing %d\n", node->val);
			free(node);
		}
		else //non-leaf node
		{
			freeTreeNode(node->left);
			freeTreeNode(node->right);
			printf("Freeing %d\n", node->val);
			free(node);
		}
	}
}
