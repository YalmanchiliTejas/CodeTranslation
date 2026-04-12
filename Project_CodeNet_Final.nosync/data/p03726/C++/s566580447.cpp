#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 1e5 + 55;//, mod = 1e9 + 7;
int n, p[maxn], rem[maxn], deg[maxn], h[maxn];
vi g[maxn], ord;
void dfs(int v, int pr = -1) {
	p[v] = pr;
	for(auto i : g[v])
		if(i!=pr) h[i] = h[v] + 1, dfs(i, v), deg[v]++;
	ord.pb(v);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if(n==1) return cout << "First", 0;
	if(n==2) return cout << "Second", 0;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int r = 0;
	for(int i = 1; i <= n; i++) if(g[i].size()==1) {dfs(i);r=i;break;};
	sort(all(ord), [&](const int &i, const int &j) {
		return h[i] > h[j];
	});
	int lft = 0;
	for(auto i : ord) {
		if(rem[i]) continue;
		if(deg[i] ==0 && deg[p[i]]==1) {
			rem[i] = rem[p[i]] = 1;
			p[p[i]]!=-1?deg[p[p[i]]]--:0;
		} else lft++;
	}
	lft += 1^rem[r];
	cout << (lft==0?"Second":"First");
}

