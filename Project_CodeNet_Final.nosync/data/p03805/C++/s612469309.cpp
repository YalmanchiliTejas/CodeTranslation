#include<bits/stdc++.h>
 
#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;
 
using namespace std;
 
vi g[10];
 
vi cnt(10 , 0);

int n , m , ans;

void dfs(int cur , vi used , int total){
	used[cur] = 1;
	if(total == n){
		++ans;
		return;
	}
	rep(i , sz(g[cur])){
		int v = g[cur][i];
		if(!used[v]){
			dfs(v , used , total + 1);
		}
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	cin >> n >> m;
	rep(i , m){
		int u , v;
		cin >> u >> v;
		--u;
		--v;
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i , sz(g[0])){
		vi used(10 , 0);
		used[0] = 1;
		++cnt[0];
		dfs(g[0][i] , used , 2);
	}
	die(ans);
	return 0;
}