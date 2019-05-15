// BinarTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct Node                        
{
	int data;                           
	Node *l, *r;                     
};

void Print(Node *&Tree,int k)           
{
	if (Tree != NULL)               
	{
		Print(Tree->r,k+1);
		for (int i = 1; i <= k; i++)
			cout << "   ";
		cout << Tree->data << endl;
		Print(Tree->l,k+1);
	}
}


void del(Node *&Tree){
	if (Tree != NULL)                
	{
		del(Tree->l);               
		del(Tree->r);               
		delete Tree;               
		Tree = NULL;                
	}

}

void Insert(int data, Node *&MyTree)
{
	if (NULL == MyTree)             
	{
		MyTree = new Node;          
		MyTree->data = data;
		MyTree->l = MyTree->r = NULL; 
		
	}

	if (data < MyTree->data)
	{
		if (MyTree->l != NULL) Insert(data, MyTree->l);
		else          
		{
			MyTree->l = new Node;                 
			MyTree->l->l = MyTree->l->r = NULL;   
			MyTree->l->data = data;
		}
	}

	if (data > MyTree->data)
	{
		if (MyTree->r != NULL) Insert(data, MyTree->r);
		else            
		{
			MyTree->r = new Node;                 
			MyTree->r->l = MyTree->r->r = NULL;   
			MyTree->r->data = data;
		}
	}
}

int find_item(int item, Node *&MyTree) 
{
	if (NULL == MyTree)             
	{
		return NULL; 
	}
	if (item == MyTree->data){
		return item;
	}
	if (item <= MyTree->data)
	{
		if (MyTree->l != NULL) find_item(item, MyTree->l); 
		else          
		{
			return NULL;
		}
	}
	else{
		if (MyTree->r)            
			return find_item(item, MyTree->r);
		
		else              
		{
			return NULL;
		}
	}
}
int interval_search(int a, int b, Node *&Tree)
{
	if (NULL == Tree)
	{
		return NULL;
	}
	
	if (Tree != NULL)
	{
		if ((a <= Tree->data) && (b >= Tree->data))
			cout << "  " << Tree->data << "  ";
		interval_search(a, b, Tree->l);
		interval_search(a, b, Tree->r);
	}
	
}

int main()
{
	int el = 0; int N = 0;
	cout << "Enter the number of items:";
	cin >> N;
	Node *Tree = NULL;                   
	for (int i = 0; i < N;i++){
		cin >> el;
		Insert(el, Tree);
	}
	Print(Tree,0);
	cout << '\n';
	int count_item = 0;
	cout << "Enter the number of items you want to find:";
	cin >> count_item;
	int item = 0;
	for (int i = 0; i < count_item; i++){
		cout << "Enter the item you want to find:";
		cin >> item;
		if (find_item(item, Tree) == item)
			cout << "item was fount!" << endl;
		else cout << "Sorry, item not found" << endl;
	}
	
	int a = 0; int b = 0;
	cout << "Enter the interval:";
	cin >> a; cin >> b;
	interval_search(a, b, Tree);

	del(Tree);                    
	_getch();
}

