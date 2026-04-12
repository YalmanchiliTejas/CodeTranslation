#include <bits/stdc++.h>

#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define vin(v,n) copy_n(istream_iterator<int>(cin),n,back_inserter(v));
#define all(v) v.begin(),v.end()
#define INF 2000000000
#define MOD 1000000007
#define ll long long 
#define vi vector<int>
#define ii pair<int,int>
#define si set<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define f1(i,a,b) for(int i = a;i<b;i++)
#define f2(i,a,b) for(int i = a;i<=b;i++)

using namespace std;

const int N = 3005;
int dp[N-1][N-1][2];
vi a;

int solve(int l, int r, int turn)
{
	if(r<l)
		return 0;
	if(dp[l][r][turn]!=-1)
		return dp[l][r][turn];

	if(turn==1)
		dp[l][r][1] = max(a[l]+solve(l+1,r,0), a[r]+solve(l,r-1,0));
	else
		dp[l][r][0] = min(-a[l]+solve(l+1,r,1), -a[r]+solve(l,r-1,1));
	
	return dp[l][r][turn];
	
}

int32_t main() 
{
	IOS;
	int n;
	cin >> n;
	vin(a,n);
	f1(i,0,n) f1(j,0,n) dp[i][j][0] = -1, dp[i][j][1] = -1;

	cout << solve(0,n-1,1);
}
