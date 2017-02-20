// Patel_KDTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Patel_KDTree.h"
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	KDTree tree;
	int vals1[2] = { 10, 50 };
	tree.insert(vals1);

	int vals2[] = { 20, 340 };
	tree.insert(vals2);

	int vals3[2] = { 65, 85 };
	tree.insert(vals3);

	int vals4[2] = { 90, 116 };
	tree.insert(vals4);

	int vals5[2] = { 15, 45 };
	tree.insert(vals5);

	int vals6[2] = { 79, 250 };
	tree.insert(vals6);

	int vals7[2] = { 45, 24 };
	tree.insert(vals7);

	int vals8[2] = { 46, 28 };
	tree.insert(vals8);

	int vals9[2] = { 30, 176 };
	tree.insert(vals9);
	cout << endl;

	cout << "first rangeQuery test";

	int rangeVals[2] = { 25, 60 };
	tree.rangeQuery(rangeVals, 40);
	cout << endl;
	cout << endl;

	int notInTree[2] = { 5, 20 };
	cout << "i m herr";
	TREENODEPTR testfind = tree.find(vals8);
	tree.print(testfind);
	cout << endl;
	TREENODEPTR testfind2 = tree.find(vals6);
	tree.print(testfind2);

	if (testfind2 == TREENULLPTR)
		cout << "didn't find";
	cout << endl;
	TREENODEPTR root = tree.getRoot();
	tree.printSubTree(root);

	cout << endl << "Number Items: " << tree.getSize() << endl;

	KDTree tree2 = KDTree(4);
	int va1[4] = { 50, 40, 60, 70 };
	tree2.insert(va1);

	int va2[4] = { 30, 50, 200, 70 };
	tree2.insert(va2);

	int va3[4] = { 25, 40, 60, 70 };
	tree2.insert(va3);

	int va4[4] = { 45, 32, 50, 70 };
	tree2.insert(va4);

	int va5[4] = { 26, 110, 60, 70 };
	tree2.insert(va5);

	int va6[4] = { 20, 60, 44, 70 };
	tree2.insert(va6);



	tree2.printSubTree(tree2.getRoot());

	cout << endl << "Number Items: " << tree2.getSize() << endl;


	TREENODEPTR testingFind = tree2.find(va4);
	tree2.print(testingFind);
	cout << endl << endl << endl;
	cout << "second rangeQuery test";
	int rangeTestV[4] = { 50, 50, 50, 50 };
	tree2.rangeQuery(rangeTestV, 50);
	
	cout << endl<<"before remove method"<<endl;
	tree.printSubTree(root);
	cout << endl;
	tree2.printSubTree(tree2.getRoot());
	tree.remove(vals6);
	tree2.remove(va4);
	cout << endl; cout << endl; cout << endl;
	cout << "after remove method"<<endl;
	tree.printSubTree(root);
	cout << endl;
	tree2.printSubTree(tree2.getRoot());

	system("pause");
	return 0;
}






//KDTree tree;
//int vals1[2] = { 10, 50 };
//tree.insert(vals1);
//
//int vals2[2] = { 11, 51 };
//tree.insert(vals2);
//
//int vals3[2] = { 65, 85 };
//tree.insert(vals3);
//
//int vals4[2] = { 90, 116 };
//tree.insert(vals4);
//
//int vals5[2] = { 15, 45 };
//tree.insert(vals5);
//
//int vals6[2] = { 79, 250 };
//tree.insert(vals6);
//
//int vals7[2] = { 45, 24 };
//tree.insert(vals7);
//
//int vals8[2] = { 46, 28 };
//tree.insert(vals8);
//
//int vals9[2] = { 30, 176 };
//tree.insert(vals9);
//
//TREENODEPTR root = tree.getRoot();
//tree.printSubTree(root);
//unsigned int val1=tree.getSize();
////cout << val1 << endl;
////cout<<endl;
//
//KDTree tree2 = KDTree(4);
//int va1[4] = { 50, 40, 60, 70 };
//tree2.insert(va1);
//
//int va2[4] = { 30, 50, 60, 70 };
//tree2.insert(va2);
//
//int va3[4] = { 25, 40, 60, 70 };
//tree2.insert(va3);
//
//int va4[4] = { 45, 32, 50, 70 };
//tree2.insert(va4);
//
//int va5[4] = { 26, 65, 60, 70 };
//tree2.insert(va5);
//
//int va6[4] = { 20, 60, 44, 70 };
//tree2.insert(va6);
//
//tree2.printSubTree(tree2.getRoot());
//
//tree.printSubTree(tree.getRightChild(root));
//
//tree.rangeQuery();	
//
//system("pause");
//
//
//	return 0;
