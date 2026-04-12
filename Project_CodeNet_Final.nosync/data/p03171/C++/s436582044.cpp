#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second
#define mod 1000000007
#define lim 100005
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
	int i,j,d,l,r,n,a[3001]; ll dp[3001][3001] = {};
	cin>>n;
	for(i=1; i<=n; i++) cin>>a[i];
	for(i=1; i<=n; i++) dp[i][i] = ((n&1)?1:-1)*a[i];
	for(d=1; d<n; d++)
		for(i=1; i<=n-d; i++){
			j = i + d; int mult = (((n-(d+1))&1)?-1:1);
			if(mult == -1) dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j]);
			else dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j]);
		}

	cout<<dp[1][n];
}