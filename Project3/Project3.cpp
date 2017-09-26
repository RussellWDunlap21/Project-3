//Rusell Dunlap
//Dr. Woodcock
//COSC-3351-110
//T/Th 2:30

#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
//Makeing the linked list
struct node
{
	int data;
	node *next;
}*front = NULL, *rear = NULL, *pointer = NULL, *nullpointer = NULL;
//Push numbers into the queue
void push(int x)
{
	nullpointer = new node;
	nullpointer->data = x;
	nullpointer->next = NULL;
	if (front == NULL)
	{
		front = rear = nullpointer;
		rear->next = NULL;
	}
	else
	{
		rear->next = nullpointer;
		rear = nullpointer;
		rear->next = NULL;
	}
}
//Remove number from queue
int remove()
{
	int number;
	if (front == NULL)
	{
		cout << "empty queue\n";
	}
	else
	{
		cout << "Which value do you want to delete from the list: ";
		cin >> number;
		node *prev = front;
		node *current = front->next;

		while (current)
		{
			if (current->data == number) {
				prev->next = current->next;
				delete current;
				return(number);
			}
			prev = current;
			current = current->next;
		}
		if (!current) {
			cout << "That value is not in the list." << endl;
		}
	}
}
//Main GUI
int main()
{
	int number = 0;
	cout << "Enter the value to be entered into queue (or -1 to delete): ";
	cin >> number;
	while(number != -1)
	{
		cout << "Enter the value to be entered into queue (or -1 to delete): ";
		cin >> number;
		push(number);
	}

	if (front != NULL)
		cout << remove() << endl;

	_getch();
}