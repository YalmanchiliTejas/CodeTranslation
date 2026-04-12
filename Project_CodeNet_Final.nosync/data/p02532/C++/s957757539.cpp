#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> st[101];
	string s;
	int n, p, p1, p2;
	char c;
	cin >> n;
	while (cin >> s) {
		if (s == "quit") {
			break;
		} else if (s == "push") {
			cin >> p >> c;
			st[p].push(c);
		} else if (s == "pop") {
			cin >> p;
			cout << st[p].top() << endl;
			st[p].pop();
		} else if (s == "move") {
			cin >> p1 >> p2;
			st[p2].push(st[p1].top());
			st[p1].pop();
		}
	}
}