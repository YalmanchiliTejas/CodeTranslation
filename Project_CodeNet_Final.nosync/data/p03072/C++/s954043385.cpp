#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, aux, total = 0;
	cin >> n;
	
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	aux = h[0];
	
	for (int i = 0; i < n; i++) {
		if (h[i] >= aux) {
			total++;
			aux = h[i];
		}
	}
	
	cout << total;
	
	return 0;
}