#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int par[110001];

int rt(int u)
{
	if(par[u]<0) return u;
	return (par[u]=rt(par[u]));
}

void merge(int u,int v)
{
	u=rt(u); v=rt(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v]; par[v]=u;
}

ii a[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	memset(par,-1,sizeof(par));
	vector<pair<ll,ii> > vec;
	vector<ii> X,Y;
	for(int i = 0; i < n; i++)
	{
		int x,y; cin>>x>>y;
		a[i]=mp(x,y);
		X.pb(mp(x,i)); Y.pb(mp(y,i));
	}
	sort(X.begin(),X.end()); sort(Y.begin(),Y.end());
	for(int i=0;i+1<n;i++)
	{
		vec.pb(mp(min(abs(a[X[i].se].fi-a[X[i+1].se].fi),abs(a[X[i].se].se-a[X[i+1].se].se)),mp(X[i].se,X[i+1].se)));
		vec.pb(mp(min(abs(a[Y[i].se].fi-a[Y[i+1].se].fi),abs(a[Y[i].se].se-a[Y[i+1].se].se)),mp(Y[i].se,Y[i+1].se)));
	}
	sort(vec.begin(),vec.end());
	ll ans=0;
	for(int i=0;i<vec.size();i++)
	{
		if(rt(vec[i].se.fi)!=rt(vec[i].se.se))
		{
			ans+=vec[i].fi;
			merge(vec[i].se.fi,vec[i].se.se);
		}
	}
	cout<<ans<<'\n';
}
