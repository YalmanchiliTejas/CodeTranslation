#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

signed main() {
	int n; string s; int k; cin >> n >> s >> k;
	k--;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[k])s[i] = '*';
	}

	cout << s << endl;
}