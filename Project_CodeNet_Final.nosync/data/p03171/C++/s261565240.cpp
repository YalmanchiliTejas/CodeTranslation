#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod	%1000000007
#define FOR(I,N) for(I=0;I<N;++I)

int main()
{
	ll n,k,j,i,f;
	cin>>n;
	ll a[n];
	ll dp[n][n];
	FOR(i,n)
	{
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(k=1;k<n;++k)
	for(j=k;j<n;++j)
	{
		i=j-k;
		dp[i][j]= max((a[i]-dp[i+1][j]), (a[j]-dp[i][j-1]));
	}
	cout<<dp[0][n-1];
}