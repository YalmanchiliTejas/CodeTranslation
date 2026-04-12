// In the name of Allah
// #Isart

#include<bits/stdc++.h>

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double

using namespace std;

const int MAXN = 1e5 + 10;
int root[MAXN], sz[MAXN];
pair<ll, ll> x[MAXN], y[MAXN]; 
vector<pair<ll, pair<ll, ll> > > e;

int get_root(int v){
	return (root[v] == v) ? v : root[v] = get_root(root[v]);
}

bool merge(int x, int y){
	x = get_root(x), y = get_root(y);
	if(x == y) return false;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y]; root[y] = x;
	return true;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) sz[i] = 1, root[i] = i;
	ll sum = 0;
	for(int i = 0; i < n; i ++) cin >> x[i].F >> y[i].F, x[i].S = y[i].S = i;
	sort(x, x + n);
	sort(y, y + n);
	for(int i = 0; i < n - 1; i ++){
		e.pb({x[i + 1].F - x[i].F, {x[i].S, x[i + 1].S}});
		e.pb({y[i + 1].F - y[i].F, {y[i].S, y[i + 1].S}});
	}
	sort(e.begin(), e.end());
	for(auto u : e){
		if(merge(u.S.F, u.S.S)) sum += u.F;
	}
	cout << sum << endl;
	return 0;	
}