#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0, h, max = 0; i < n; i++) {
		cin >> h;
		if (h >= max) {
			count++;
			max = h;
		}
	}
	cout << count << endl;
}

