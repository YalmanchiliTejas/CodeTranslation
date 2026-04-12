#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n; cin >> n;
	char a, b, t;
	queue<char> p;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		p.push(t);
		if (p.size() == 2) {
			a = p.front(); p.pop(); b = p.front(); p.pop();
			if (a == 'T' && b == 'F') p.push('F');
			else p.push('T');
		}
	}
	cout << p.front() << endl;

	return 0;
}
