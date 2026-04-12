#include<bits/stdc++.h>
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define endl '\n'
#define for(i,s,n) for(int i=s;i<n;i++)
#define vii vector<int>
int t = 1, n, OO = 1e14;
int dp[2][3001][3001];
vii v;
int solve(bool p = 0, int first = 0, int last = n - 1) {
	if (first > last) return 0;
	int& ret = dp[p][first][last];
	if (~ret) return ret;
	ret = -OO;
	int r1 = solve(!p, first, last - 1);
	int r2 = solve(!p, first + 1, last);
		ret = max({ ret,v[last] - r1,v[first] - r2 });
	
	return ret;
}
signed main()
{
	fast;

	//cin>>t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n;
		v = vii(n);
		for (i, 0, n) cin >> v[i];
		cout << solve() << endl;
	}
}
