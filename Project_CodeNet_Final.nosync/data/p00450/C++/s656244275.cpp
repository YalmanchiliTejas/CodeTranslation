#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> P;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		stack<P> stk;
		int c;
		for (int i = 0; i < n; i++) {
			cin >> c;
			if (i % 2 == 0) {
				if (stk.empty()) {
					stk.push(P(c, 1));
				} else {
					P p = stk.top();
					stk.pop();
					if (p.first == c) {
						stk.push(P(p.first, p.second+1));
					} else {
						stk.push(p);
						stk.push(P(c, 1));
					}
				}
			} else {
				P p = stk.top();
				stk.pop();
				if (p.first == c) {
					stk.push(P(p.first, p.second+1));
				} else {
					if (!stk.empty()) {
						P pp = stk.top();
						stk.pop();
						stk.push(P(pp.first, pp.second+p.second+1));
					} else {
						stk.push(P(c, p.second+1));
					}
				}
			}
		}
		int cc = 0;
		while (!stk.empty()) {
			P p = stk.top();
			stk.pop();
			if (p.first == 0) {
				cc += p.second;
			}
		}
		cout << cc << endl;
	}
	return 0;
}