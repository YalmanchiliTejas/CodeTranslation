#include<bits/stdc++.h>
#define int long long int  //comment for large arrays
#define pll pair<int,int>
#define dbl long double
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define eps 0.00000001
#define INF 10000000000000001
#define all(x) (x).begin(),(x).end()
#define LB(v,x) (lower_bound(all(v),x) - v.begin()) 
#define UB(v,x) (upper_bound(all(v),x) - v.begin())
#define size(x) (int)(x).size()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define popb() pop_back()
#define popf() pop_front()
#define mp(x,y) make_pair((x),(y))
#define vec(dt) vector<dt>
#define vv(dt) vector<vector<dt>>
#define fastio(x) ios_base::sync_with_stdio(x); cin.tie(NULL)
#define init(v,s) memset(v,s,sizeof(v)) 
#define bug(x) cerr<<"LINE: "<<__LINE__<<" || click to see test details "<<#x<<" = "<<x<<endl
#define loop(i,s,n) for(int i=s;i<n;i++)
#define print(v) for(auto it:v) cout<<it<<" "; cout<<endl 
using namespace std;




signed main()
{
	fastio(0);
	string s;
	cin>>s;
	int d;
	cin>>d;
	vec(int) v;
	v.pb(0);
	reverse(all(s));
	for(auto it:s) v.pb(it - '0');
	
	int dp[size(v)][d][2]; // dp[idx, sum%d, tight]
	init(dp,0);
	loop(i,0,10) dp[1][i%d][0] += 1;
	loop(i,0,v[1]+1) dp[1][i%d][1] += 1;

	loop(n,2,size(v))
	{
		loop(sum,0,d)
		{
			loop(i,0,10) dp[n][sum][0] = (dp[n][sum][0] + dp[n-1][(sum-i+ 10*d)%d][0])%mod;
			loop(i,0,v[n]+1) 
				if(i<v[n]) dp[n][sum][1] = (dp[n][sum][1] + dp[n-1][(sum-i+ 10*d)%d][0])%mod;
				else  dp[n][sum][1] = (dp[n][sum][1] + dp[n-1][(sum-i+ 10*d)%d][1])%mod;
		}
	}

	cout<<(dp[size(s)][0][1] - 1 + mod)%mod<<endl; // -1 to remove no. 000000000

	return 0;		
}
