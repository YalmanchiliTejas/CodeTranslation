#include<bits/stdc++.h>
#define up(j,k,i) for(ll i=j;i<k;i++)
#define down(j,k,i) for(ll i=j;i>k;i--)
#define M 1000000007
#define pp(n) printf("%lld\n",ll(n))
#define ps(n) printf("%lld ",ll(n))
#define pd(x,y) printf("%lld %lld\n",ll(x),ll(y))
#define is(n) scanf("%lld",&n)
#define inf LLONG_MAX
#define id(n,m) scanf("%lld%lld",&n,&m)
#define it(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define ss(s) scanf("%s",s)
#define cool 0
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pll pair<ll,ll> 
#define db cout<<"######\n"
#define null(a) memset(a,0,sizeof(a))
#define neg(a) memset(a,255,sizeof(a))
typedef long double ld;
typedef long long int ll;
using namespace std;
ll i,j,k,z,t,n,m,sum,ans,x,y,maxm=0,minm=inf; bool flag;
set<ll> lev[100005];
vector<ll> v[100005];
ll par[100005];
void dfs(ll x,ll level,ll parent)
{
	par[x]=parent;
	
	for(auto c:v[x])
	if(c!=parent)
	dfs(c,level+1,x);
	
	lev[level].insert(x);
}
int main()
{
	is(n);
	
	up(0,n-1,i)
	{
		id(x,y);
		v[x].pb(y);
		v[y].pb(x);
	}
	
	dfs(1,1,0);
	
	down(n,0,i)
	{
		for(auto c:lev[i])
		{
			x=par[c];
			
			auto it=lev[i-1].find(x);
			
			if(it==lev[i-1].end())
			{
				puts("First");
				return 0;
			}
			else
			lev[i-1].erase(it);
		}
	}
	
	puts("Second");
}
