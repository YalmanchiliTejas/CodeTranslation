#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define sz(x) (int)(x.size())
#define fr(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
/////////////////

int const N = 2e5 + 41;

int n;
vector<pii> x, y;
int p[N];

int find(int u){
	if(u == p[u]) return u;
	return p[u] = find(p[u]);
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	p[b] = a;
	return true;
}

typedef pair<int, pair<int, int>> E;
#define COST first
#define FROM second.first
#define TO second.second

E getE(int c, int f, int t){
	return mp(c, mp(f, t));
}

vector<E> e;

void solve(){
	cin >> n;
	fr(i, 0, n){
		int xi, yi;
		cin >> xi >> yi;
		x.pb(mp(xi, i));
		y.pb(mp(yi, i));
	}
	fr(i, 0, n) p[i] = i;
	sort(x.begin(), x.end());
	fr(i, 1, n) e.pb(getE(x[i].first - x[i-1].first, x[i].second, x[i-1].second));
	sort(y.begin(), y.end());
	fr(i, 1, n) e.pb(getE(y[i].first - y[i-1].first, y[i].second, y[i-1].second));
	sort(e.begin(), e.end());
	ll ans = 0;
	fr(i, 0, sz(e)){
		if(uni(e[i].FROM, e[i].TO)) ans += e[i].COST;
	}
	cout << ans << endl;
}


int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();



	return 0;
}