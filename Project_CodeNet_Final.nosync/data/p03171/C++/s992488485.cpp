#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair

int solveGame(int a[],vector<vector<int>> &dp,int i,int j,int n)
{
	if(i>j) return 0;
	if(i==j) return dp[i][i]=a[i];
	else if(dp[i][j]!=-1) return dp[i][j];
	else
	{
		int x=a[i]+min(solveGame(a,dp,i+1,j-1,n),solveGame(a,dp,i+2,j,n));
		int y=a[j]+min(solveGame(a,dp,i+1,j-1,n),solveGame(a,dp,i,j-2,n));
		return dp[i][j]=max(x,y);
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(n));
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++) dp[i][j]=-1;
    }
    k=solveGame(a,dp,0,n-1,n);
    int sum=0;
    for(i=0;i<n;i++) sum+=a[i];
    cout<<k-(sum-k)<<endl;
	return 0;
}
