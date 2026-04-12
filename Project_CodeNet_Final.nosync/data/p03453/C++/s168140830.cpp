#include <bits/stdc++.h>
#define MAX 1000005
#define ll long long
#define upperlimit 1000100
#define INF 1e18
#define eps 1e-8
#define endl '\n'
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define MOD 1000000007LL
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define vll vector<ll>
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define csl ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
ll gcd(ll n1,ll n2){
	if(n2==0)
		return n1;
	if(n1%n2==0)return n2;
	return gcd(n2,n1%n2);
}
ll powmod(ll base,ll exponent)
{
	if(exponent<0) exponent+=MOD-1;
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%MOD;
		base=(base*base)%MOD;
		exponent/=2;
	}
	return ans;
}
vector<pair<ll,ll>> v[MAX];
ll dist[MAX],dist2[MAX];
set<pair<ll,ll>> se;
ll dp[MAX],dp2[MAX];
pair<ll,ll> mkc[MAX],mkc2[MAX];
int main()
{
	csl;
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[a].pb(mp(b,c));
		v[b].pb(mp(a,c));
	}
	for(int i=1;i<=n;i++)
		sort(v[i].begin(), v[i].end());
	for(int i=1;i<=n;i++)
		dist[i]=1e14+1;
	dist[s]=0;
	se.insert(mp(dist[s],s));
	while(!se.empty())
	{
		ll x=se.begin()->FF,y=se.begin()->SS;
		se.erase(se.begin());
		for(auto i:v[y])
		{
			if(dist[i.FF]>dist[y]+i.SS)
			{
				se.erase(mp(dist[i.FF],i.FF));
				dist[i.FF]=dist[y]+i.SS;
				se.insert(mp(dist[i.FF],i.FF));
			}
		}
	}
	for(int i=1;i<=n;i++)
		dist2[i]=1e14+1;
	dist2[t]=0;
	se.insert(mp(dist2[t],t));
	while(!se.empty())
	{
		ll x=se.begin()->FF,y=se.begin()->SS;
		se.erase(se.begin());
		for(auto i:v[y])
		{
			if(dist2[i.FF]>dist2[y]+i.SS)
			{
				se.erase(mp(dist2[i.FF],i.FF));
				dist2[i.FF]=dist2[y]+i.SS;
				se.insert(mp(dist2[i.FF],i.FF));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		mkc[i]=mp(dist[i],i);
	}
	ll val=dist[t];
	sort(mkc+1,mkc+1+n);
	dp[s]=1;
	for(int i=2;i<=n;i++)
	{
		int x=mkc[i].SS;
		int last=-1;
		for(int j=0;j<v[x].size();j++)
		{
			if(dist[x]==dist[v[x][j].FF]+v[x][j].SS)
			{
				dp[x]+=dp[v[x][j].FF];
				dp[x]%=MOD;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		mkc2[i]=mp(dist2[i],i);
	}
	sort(mkc2+1,mkc2+1+n);
	dp2[t]=1;
	for(int i=2;i<=n;i++)
	{
		int x=mkc2[i].SS;
		int last=-1;
		for(int j=0;j<v[x].size();j++)
		{
			if(dist2[x]==dist2[v[x][j].FF]+v[x][j].SS)
			{
				dp2[x]+=dp2[v[x][j].FF];
				dp2[x]%=MOD;
			}
		}
	}
	assert(dp2[s]==dp[t]);
	ll x=dp[t]*dp[t];
	x%=MOD;
	//for(int i=1;i<=n;i++)
	//	cout<<dist[i]<<" "<<dist2[i]<<endl;
	for(int i=1;i<=n;i++)
		if(dist[i]==dist2[i]&&2*dist[i]==val)
		{
			//cout<<i<<endl;
			ll temp=dp[i]*dp[i];
			temp%=MOD;
			temp*=dp2[i];
			temp%=MOD;
			temp*=dp2[i];
			temp%=MOD;
			x=x-temp+MOD;
			x%=MOD;
			//x+=(MOD-(dp[i]*dp[i])%MOD)*((dp2[i]*dp2[i])%MOD);
			x%=MOD;
		}
	for(int i=1;i<=n;i++)
		for(auto j:v[i])
		{
			//cout<<i<<" "<<j.FF<<endl;
			//cout<<(dist[j.FF])<<" "<<(dist2[i])<<" "<<(dist2[i]+dist[j.FF]+j.SS)<<endl;
			if(2*dist[i]<val&&2*dist2[j.FF]<val&&dist[i]+dist2[j.FF]+j.SS==val)
			{
				ll temp=dp[i]*dp[i];
				temp%=MOD;
				temp*=dp2[j.FF];
				temp%=MOD;
				temp*=dp2[j.FF];
				temp%=MOD;
				x=x-temp+MOD;
				x%=MOD;
				//x+=(MOD-(dp[i]*dp[i])%MOD)*((dp2[j.FF]*dp2[j.FF])%MOD);
				x%=MOD;
			}
		}
	cout<<x<<endl;
}