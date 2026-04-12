#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
int n;
signed main() {
	cin >> n;
	rep(i, (1 << n)) {
		vector<int>v;
		rep(j, n) {
			if ((i >> j) & 1)v.push_back(j);
		}
		if (i == 0)puts("0:");
		else {
			cout << i << ":";
			for (int x : v)cout << " " << x;
			cout << endl;
		}
	}
	return 0;
}
