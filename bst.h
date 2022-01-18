/*
 * bst.h
 *
 *  Created on: Jun 24, 2015
 *      Author: dchiu
 */

#ifndef BST_H_
#define BST_H_

/**
 * Struct for a BST Node
 */
typedef struct BSTNode
{
	int val;
	struct BSTNode *left;	 //pointer to left childs
	struct BSTNode *right; //pointer to right child
} BSTNode;

/**
 * Struct for Binary Search Tree
 */
typedef struct BST
{
	BSTNode *root; //pointer to root of tree
} BST;

//function declarations
void insert(BST *tree, int key);
BSTNode *search(BST *tree, int searchKey);
void printTreeInOrder(BST *tree);
void inOrder(BSTNode *root);
void freeTree(BST *tree);
void freeTreeNode(BSTNode *root);

#endif /* BST_H_ */
