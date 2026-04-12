//https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>
#define ALL(e) e.begin(), e.end()
#define RALL(e) e.rbegin(), e.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define dbg(x) (cerr << #x << ":" << x)
#define mid (l + r) / 2
#define fi first
#define sc second
#define N 1000000009

using namespace std;

typedef long long int lli;

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector <lli> ar(n);
	for(int i=0; i<n; i++) cin >> ar[i];

	lli dp[n+5][n+5];

	memset(dp, 0, sizeof dp);

	for(int l=n-1; l>=0; l--){
		for(int r=l; r<n; r++){
			dp[l][r] = max(ar[l] - dp[l+1][r], ar[r] - dp[l][r-1]);
		}
	}

	cout << dp[0][n-1];

	return 0;
}