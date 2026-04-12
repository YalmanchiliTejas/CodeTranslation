#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int a[222222], b[222222];
int main() {
	int n, q;
	cin >> n;
	rep(i, n)cin >> a[i];
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		cout << lower_bound(a, a + n, k) - a << endl;
	}
	return 0;
}
