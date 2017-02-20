/*This project is about KD Tree which can hold K number of data in a node and use insert method to insert data and delete to delete method. 
It also uses require basic method to perform basic operations on this data structure.
*/
#include <stdio.h>
#include"stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

using namespace std;

/*TreeNode class to create node with neccessary fields */
class TreeNode
{
public:

	//KD is an array to hold K number of integers 
	int *KD;
	TREENODEPTR leftChild;
	TREENODEPTR rightChild;

	//default condtructor to create a node with array of size 2. 
	TreeNode()	{
		KD = new int[2];
		leftChild = TREENULLPTR;
		rightChild = TREENULLPTR;
	}

	//constructor to create a node with spesicific dimentions.
	TreeNode(int size){
		KD = new int[size];
		leftChild = TREENULLPTR;
		rightChild = TREENULLPTR;
	}
};

/*
KDTree class contains all required method to perfom basic operations like insert, delete, find etc.
*/
class KDTree
{ 
private:
	TREENODEPTR root;
    int count,k;
	//TREENODEPTR temp = root;
public:

	//default condtructor. 
	KDTree(){
		k = 2;
		root = TREENULLPTR;
		count = 0;
	}

	//constructor to initialize with spesicific dimentions.
	KDTree(int dimSize)
	{
		k = dimSize;
		root = TREENULLPTR;
		count = 0;
	}

	/*This method simply return the size of the tree in other words it just return total number of nodes*/
	unsigned int getSize(){
		return count;
	}

	/*This method simply return pointer to the root*/
	TREENODEPTR getRoot() {
		return root;
	}
	/*This method return left child of passed node and it returns NULL if there is no left child*/
	TREENODEPTR getLeftChild(TREENODEPTR node) {

		if (node->leftChild != TREENULLPTR && node != TREENULLPTR){
			return node->leftChild;
		}
		else
			return TREENULLPTR;
	}
	/*This method return right child of passed node and it returns NULL if there is no right child*/
	TREENODEPTR getRightChild(TREENODEPTR node) {

		if (node->rightChild != TREENULLPTR){
			return node->rightChild;
		}
		else
			return TREENULLPTR;
	}
	/*This method simply create a node and assign values of passed array*/
	TREENODEPTR createNode(int *points){

		TREENODEPTR newNode = new TreeNode();
		newNode->KD = new int[k];

		//for loop to assign values.
		for (int i = 0; i < k; i++){
			newNode->KD[i] = points[i];
		}
		newNode->leftChild = TREENULLPTR;
		newNode->rightChild = TREENULLPTR;
		return newNode;
	}

	/*This method insert element at proper place and to do that it calls insertHelper method which does almost all work for it*/
	void insert(int	*coordinates){

		//assign node as a root if root is empty
		if (root == TREENULLPTR){
			root = createNode(coordinates);
			count++;
		}
		else{
			//calls insertHelper method
			insertHelper(root, coordinates, 0);
		}
	}

	/*This method inserts element at proper place and it can achieve by recursion*/
	void insertHelper(TREENODEPTR nodePtr, int *coordinates, unsigned int height){

		//count current dimention on each level
		unsigned int currentDim = height % k;

		//condition to check if current dimention of coordinates is less than passed nodes current dimention
		if (coordinates[currentDim] < nodePtr->KD[currentDim]){

			//create a node and assign it to the left child of passed node if passed node's left child is null and increament count variable to keep track number of nodes.
			if (nodePtr->leftChild == TREENULLPTR){
				nodePtr->leftChild = createNode(coordinates);
				count++;
			}
			//calls recursively to check left subtree.
			else{
				insertHelper(nodePtr->leftChild, coordinates, height + 1);
			}
		}		
		else
		{
			//create a node and assign it to the right child of passed node if passed node's right child is null and increament count variable to keep track number of nodes.
			if (nodePtr->rightChild == TREENULLPTR){
				nodePtr->rightChild = createNode(coordinates);
				count++;
			}
			else
			{
				//calls recursively to check right subtree.
				insertHelper(nodePtr->rightChild, coordinates, height + 1);
			}
		}
	}

	/*This method prints subtree of the passed node and it also calls print method to for printing elements and it can achieve by recursion
	*/
	void printSubTree(TREENODEPTR subTreeRoot){

		//prints / if subTreeRoot is Null
		if (subTreeRoot == TREENULLPTR){
			cout << "/";
			return;
		}
		//calls print method to prints all elements.
		print(subTreeRoot);
		//calls recursively on the left child and right child
		printSubTree(subTreeRoot->leftChild);
		printSubTree(subTreeRoot->rightChild);	
	}

	/*This mehtod finds desired node with passed coordinates and return node pointer and it also calls findHelper method to do that work.
	*/
	TREENODEPTR find(int *coordinates){

		return findHelper(root, coordinates);
	}
	
	/*This method finds element at in a tree by checking its left and right child recursively*/
	TREENODEPTR findHelper(TREENODEPTR node, int *coordinates){

		//return null if passes node is empty.
		if (node == TREENULLPTR)
			return TREENULLPTR;
		else
		{
			//calls checkvalue method to check all values of passed node and coordinates and return that node if all values are equal.
			if (checkValue(coordinates, node))
				return node;
			//calls recursively to left subtree	
			if (node->leftChild!=TREENULLPTR)
				findHelper(node->leftChild, coordinates);
			
			//calls recursively to right subtree
			else
				findHelper(node->rightChild, coordinates);
		}
		return TREENULLPTR;
	}
	
	/*This method compares all value of passed coordinates and node's KD array*/
	bool checkValue(int *coordinates,TREENODEPTR temp){
		int i = 0;
		//while loop to check values 
		while (i<k)
		{
			if (temp->KD[i] != coordinates[i])
				return false;
			i++;
		}
		//return true if all values are same
		return true;
	}

