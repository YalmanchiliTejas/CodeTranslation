#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int main() {
	int n;
	cin >> n;
	
	multiset<int> tails;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		auto it = tails.lower_bound(a);
		if (it == tails.begin()) {
			tails.insert(a);
		} else {
			it--;
			if (*it < a) {
				tails.erase(it);
				tails.insert(a);
			} else
				tails.insert(a);
		}
	}
	cout << tails.size();
}

