#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h.at(i);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < i; j++) {
			if (h.at(i) - h.at(j) >= 0)s++;
		}
		if (s == i)cnt++;
	}
	cout << cnt << endl;
}