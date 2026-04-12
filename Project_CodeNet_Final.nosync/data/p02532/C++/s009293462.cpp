#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<char> xs[128];
	string s;
	cin.ignore(10, '\n');
	while (true) {
		cin >> s;
		if (s == "quit") break;
		if (s == "push") {
			int to; char v; cin >> to >> v;
			xs[to].push(v);
		} else if (s == "pop") {
			int from; cin >> from;
			cout << xs[from].top() << endl;
			xs[from].pop();
		} else if (s == "move") {
			int from, to; cin >> from >> to;
			xs[to].push(xs[from].top());
			xs[from].pop();
		}
	}
	return 0;
}