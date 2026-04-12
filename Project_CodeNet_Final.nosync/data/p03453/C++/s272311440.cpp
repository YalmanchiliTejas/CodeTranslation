#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <complex>
#include <iomanip>
#include <stack>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
ll mod=1e9+7;
double eps=1e-7;
ll exp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=(x*x)%mod){if(y&1)ret=(ret*x)%mod;}return ret;}
ull pexp(ull x,ull y){if(y<0) return 0; ull ret=1; for(;y;y>>=1,x=(x*x)){if(y&1)ret=(ret*x);}return ret;}
ll gcd(ll x,ll y){if(!x||!y) return x+y; return x%y==0?y:gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll bsum(ll u,ll b){ll ret=0;if(u<b)return u;while(u){ret+=u%b;u/=b;}return ret;}
ll prival(ll u,ll p){ll cn=0;while(u%p==0){cn++;u=u/p;}return cn;}
ll minv(ll a,ll b){return 1<a?b-minv(b%a,a)*b/a:1;}
ll extm(ll a,ll b){ll ret=0;while(a!=0){if(a%2==1){ret+=b;ret%=mod;}a>>=1;b=(2*b)%mod;}return ret;}
ll eaphi(ll x){ll t=x,ret=x,i;for(i=2;i*i<=x;i++){if(t%i==0){ret-=ret/i;while(t%i==0) t/=i;}}if(t!=1) ret-=ret/t;return ret;}
ll eadivc(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=2;if(x%i==0 && i*i==x) ret+=1;}return ret;}
ll eadivs(ll x){ll ret=0;ll i;for(i=1;i*i<=x;i++){if(x%i==0 && i*i!=x) ret+=i+x/i;if(x%i==0 && i*i==x) ret+=i;}return ret;}
ll ndig(ll x, ll b){ll ret=0;while(x){x/=b; ret++;}return ret;}
ll rev(ll n, ll b){ll ret=0;while(n){ret=b*ret+n%b; n/=b;}return ret;}
ll sq(ll x){ll t=(ll)sqrt(x); for(ll i=t-2 ; i<=t+2 ; i++) if(i*i==x) return abs(i); return -1;}
ll extexp(ll x,ll y){if(y<0) return 0; ll ret=1;for(;y;y>>=1,x=extm(x,x)){if(y&1)ret=extm(ret,x);}return ret;}
bool isprime(ll x){if(x<=1) return false; for(ll i=2;i*i<=x;i++){if(x%i==0){return false;}}return true;}
ll n, m, ans, s, t, inf=1e18;
ll count_s[111111];
ll dist_s[111111];
pair<ll, ll> vertex_s[111111];
ll count_t[111111];
ll dist_t[111111];
pair<ll, ll> vertex_t[111111];
vector< pair<ll, int> > edge[111111];
priority_queue< pair<ll, int> > PQ;

void finale_1(void)
{
	int i, j;
	for(i=1 ; i<=n ; i++) vertex_s[i]=make_pair(dist_s[i],i);
	sort(vertex_s+1,vertex_s+n+1); count_s[s]=1;
	for(i=1 ; i<=n ; i++)
	{
		int cur_vertex=vertex_s[i].second;
		for(j=0 ; j<edge[cur_vertex].size() ; j++)
		{
			int prv=edge[cur_vertex][j].second;
			ll val=edge[cur_vertex][j].first;
			if(dist_s[prv]+val==dist_s[cur_vertex])
				count_s[cur_vertex]+=count_s[prv];
		}
		count_s[cur_vertex]%=mod;
	}
}

void dijkstra_1(void)
{
	dist_s[s]=0; int i;
	for(i=1 ; i<=n ; i++) if(i!=s) dist_s[i]=inf;
	PQ.push(make_pair(0,s));
	while(!PQ.empty())
	{
		pair<ll, int> CUR=PQ.top(); PQ.pop();
		ll cdist=-CUR.first; int cloc=CUR.second;
		if(dist_s[cloc]<cdist) continue;
		for(i=0 ; i<edge[cloc].size() ; i++)
		{
			ll ndist=cdist+edge[cloc][i].first;
			int nloc=edge[cloc][i].second;
			if(dist_s[nloc]>ndist)
			{
				dist_s[nloc]=ndist;
				PQ.push(make_pair(-ndist,nloc));
			}
		}
	}
}

void finale_2(void)
{
	int i, j;
	for(i=1 ; i<=n ; i++) vertex_t[i]=make_pair(dist_t[i],i);
	sort(vertex_t+1,vertex_t+n+1); count_t[t]=1;
	for(i=1 ; i<=n ; i++)
	{
		int cur_vertex=vertex_t[i].second;
		for(j=0 ; j<edge[cur_vertex].size() ; j++)
		{
			int prv=edge[cur_vertex][j].second;
			ll val=edge[cur_vertex][j].first;
			if(dist_t[prv]+val==dist_t[cur_vertex])
				count_t[cur_vertex]+=count_t[prv];
		}
		count_t[cur_vertex]%=mod;
	}
}

void dijkstra_2(void)
{
	dist_t[t]=0; int i;
	for(i=1 ; i<=n ; i++) if(i!=t) dist_t[i]=inf;
	PQ.push(make_pair(0,t));
	while(!PQ.empty())
	{
		pair<ll, int> CUR=PQ.top(); PQ.pop();
		ll cdist=-CUR.first; int cloc=CUR.second;
		if(dist_t[cloc]<cdist) continue;
		for(i=0 ; i<edge[cloc].size() ; i++)
		{
			ll ndist=cdist+edge[cloc][i].first;
			int nloc=edge[cloc][i].second;
			if(dist_t[nloc]>ndist)
			{
				dist_t[nloc]=ndist;
				PQ.push(make_pair(-ndist,nloc));
			}
		}
	}
}

ll vertex_meet(int v)
{
	if(dist_s[v]+dist_t[v]!=dist_s[t] || dist_s[v]!=dist_t[v]) return 0;
	ll ret=(count_s[v]*count_t[v])%mod; return (ret*ret)%mod;
}

ll edge_meet(int v_1, int v_2, ll L)
{
	if(dist_s[v_1]+L!=dist_s[v_2]) return 0;
	if(dist_s[v_1]+dist_t[v_1]!=dist_s[t]) return 0;
	if(dist_t[v_2]+L!=dist_t[v_1]) return 0;
	if(dist_t[v_2]+dist_s[v_2]!=dist_t[s]) return 0;
	ll ret=(count_s[v_1]*count_t[v_2])%mod;
	if(dist_s[v_1]*2<dist_s[t] && dist_t[v_2]*2<dist_t[s] && dist_s[v_1]+L+dist_t[v_2]==dist_t[s])
		return (ret*ret)%mod;
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll i, j, u, v, w; cin>>n>>m>>s>>t;
	for(i=1 ; i<=m ; i++)
	{
		cin>>u>>v>>w;
		edge[u].push_back(make_pair(w,v));
		edge[v].push_back(make_pair(w,u));
	}
	dijkstra_1(); dijkstra_2(); finale_1(); finale_2();
	ans=(count_s[t]*count_t[s])%mod;
	for(i=1 ; i<=n ; i++) ans+=(mod-vertex_meet(i));
	for(i=1 ; i<=n ; i++)
		for(j=0 ; j<edge[i].size() ; j++)
			ans+=(mod-edge_meet(i,edge[i][j].second,edge[i][j].first));
	cout<<ans%mod; return 0;
}
