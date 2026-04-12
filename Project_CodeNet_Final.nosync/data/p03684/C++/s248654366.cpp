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
#define INF 1e18

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector < pair<int, int> > vii;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll n, x, y, ans, par[111111];
vector <pair<ii, int> > town;
priority_queue <pair<ll, ii>, vector<pair<ll, ii> >, greater<pair<ll, ii> > > edges;

ll root(ll a){
	if(par[a]<0){
		return a;
	}
	else{
		par[a]=root(par[a]);
		return par[a];
	}
}

void merge(ll a, ll b){
	a=root(a);
	b=root(b);
	if(a==b){
		return;
	}
	else{
		if(par[a]>par[b]){
			swap(a,b);
		}
		par[a]+=par[b];
		par[b]=a;
	}
}

bool cmp(pair<ii, int>  a, pair<ii, int>  b){
	return a.fi.fi<b.fi.fi;
}
bool cmp1(pair<ii, int>  a, pair<ii, int>  b){
	return a.fi.se<b.fi.se;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		town.pb(mp(mp(x,y),i));
	}
	sort(town.begin(),town.end(),cmp);
	for(int i = 1; i < n; i++){
		edges.push(mp(town[i].fi.fi-town[i-1].fi.fi,mp(town[i-1].se,town[i].se)));
	}
	sort(town.begin(),town.end(),cmp1);
	for(int i = 1; i < n; i++){
		edges.push(mp(town[i].fi.se-town[i-1].fi.se,mp(town[i-1].se,town[i].se)));
	}
	for(int i = 0; i < n; i++){
		par[i]=-1;
	}
	while(!edges.empty()){
		auto cur = edges.top();
		edges.pop();
		if(root(cur.se.fi)!=root(cur.se.se)){
			ans+=cur.fi;
			merge(cur.se.fi,cur.se.se);
		}
	}
	cout << ans;
	return 0;
}
