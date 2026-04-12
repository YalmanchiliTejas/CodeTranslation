/*	
*  Sachin Mittal
*/
#include<bits/stdc++.h>
#define int long long
#define M 998244353
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,j,n) for(int i=j;i<n;i++)
#define F first
#define S second
#define lb lower_bound
#define mem0(dp) memset(dp,0,sizeof(dp))
#define mem1(dp) memset(dp,-1,sizeof(dp))
#define pb push_back
#define sz(s) (int)(s.size())
#define debug(x) cout << #x << " = " << x << '\n';
using namespace std;

void solve()
{
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	if(!n%2)
	{
		int sm1=0,sm2=0;
		rep(i,0,n){if(i%2)sm1+=a[i];else sm2+=a[i];}
		cout<<max(sm1,sm2);
	}
	else 
	{
		unordered_map<int,int> dp[n];
		dp[0][0]=0;
		dp[0][1]=a[0];
		dp[1][0]=0;
		dp[1][1]=a[1];
		int ans=-1e18;
		for(int i=2;i<n;i++)
		{
			for(auto j:dp[i-2])
				if(j.F+1>=(i-1)/2)
				dp[i][j.F+1]=j.S+a[i];
			if(i!=2)
			{
				for(auto j:dp[i-3])
				{
					if(j.F+1>=(i-1)/2)
					{if(dp[i].count(j.F+1))
											dp[i][j.F+1]=max(dp[i][j.F+1],j.S+a[i]);
										else dp[i][j.F+1]=j.S+a[i];}
				}
			}
			for(auto j:dp[i])
				if(j.F==n/2)ans=max(ans,j.S);
		}
		if(n==2)
			ans=max(a[0],a[1]);
		else if(n==3)
			ans=max(a[0],max(a[1],a[2]));
		cout<<ans;
	}
	
}

int32_t main(){

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int t=1;
//cin>>t;
while(t--)
{
	solve();
}
}
