
// Problem : S - Digit Sum
// Contest : Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_s
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define maxm 1e18
#define minm -1e18
#define pr pair<ll,ll>
#define mod 1000000007

void add_self(ll &a,ll b)
{
	a=(a+b)%mod;
}
 
void solve()
{
	ll d,i,digit,sm_already;
	string k;
	cin>>k>>d;
	ll len=k.length(),sum;
	vector< vector<ll> > dp(d,vector<ll> (2));
	//dp[sum][smaller_already] -> the number of ways
	//to choose digits so far such that sum of digits
	//modulo d is 'sum' and 'smaller_already' says whether
	//we already chosen some digit smaller than in k
	dp[0][0]=1;
	for(i=0;i<len;i++)
	{
		vector< vector<ll> > new_dp(d,vector<ll> (2));
		for(sum=0;sum<d;sum++)
		{
			for(sm_already=0;sm_already<2;sm_already++)
			{
				for(digit=0;digit<10;digit++)
				{
					if(!sm_already && (digit>k[i]-'0'))
						break;
					add_self(new_dp[(sum+digit)%d][sm_already || (digit<k[i]-'0')],dp[sum][sm_already]);
				}
			}
		}
		dp=new_dp;
	}
	ll ans=(dp[0][0]+dp[0][1]-1+mod)%mod;
	cout<<ans<<endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
