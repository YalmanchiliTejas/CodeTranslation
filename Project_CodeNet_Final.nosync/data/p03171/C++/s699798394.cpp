#include <bits/stdc++.h>
#define int long long
#define ld long double
#define fio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 1000000007
#define nl '\n'
#define pb push_back
#define mp make_pair

using namespace std;
const int N = 3005;
int dp[N][N];
int used[N][N];
int a[N];
int solve(int l,int r)
{
	if(l>r)
		return 0;
	if(used[l][r])
		return dp[l][r];
	used[l][r]=1;
	int res=LLONG_MIN;
	res=max(res,a[l]-solve(l+1,r));
	res=max(res,a[r]-solve(l,r-1));
	dp[l][r]=res;
	return res;
}
int32_t main()
{
	fio();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	solve(0,n-1);
	cout<<dp[0][n-1];
}

