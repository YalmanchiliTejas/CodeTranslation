#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long                           //del this if TLE or MLE
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fow(i,a,b,c) for(int i=a;i<=b;i+=c)
#define bck(i,a,b,c) for(int i=a;i>=b;i-=c)
#define F first
#define S second
#define loop int tests;cin>>tests;while(tests--)

const int N=3005;

int a[N];

int dp[N][N];

signed main()
{
	fastio;
	int n;
	cin>>n;
	fow(i,1,n,1)
	{
		cin>>a[i];
		dp[i][i]=a[i];
	}
	bck(l,n,1,1)
	{
		fow(r,l+1,n,1)
		{
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	}
	cout<<dp[1][n]<<"\n";
}

