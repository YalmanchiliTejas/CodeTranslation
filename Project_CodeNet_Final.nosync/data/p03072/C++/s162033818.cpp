#include<bits/stdc++.h>
using namespace std;
int n, h[110], tot;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int m = h[1];
	for (int i = 1; i <= n; i++) {
		if (h[i] >= m) {
			m = h[i];
			tot++;
		}
	}
	cout << tot << endl;
	return 0;
}