#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> ii;
typedef pair<int,ii> edge;
typedef pair<ii,int> data;
const int N = 1e5 + 5;
int n;
data a[N];
priority_queue<edge, vector<edge>, greater<edge> > pq;
int par[N];
int anc(int u) { return u == par[u] ? u : par[u] = anc(par[u]); }
void join(int u,int v) { par[anc(v)] = anc(u); }
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se = i;
		par[i] = i; //////////////////
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2;i <= n;++i) pq.push(edge(min(abs(a[i].fi.fi - a[i - 1].fi.fi), abs(a[i].fi.se - a[i - 1].fi.se)), ii(a[i].se, a[i - 1].se)));
	for (int i = 1;i <= n;++i) swap(a[i].fi.se, a[i].fi.fi);
	sort(a + 1, a + 1 + n);
	for (int i = 2;i <= n;++i) pq.push(edge(min(abs(a[i].fi.fi - a[i - 1].fi.fi), abs(a[i].fi.se - a[i - 1].fi.se)), ii(a[i].se, a[i - 1].se)));
	int need = n - 1;
	int res = 0;
	while (need) {
		edge cur = pq.top(); pq.pop();
		if (anc(cur.se.fi) == anc(cur.se.se)) continue;
		join(cur.se.fi, cur.se.se) ; res += cur.fi;need--;
	}
	cout << res;
}