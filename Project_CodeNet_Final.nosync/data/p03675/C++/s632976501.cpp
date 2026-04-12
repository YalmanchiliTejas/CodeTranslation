#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> d;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i % 2 == 0)
			d.push_back(x);
		else
			d.push_front(x);
	}
	if (n % 2 == 1) 
		reverse(begin(d), end(d));
	for (int i = 0; i < n; i++) {
		cout << d[i] << ' ';
	}
	return 0;
}