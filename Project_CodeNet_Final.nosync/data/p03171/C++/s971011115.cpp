// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define mp make_pair
#define pi pair<int,int>
#define pl pair<long long int,long long int>
#define pb push_back
#define fi first
#define se second
#define len(a) (int)(a).length()
#define sz(a) (int)(a).size()

using namespace std;

ll n, a[3000], dp[3000][3000][2];

int main ()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int d=1; d<n; ++d) {
		for (int i=0; i+d<n; ++i) {
			dp[i][i+d][0] = max(a[i] + dp[i+1][i+d][1], a[i+d] + dp[i][i+d-1][1]);
			dp[i][i+d][1] = min(-a[i] + dp[i+1][i+d][0], -a[i+d] + dp[i][i+d-1][0]);
		}
	}
	cout << dp[0][n-1][0] << endl;
	return 0;
}
