#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct UF {
	vi t;
	UF(int n){
		t.resize(n, -1);
	}

	int find(int a){
		return t[a]<0 ? a : t[a] = find(t[a]);
	}

	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return 0;
		if(t[a] < t[b]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
		return 1;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi xs(n), ys(n);
	rep(i,0,n) cin >> xs[i] >> ys[i];
	vi ps1(n), ps2(n);
	rep(i,0,n) ps1[i] = ps2[i] = i;
	sort(all(ps1), [&](int x, int y){
		return xs[x] < xs[y];
	});
	sort(all(ps2), [&](int x, int y){
		return ys[x] < ys[y];
	});
	ll cost = 0;
	vector<pair<int,pii>> es;
	rep(i,1,n) es.emplace_back(xs[ps1[i]]-xs[ps1[i-1]], pii(ps1[i],ps1[i-1]));
	rep(i,1,n) es.emplace_back(ys[ps2[i]]-ys[ps2[i-1]], pii(ps2[i],ps2[i-1]));
	UF uf(n);
	sort(all(es));
	trav(pa, es){
		int a = pa.second.first, b = pa.second.second;
		if(uf.uni(a,b)) cost += pa.first;
	}
	cout << cost << endl;
}