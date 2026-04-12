#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pb push_back
#define pp pair<int,int>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define int long long
 main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt.txt","r",stdin);
	// freopen("output.txt.txt","w",stdout);
	// #endif
	int n;
	cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	int dp[n][n],dp2[n][n];
	rep(len,1,n+1)
	{
		rep(st,0,n-len+1)
		{
			int en = st+len-1;
			dp[st][en] = 0;
			if(st==en)
			{
				dp[st][en] = a[st];
				dp2[st][en] = 0;
				continue;
			}

			dp[st][en] = max(dp2[st+1][en]+a[st],dp[st][en]);
			dp[st][en] = max(dp2[st][en-1]+a[en],dp[st][en]);
			dp2[st][en] = min(dp[st][en-1],dp[st+1][en]);

		}
	}
	cout<<2*dp[0][n-1]-accumulate(all(a),0ll)<<endl;
 
}