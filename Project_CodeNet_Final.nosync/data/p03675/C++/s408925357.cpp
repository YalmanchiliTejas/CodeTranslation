#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i % 2) {
			dq.push_back(x);
		} else {
			dq.push_front(x);
		}
	}
	if (n % 2 == 0) {
		reverse(dq.begin(), dq.end());
	}
	bool first = true;
	while (!dq.empty()) {
		if (first) first = false;
		else cout << ' ';
		cout << dq.front(); dq.pop_front();
	}
}