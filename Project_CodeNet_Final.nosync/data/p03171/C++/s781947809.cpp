#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define F first
#define S second
#define MEM(a,b) memset(a,b,sizeof a)
#define Tie ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n,a[3010],dp[3010][3010];

int main()
{Tie
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],dp[i][0]=(n&1?1:-1)*a[i];
	for(int i=1;i<n;i++)
		for(int j=0;j+i<n;j++)
		{
			if((i+(n&1?0:1))&1)
				dp[j][i]=min(dp[j][i-1]-a[j+i],dp[j+1][i-1]-a[j]);
			else
				dp[j][i]=max(dp[j][i-1]+a[j+i],dp[j+1][i-1]+a[j]);
		}
	cout <<dp[0][n-1]<<'\n'; 
}