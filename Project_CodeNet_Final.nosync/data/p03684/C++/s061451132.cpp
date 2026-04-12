#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
typedef long long ll;

using namespace std;

int pai[MAXN];

void init(int n){
	for(int i=1; i<=n; i++){
		pai[i]=i;
	}
}

int find(int i){
	if(pai[i]==i)return i;
	return pai[i]=find(pai[i]);
}

int join(int a, int b){
	a=find(a);
	b=find(b);
	pai[a]=pai[b];
}

int n;
ll ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    init(n);
    vector<pair<pii, int> > s, r;
    for(int i = 0; i < n; i++){
    	pii p;
    	cin >> p.fi >> p.se;
    	s.pb({p, i});
    	r.pb({{p.se, p.fi}, i});
    }
    sort(s.begin(), s.end());
    sort(r.begin(), r.end());
    vector<pair<int, pii> > edges;
    for(int i = 0; i < n - 1; i++){
    	edges.pb({s[i + 1].fi.fi - s[i].fi.fi, {s[i].se, s[i + 1].se}});
    	edges.pb({r[i + 1].fi.fi - r[i].fi.fi, {r[i].se, r[i + 1].se}});
    }
    sort(edges.begin(), edges.end());
    for(auto e : edges){
    	int a = e.se.fi, b = e.se.se;
    	if(find(a) == find(b)) continue;
    	join(a, b);
    	ans += e.fi;
    }
    cout << ans;
}