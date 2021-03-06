#include "stdafx.h"
#pragma once 

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include <cassert>
#include <queue>
#include <stack>
#include <vector>
#include "uGraph.h"
#include "Exception.h"
using namespace std;
using std::vector;

void PrintTestHeader(const char *testName)
{
	cout << "\n************* " << testName << " ************" << endl;
}

void PrintTestPass(const char * test)
{
	cout << "\t" << test << ": TEST PASS" << endl;
}

void PrintTestPassForGoodMeasure(const char * test)
{
	cout << "\t" << test << ": TEST FAIL" << endl;
}

void PrintTestFail(const char * test, const char * message)
{
	cerr << message << endl;
	cerr << "\t" << test << ": TEST FAIL" << endl;;
}

void PrintTestFailForGoodMeasure(const char * test, const char * message)
{
	cerr << message << endl;
	cerr << "\t" << test << ": TEST PASS" << endl;
}

void testingGenericInsertion()
{
	const char * test = "Testing Generic Insertion";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	cout << "Case: Inserting values of A, B, C, D, E, F, consecutively." << endl;

	try {
		//Insert Verticies 
		graph.insertVertex('A');
		graph.insertVertex('B');
		graph.insertVertex('C');
		graph.insertVertex('D');
		graph.insertVertex('E');
		graph.insertVertex('F');
		// Insert Edges
		graph.insertEdge('A', 'B', 1);
		graph.insertEdge('A', 'E', 1);
		graph.insertEdge('B', 'A', 1);
		graph.insertEdge('B', 'E', 1);
		graph.insertEdge('B', 'C', 1);
		graph.insertEdge('C', 'B', 1);
		graph.insertEdge('C', 'D', 1);
		graph.insertEdge('D', 'C', 1);
		graph.insertEdge('D', 'E', 1);
		graph.insertEdge('E', 'A', 1);
		graph.insertEdge('E', 'B', 1);
		graph.insertEdge('E', 'D', 1);
		graph.insertEdge('E', 'F', 1);
		graph.insertEdge('F', 'E', 1);

		PrintTestPass(test);
	}
	catch (Exception e) {
		PrintTestFail(test, e.getMessage());
	}
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingDeleteExistingVertex()
{
	const char * test = "Testing Delete Existing Vertex";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	cout << "Case: Inserting values of A, B, C, D, E, F, consecutively." << endl;
	//Insert Verticies 
	graph.insertVertex('A');
	graph.insertVertex('B');
	graph.insertVertex('C');
	graph.insertVertex('D');
	graph.insertVertex('E');
	graph.insertVertex('F');
	// Insert Edges
	graph.insertEdge('A', 'B', 1);
	graph.insertEdge('A', 'E', 1);
	graph.insertEdge('B', 'A', 1);
	graph.insertEdge('B', 'E', 1);
	graph.insertEdge('B', 'C', 1);
	graph.insertEdge('C', 'B', 1);
	graph.insertEdge('C', 'D', 1);
	graph.insertEdge('D', 'C', 1);
	graph.insertEdge('D', 'E', 1);
	graph.insertEdge('E', 'A', 1);
	graph.insertEdge('E', 'B', 1);
	graph.insertEdge('E', 'D', 1);
	graph.insertEdge('E', 'F', 1);
	graph.insertEdge('F', 'E', 1);

	try {
		graph.deleteVertex('F');

		PrintTestPass(test);
	}
	catch (Exception e) {
		PrintTestFail(test, e.getMessage());
	}
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingDeleteExistingEdge()
{
	const char * test = "Testing Delete Existing Edge";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	cout << "Case: Inserting values of A, B, C, D, E, F, consecutively." << endl;
	//Insert Verticies 
	graph.insertVertex('A');
	graph.insertVertex('B');
	graph.insertVertex('C');
	graph.insertVertex('D');
	graph.insertVertex('E');
	graph.insertVertex('F');
	// Insert Edges
	graph.insertEdge('A', 'B', 1);
	graph.insertEdge('A', 'E', 1);
	graph.insertEdge('B', 'A', 1);
	graph.insertEdge('B', 'E', 1);
	graph.insertEdge('B', 'C', 1);
	graph.insertEdge('C', 'B', 1);
	graph.insertEdge('C', 'D', 1);
	graph.insertEdge('D', 'C', 1);
	graph.insertEdge('D', 'E', 1);
	graph.insertEdge('E', 'A', 1);
	graph.insertEdge('E', 'B', 1);
	graph.insertEdge('E', 'D', 1);
	graph.insertEdge('E', 'F', 1);
	graph.insertEdge('F', 'E', 1);

	try {
		graph.deleteEdge('A', 'E', 1);

		PrintTestPass(test);
	}
	catch (Exception e) {
		PrintTestFail(test, e.getMessage());
	}
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingDeleteNonExistentVertex()
{
	const char * test = "Testing Delete Non-Existent Vertex";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	cout << "Case: Inserting values of A, B, C, D, E, F, consecutively." << endl;
	//Insert Verticies 
	graph.insertVertex('A');
	graph.insertVertex('B');
	graph.insertVertex('C');
	graph.insertVertex('D');
	graph.insertVertex('E');
	graph.insertVertex('F');
	// Insert Edges
	graph.insertEdge('A', 'B', 1);
	graph.insertEdge('A', 'E', 1);
	graph.insertEdge('B', 'A', 1);
	graph.insertEdge('B', 'E', 1);
	graph.insertEdge('B', 'C', 1);
	graph.insertEdge('C', 'B', 1);
	graph.insertEdge('C', 'D', 1);
	graph.insertEdge('D', 'C', 1);
	graph.insertEdge('D', 'E', 1);
	graph.insertEdge('E', 'A', 1);
	graph.insertEdge('E', 'B', 1);
	graph.insertEdge('E', 'D', 1);
	graph.insertEdge('E', 'F', 1);
	graph.insertEdge('F', 'E', 1);

	try {
		graph.deleteVertex('G');

		PrintTestPassForGoodMeasure(test);
	}
	catch(Exception e) {
		PrintTestFailForGoodMeasure(test, e.getMessage());
	}
	
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingDeleteNonExistentEdge()
{
	const char * test = "Testing Delete Non-Existent Edge";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	cout << "Case: Inserting values of A, B, C, D, E, F, consecutively." << endl;
	//Insert Verticies 
	graph.insertVertex('A');
	graph.insertVertex('B');
	graph.insertVertex('C');
	graph.insertVertex('D');
	graph.insertVertex('E');
	graph.insertVertex('F');
	// Insert Edges
	graph.insertEdge('A', 'B', 1);
	graph.insertEdge('A', 'E', 1);
	graph.insertEdge('B', 'A', 1);
	graph.insertEdge('B', 'E', 1);
	graph.insertEdge('B', 'C', 1);
	graph.insertEdge('C', 'B', 1);
	graph.insertEdge('C', 'D', 1);
	graph.insertEdge('D', 'C', 1);
	graph.insertEdge('D', 'E', 1);
	graph.insertEdge('E', 'A', 1);
	graph.insertEdge('E', 'B', 1);
	graph.insertEdge('E', 'D', 1);
	graph.insertEdge('E', 'F', 1);
	graph.insertEdge('F', 'E', 1);

	try {
		graph.deleteEdge('A', 'Z', 1);

		PrintTestPassForGoodMeasure(test);
	}
	catch (Exception e) {
		PrintTestFailForGoodMeasure(test, e.getMessage());
	}
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingBreadthFirst()
{
	const char * test = "Testing Breadth-First Search Method";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	//Insert Verticies 
	graph.insertVertex('A');
	graph.insertVertex('B');
	graph.insertVertex('C');
	graph.insertVertex('D');
	graph.insertVertex('E');
	graph.insertVertex('F');
	// Insert Edges
	graph.insertEdge( 'A', 'B', 1);
	graph.insertEdge('A', 'E', 1);
	graph.insertEdge('B', 'A', 1);
	graph.insertEdge('B', 'E', 1);
	graph.insertEdge('B', 'C', 1);
	graph.insertEdge('C', 'B', 1);
	graph.insertEdge('C', 'D', 1);
	graph.insertEdge('D', 'C', 1);
	graph.insertEdge('D', 'E', 1);
	graph.insertEdge('E', 'A', 1);
	graph.insertEdge('E', 'B', 1);
	graph.insertEdge('E', 'D', 1);
	graph.insertEdge('E', 'F', 1);
	graph.insertEdge('F', 'E', 1);

	try {
		cout << "Search for: F with breadthfirstSearch()" << endl;
		graph.breadthfirstSearch('F');
		
		cout << endl << "Result: Vertex F found. " << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e) {
		PrintTestFail(test, e.getMessage());
	}
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingDepthFirst()
{
	const char * test = "Testing Depth First Search Method";
	PrintTestHeader(test);

	uGraph<char, int> graph;
	//Insert Verticies 
	graph.insertVertex('A');
	graph.insertVertex('B');
	graph.insertVertex('C');
	graph.insertVertex('D');
	graph.insertVertex('E');
	graph.insertVertex('F');
	// Insert Edges
	graph.insertEdge( 'A', 'B', 1);
	graph.insertEdge('A', 'E', 1);
	graph.insertEdge('B', 'A', 1);
	graph.insertEdge('B', 'E', 1);
	graph.insertEdge('B', 'C', 1);
	graph.insertEdge('C', 'B', 1);
	graph.insertEdge('C', 'D', 1);
	graph.insertEdge('D', 'C', 1);
	graph.insertEdge('D', 'E', 1);
	graph.insertEdge('E', 'A', 1);
	graph.insertEdge('E', 'B', 1);
	graph.insertEdge('E', 'D', 1);
	graph.insertEdge('E', 'F', 1);
	graph.insertEdge('F', 'E', 1);

	try {
		cout << "Search for: F with depthfirstSearch()" << endl;
		graph.depthfirstSearch('F');
		
		cout << endl << "Result: Vertex F found. " << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	cout << " --------------------------------------------------------------------------------------" << endl;
}


void RunTest()
{
	testingGenericInsertion();
	testingDeleteExistingVertex();
	testingDeleteExistingEdge();
	testingDeleteNonExistentVertex();
	testingDeleteNonExistentEdge();
	testingBreadthFirst();
	testingDepthFirst();
}

int main() {

	RunTest();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}