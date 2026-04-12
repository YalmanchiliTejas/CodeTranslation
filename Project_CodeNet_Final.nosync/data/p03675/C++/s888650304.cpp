#include <bits/stdc++.h>
using namespace std;

int b[200010];

int f(int d, int n) {
	int ans = 2*d+2*n+1;
	if(n%2)	ans -= (2*d-1);
	else	ans += (2*d-1);
	return ans/4;
}

int main() {
	int i, j, n;
	// freopen("in.txt", "r", stdin);
	cin >> n;
	for(i = 1; i <=n; ++i) {
		int x;
		cin >> x;
		int z = f(i, n-i+1);
		// cout << z << endl;
		b[z] = x;
	}
	for(i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}