	/*This method find the range of coordintes if it is less than the passed distance than it prints out that node
	and this can achieve by recursion*/
	void rangeQuery(int	*coordinates, double distance){

		//return if root is null
		if (root == TREENULLPTR)
			return;
		else
			//calls rangeQueryHelper method to test range 
			rangeQueryHelper(coordinates,distance,root);
	}

	/*This method calls calculateDist method to calculate the distance and then test all cases */
	void rangeQueryHelper(int *points, double dist, TREENODEPTR tempNode){

		//store calulated distance in distWithTempNode
		double distWithTempNode = calculateDist(points, tempNode->KD);

		//check if distWithTempNode is less than the passed distance then calls print method to print all values of that node
		if (distWithTempNode < dist)
			print(tempNode);
		//recursively check left child of the passed node
		if (tempNode->leftChild != TREENULLPTR)
			rangeQueryHelper(points, dist, tempNode->leftChild);
		//recursively check right child of the passed node
		if (tempNode->rightChild!=TREENULLPTR)
			rangeQueryHelper(points, dist, tempNode->rightChild);
	}

	/*This method simply prints the values of passed node with proper format*/
	void print(TREENODEPTR node){
		if (node == TREENULLPTR)
			return;

		cout << "{ ";
		//for loop to go through whole array
		for (int i = 0; i < k; i++){
			cout << node->KD[i]<<" ";
		}
		cout << "}";
	}
	/*This method calculates the distance between passed two points*/
	double calculateDist(int *point1, int *point2){
		//initialize sum with 0
		double sum = 0;
		//for loop to calculate distance and stores it in to sum
		for (int i = 0; i < k; i++){
			sum = ((point1[i] - point2[i])*(point1[i] - point2[i])) + sum;
		}
		//return sqaure root of sum
		return sqrt(sum);
	}
	
	/*This method simply removes node with passed coordinates and to do that it calls removeHelper method and return true if passed coordinates 
	contain node is successfully deleted from the tree otherwise return false*/
	bool remove(int  *coordinates){
		 removeHelper(root, coordinates, 0);
		 return true;
	}
	/*This method calls checkValue method to check all values of the passed node and points at specfic level*/
	TREENODEPTR removeHelper(TREENODEPTR Node, int * points, int level){
		if (root == TREENULLPTR)
			return TREENULLPTR;
		//calcuates discriminator at specific level
		int curDim = level % k;
		
		//calls method to compare all points with node's points
		if (checkValue(points, Node)){

			//check if right child of Node is null or not
			if (Node->rightChild != TREENULLPTR){

				//find minimum of node's dimention in the right subtree.
				TREENODEPTR tempNode = findMin(Node->rightChild, level);

				//copy all values of minimum to node
				copyElements(Node->KD, tempNode->KD);

				//recursively delete the minimum
				Node->rightChild = removeHelper(Node->rightChild, tempNode->KD, level + 1);
			}
			//check if left child of Node is null or not
			else if (Node->leftChild!=TREENULLPTR)
			{
				//find minimum of node's dimention in the left subtree.
				TREENODEPTR tempNode = findMin(Node->leftChild, level);

				//copy all values of minimum to node
				copyElements(Node->KD, tempNode->KD);

				//recursively delete the minimum
				Node->leftChild = removeHelper(Node->leftChild, tempNode->KD, level + 1);
			}
			//if node to be deleted is lead node
			else
			{
				delete Node;
				return TREENULLPTR;
			}
			return Node;
		}
		//recursively go through left subtree if current node does not contain point
		if (points[curDim] < Node->KD[curDim])
			Node->leftChild = removeHelper(Node->leftChild, points, level + 1);
		//recursively go through right subtree if current node does not contain point
		else
			Node->rightChild = removeHelper(Node->rightChild, points, level + 1);
		return Node;
	}

	/*This method finds the minimum value at discriminator position*/
	TREENODEPTR findMin(TREENODEPTR tempNode, int curDim){
		//create nodes to store the minimum value contain node
		TREENODEPTR minToTheLeftSubTree;
		TREENODEPTR minToTheRightSubTree;
	
		//if tempNode's left child is not null then recursively find minimum on the left subtree
		if (tempNode->leftChild != TREENULLPTR)
			minToTheLeftSubTree = findMin(tempNode->leftChild, curDim);
		else
			minToTheLeftSubTree = TREENULLPTR;
		
		//if tempNode's right child is not null then recursively find minimum on the right subtree
		if (tempNode->rightChild != TREENULLPTR)
			minToTheRightSubTree = findMin(tempNode->rightChild, curDim);
		else
			minToTheRightSubTree = TREENULLPTR;

		//return tempNode if minToTheRightSubTree and minToTheRightSubTree
		if (minToTheLeftSubTree == TREENULLPTR && minToTheRightSubTree == TREENULLPTR)
			return tempNode;
	
		if (tempNode->KD[curDim] < minToTheLeftSubTree->KD[curDim] &&
			tempNode->KD[curDim] < minToTheRightSubTree->KD[curDim]){
			return tempNode;
		}
		//return minToTheLeftSubTree if minToTheLeftSubTree's current dimention value is less than 
		//minToTheRightSubTree's current dimention 
		if (minToTheLeftSubTree->KD[curDim] < minToTheRightSubTree->KD[curDim]){
			return minToTheLeftSubTree;
		}
		//return minToTheRightSubTree if minToTheLeftSubTree's current dimention value is greater than 
		//minToTheRightSubTree's current dimention 
		else
			return minToTheRightSubTree;
	}

	/*This method copies values from point2 to point1*/
	void copyElements(int *point1,int *point2){

		for (int i = 0; i<k; i++)
			point1[i] = point2[i];
	}

};