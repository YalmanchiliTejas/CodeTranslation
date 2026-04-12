#include <bits/stdc++.h>
using namespace std;

deque<int> deq;
int n, k;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if ((n - i) % 2) {
			deq.push_front(k);
		} else {
			deq.push_back(k);
		}
	}
	for (int i : deq) {
		cout << i << " ";
	}
}