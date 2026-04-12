#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	int n, a;
	cin >> n;

	deque<int> b;
	int which = n % 2;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if ((which + i) % 2 == 0) {
			b.emplace_back(a);
		} else {
			b.emplace_front(a);
		}
	}

	cout << b[0];
	for (int i = 1; i < n; i++) {
		cout << " " << b[i];
	}
	cout << endl;
	return 0;
}
