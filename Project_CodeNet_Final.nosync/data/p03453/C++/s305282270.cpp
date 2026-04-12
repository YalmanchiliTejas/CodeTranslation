#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 3e17
#define mod 1000000007
#define abs(x) ((x)>=0?(x):-(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
void read(ll &x)
{
	scanf("%lld",&x);
}
void read(ll &x, ll &y)
{
	scanf("%lld%lld",&x,&y);
}
void read(ll &x, ll &y, ll &z)
{
	scanf("%lld%lld%lld",&x,&y,&z);
}
void print(ll x)
{
	printf("%lld ",x);
}
void println(ll x)
{
	printf("%lld\n",x);
}
const ll N=200000;
ll n,m,s,t,x,y,z,w[N+10],d1[N+10],cnt1[N+10],d2[N+10],cnt2[N+10],ans,len;
vector<ll>v[N+10],c[N+10];
priority_queue<pair<ll,ll> >q;
int main()
{
	//freopen("c.cpp","r",stdin);
 
	cin>>n>>m>>s>>t;
	for(ll i=1;i<=m;i++)
		read(x,y,z),v[x].pb(y),v[y].pb(x),c[x].pb(z),c[y].pb(z);
	for(ll i=1;i<=n;i++)
		d1[i]=d2[i]=INF;
	d1[s]=d2[t]=0;
	cnt1[s]=cnt2[t]=1;
	q.push({0,s});
	for(;!q.empty();)
	{
		x=q.top().se;
		q.pop();
		if(w[x])
			continue;
		w[x]=1;
		for(ll i=0;i<v[x].size();i++)
		{
			ll to=v[x][i],dist=c[x][i];
			if(d1[to]>d1[x]+dist)
				d1[to]=d1[x]+dist,cnt1[to]=cnt1[x],q.push({-d1[to],to});
			else if(d1[to]==d1[x]+dist)
				cnt1[to]+=cnt1[x],cnt1[to]%=mod;
		}
	}
	for(ll i=1;i<=n;i++)
		w[i]=0;
	q.push({0,t});
	for(;!q.empty();)
	{
		x=q.top().se;
		q.pop();
		if(w[x])
			continue;
		w[x]=1;
		for(ll i=0;i<v[x].size();i++)
		{
			ll to=v[x][i],dist=c[x][i];
			if(d2[to]>d2[x]+dist)
				d2[to]=d2[x]+dist,cnt2[to]=cnt2[x],q.push({-d2[to],to});
			else if(d2[to]==d2[x]+dist)
				cnt2[to]+=cnt2[x],cnt2[to]%=mod;
		}
	}
	ans=cnt1[t]*cnt1[t]%mod;
	len=d1[t];
	if(len==INF)
	{
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++)
		if(len==d1[i]*2)
		{
			ans-=cnt1[i]*cnt2[i]%mod*cnt1[i]%mod*cnt2[i]%mod;
			while(ans<0)
				ans+=mod;
			while(ans>=mod)
				ans-=mod;
		}
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<v[i].size();j++)
		{
			ll to=v[i][j],dist=c[i][j];
			if(d1[i]+d2[to]+dist==len&&d1[i]<(len+1)/2&&d2[to]<(len+1)/2)
			{
				ans-=cnt1[i]*cnt2[to]%mod*cnt1[i]%mod*cnt2[to]%mod;
				while(ans<0)
					ans+=mod;
				while(ans>=mod)
					ans-=mod;
			}
		}
	cout<<ans;
}