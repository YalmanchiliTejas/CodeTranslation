#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct node {
	char color;
	node* prev;
	node* next;
} node;

typedef struct list {
	node* first;
	node* last;
} list;

int main()
{
	int n;
	cin >> n;
	list* blocks = new list[n];
	node* pNew;
	for (int i = 0; i < n; i++) {
		blocks[i].first = NULL;
		blocks[i].last = NULL;
	}
	string order;
	for (cin >> order; order != "quit"; cin >> order) {
		if (order == "push") {
			int num;
			char c;
			cin >> num >> c;
			pNew = new node;
			pNew->color = c;
			pNew->next = NULL;
			if (blocks[num - 1].first == NULL) {
				pNew->prev = NULL;
				blocks[num - 1].first = pNew;
				blocks[num - 1].last = pNew;
			}
			else {
				pNew->prev = blocks[num - 1].last;
				blocks[num - 1].last->next = pNew;
				blocks[num - 1].last = pNew;
			}
		}
		else if (order == "pop") {
			int num;
			cin >> num;
			cout << blocks[num - 1].last->color << endl;
			if (blocks[num - 1].first == blocks[num - 1].last) {
				pNew = blocks[num - 1].last;
				blocks[num - 1].first = NULL;
				blocks[num - 1].last = NULL;
			}
			else {
				pNew = blocks[num - 1].last;
				pNew->prev->next = NULL;
				blocks[num - 1].last = pNew->prev;
			}
			delete pNew;
		}
		else {
			int num1, num2;
			cin >> num1 >> num2;
			pNew = blocks[num1 - 1].last;
			if (blocks[num1 - 1].first == blocks[num1 - 1].last) {
				blocks[num1 - 1].first = NULL;
				blocks[num1 - 1].last = NULL;
			}
			else {
				blocks[num1 - 1].last->prev->next = NULL;
				blocks[num1 - 1].last = blocks[num1 - 1].last->prev;
			}
			if (blocks[num2 - 1].first == NULL) {
				blocks[num2 - 1].first = pNew;
				blocks[num2 - 1].last = pNew;
				pNew->prev = NULL;
				pNew->next = NULL;
			}
			else {
				blocks[num2 - 1].last->next = pNew;
				pNew->prev = blocks[num2 - 1].last;
				pNew->next = NULL;
				blocks[num2 - 1].last = pNew;
			}
		}
	}
	return 0;
}