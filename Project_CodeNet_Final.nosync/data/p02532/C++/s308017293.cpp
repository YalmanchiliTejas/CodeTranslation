#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

vector<stack<char> > blocks;

void push(int p, char c){
	blocks[p - 1].push(c);
}

void pop(int p){
	cout << blocks[p - 1].top() << endl;
	blocks[p - 1].pop();
}

void move(int p1, int p2){
	blocks[p2 - 1].push(blocks[p1 - 1].top());
	blocks[p1 - 1].pop();
}

int main(){
	int n, p1, p2;
	char c;
	string command;
	cin >> n;


	for (int i = 0; i < n; ++i)
		blocks.push_back(stack<char>());

	while (true){
		cin >> command;
		if (command == "quit")
			break;
		else if (command == "push"){
			cin >> p1 >> c;
			push(p1, c);
		}
		else if (command == "pop"){
			cin >> p1;
			pop(p1);
		}
		else if(command == "move"){
			cin >> p1 >> p2;
			move(p1, p2);
		}
	}
	return 0;
}