#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(i=a;i<b;i++)
#define fr(i,a,b) for(i=a;i>=b;i--)
#define endl '\n'
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
using namespace std;

ll dp[3000][3000];
int a[3000];

ll solve(int l,int r,int ply)
{
	if(l==r)
		return a[l];
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(ply==0)
		return dp[l][r]=max(a[l]-solve(l+1,r,1),a[r]-solve(l,r-1,1));
	else if(ply==1)
		return dp[l][r]=max(a[l]-solve(l+1,r,0),a[r]-solve(l,r-1,0));
}

int main()
{
	int n,i,j;
	cin>>n;
	f(i,0,n)
		cin>>a[i];
	if(n==1)
	{
		cout<<a[0];
		return 0;
	}
	f(i,0,n)
		f(j,0,n)
			dp[i][j]=-1;
	solve(0,n-1,0);
	/*f(i,0,n)
	{
		f(j,0,n)
			cout<<dp[i][j]<<' ';
		cout<<endl;
	}*/
	cout<<dp[0][n-1];
}