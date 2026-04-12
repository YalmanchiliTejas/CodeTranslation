#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int dp[105][2][5];
//dp[place][tight][zeroes]
int32_t main()
{
	
	string s;cin>>s;
	int K=in();
	int n=s.size();
	dp[0][0][0]=1;
	
	for(int i=0;i<n;i++)
	{
		int D=s[i]-'0';
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<=K;k++)
			{
				int target=(j==1?9:D);
				for(int d=0;d<=target;d++)
				{
					int ct=0;
					if(d!=0)ct++;
					dp[i+1][j or (d<D)][k+ct]+=dp[i][j][k];
				}
			}
			
		}
	}
	
	cout<<dp[n][0][K]+dp[n][1][K];
	
	
}