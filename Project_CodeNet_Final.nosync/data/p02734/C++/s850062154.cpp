//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3010;
const int INF = 2e9;
const int mod = 998244353;

int n,ans,s,a[MAXN];
int l[MAXN];

signed main () {
	cin >> n >> s;
	for(register int i = 1;i <= n; ++i) 
		cin >> a[i];
	l[a[1]] = 1;
	for(register int i = 2;i <= n; ++i) {
		for(register int p = s - a[i];p >= 1; --p)
			if(l[p]) (l[p + a[i]] += l[p]) %= mod;
		(l[a[i]] += i) %= mod;
		if(l[s]) (ans += l[s]) %= mod;
	}
	cout << ans << endl;
	return 0;
}
