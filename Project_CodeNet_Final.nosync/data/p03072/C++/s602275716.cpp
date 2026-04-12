#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, out = 1;
	cin >> n;

	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(h[j] > h[i]) {
				break;
			}
			if(j == i - 1) {
				out++;
			}
		}
	}

	cout << out << endl;

	return 0;
}
