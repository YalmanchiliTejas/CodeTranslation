#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(void){
	string cmd;
	stack<char> st[101];
	char c;
	int n, m;
	cin >> n;
	while(1){
		cin >> cmd;
		if(cmd == "quit")
			break;
		if(cmd == "push"){
			cin >> n;
			cin >> c;
			st[n].push(c);
		}
		if(cmd == "pop"){
			cin >> n;
			cout << st[n].top() << endl;
			st[n].pop();
		}
		if(cmd == "move"){
			cin >> n >> m;
			st[m].push(st[n].top());
			st[n].pop();
		}
	}
	return 0;
}