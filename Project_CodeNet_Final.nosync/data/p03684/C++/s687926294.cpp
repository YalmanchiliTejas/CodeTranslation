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
#define MAXN 101010
using namespace std;

vi pr(MAXN , 0);
vi ra(MAXN , 1);

inline int find_set(int v){
	return pr[v] == v ? v : pr[v] = find_set(pr[v]);
}

void union_sets(int a , int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(ra[a] < ra[b])
			swap(a , b);
		ra[a] += ra[b];
		pr[b] = a;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	int n;
	cin >> n;
	
	vector<pii> x(n) , y(n);
	
	rep(i , n){
		int u , v;
		cin >> u >> v;
		x[i] = {u , i};
		y[i] = {v , i};
		pr[i] = i;
	}
	
	
	SORT(x);
	SORT(y);
	
	vector<pair<int , pii>> g(2 * (n - 1));
	
	rep(i , n - 1){
		g[2 * i] = {x[i + 1].fi - x[i].fi , {x[i].se , x[i + 1].se}};
		g[2 * i + 1] = {y[i + 1].fi - y[i].fi , {y[i].se , y[i + 1].se}};
	}
	
	SORT(g);
	
	ll ans = 0;
	int reb = 0;
	
	rep(i , 2 * (n - 1)){
		auto e = g[i].se;
		if(find_set(e.fi) != find_set(e.se)){
			ans += g[i].fi;
			union_sets(e.fi , e.se);
			++reb;
		}
		if(reb == n - 1){
			break;
		}
	}
	cout << ans;
	return 0;
}