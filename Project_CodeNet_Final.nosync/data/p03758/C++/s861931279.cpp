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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll query(string &s)
{
	cout<<"? "<<s<<'\n';
	fflush(stdout);
	ll x; cin>>x;
	return x;
}

vector<ii> edges;

void out()
{
	cout<<"! ";
	for(int i=0;i<edges.size();i++)
	{
		cout<<"(";
		cout<<edges[i].fi<<","<<edges[i].se<<")";
		if(i+1<edges.size()) cout<<' ';
	}
	cout<<'\n';
	fflush(stdout);
}

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

int main()
{
	vector<ii> possible;
	srand(199);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			possible.pb(mp(i,j));
		}
	}
	random_shuffle(possible.begin(),possible.end());
	DSU dsu(n);
	for(int i=0;i<possible.size();i++)
	{
		if(dsu.sameset(possible[i].fi,possible[i].se)) continue;
		string s(n,'0');
		s[possible[i].fi]=s[possible[i].se]='1';
		if(query(s)==1)
		{
			dsu.merge(possible[i].fi,possible[i].se);
			edges.pb(possible[i]);
		}
		if(int(edges.size())>=n-1)
		{
			out();
			return 0;
		}
	}
		
}
