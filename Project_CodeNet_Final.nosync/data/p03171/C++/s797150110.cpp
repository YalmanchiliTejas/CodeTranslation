#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define myPair pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define qmax priority_queue<int>
#define qmin priority_queue<int,vector<int>,greater<int>>
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

const int mxn = 3005;
int dp[mxn][mxn];
int c[mxn][mxn];
int n, a[mxn];

int f(int l,int r)
{
	if(c[l][r])
		return dp[l][r];
	if(l == r)
		dp[l][r] = a[l];
	else
		dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
	c[l][r] = 1;
	return dp[l][r];
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	FOR(i,1,n)
		cin >> a[i];
	memset(c,0,sizeof(c));
	cout << f(1,n);

	return 0;
}