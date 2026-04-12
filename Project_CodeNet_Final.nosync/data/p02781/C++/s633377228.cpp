#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  105

string s;
ll k;
ll dp[105][105][2];
vector<int> v;

ll add(ll a,ll b,ll mod)
{
	return ((a%mod)+(b%mod))%mod;
}
ll sub(ll a,ll b,ll mod)
{
	return ((a%mod)+(b%mod)+mod)%mod;
}
ll mul(ll a,ll b,ll mod)
{
	return ((a%mod)*(b%mod))%mod;
}

ll rec(ll i, ll cnt, ll t){
	if(i==s.size()){
		if(cnt==k)
			return 1;
		return 0;
	}
	ll &res=dp[i][cnt][t];
	if(res!=-1)
		return res;
	int l=t?9:v[i];
	ll ans=0;
	for(int j=0; j<=l; j++){
		ll temp=cnt;
		if(j!=0)
			temp++;
		int temp2=t;
		if(j<v[i])
			temp2=1;
		ans+=rec(i+1,temp,temp2);
	}
	dp[i][cnt][t]=ans;
	return res=dp[i][cnt][t];
}

void solve()
{
	cin>>s;
	cin>>k;
	rep(i,0,s.size()){
		v.pb(s[i]-'0');
	}
	memset(dp,-1,sizeof dp);
	cout<<rec(0,0,0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	return 0;
}