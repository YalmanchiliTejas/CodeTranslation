#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define MOD 998244353ll
using namespace __gnu_pbds;
using namespace std;

int n,s,a[3010],dp[3010][3010];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s;j++){
			add(dp[i][j],dp[i-1][j]);
			if(j-a[i]>=0ll){
				add(dp[i][j],dp[i-1][j-a[i]]);
				if(j-a[i]==0ll) add(dp[i][j],i);
			}
		}
	}
	int sum=0ll;
	for(int i=1;i<=n;i++){
		add(sum,dp[i][s]);
	}
	cout<<sum<<endl;
	return 0;
}