//                             In The Name Of Allah
#include <bits/stdc++.h>
#define	ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std; 
 
const int N = 10000, OO = 1e9 + 7, T = 410, M = 998244353, P = 6151, SQ = 800, lg = 32;
typedef pair <int, int> pii;
int dp[N], a[N];

int32_t main() {
	use_fast;
	int n, s;
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = s; j > a[i]; j--) 
			dp[j] = (dp[j] + dp[j - a[i]]) % M;
		dp[a[i]] = (dp[a[i]] + (i + 1)) % M;
		ans = (ans + dp[s]) % M;
	}
	cout << ans << endl;
	return 0; 
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/