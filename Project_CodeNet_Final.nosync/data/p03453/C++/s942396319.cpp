#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
#define X first
#define Y second

const int N = 100005;
const ll inf = ll(1e18) + 5, M = ll(1e9) + 7;

vector<pii> e[N];
vector<int> de[N], re[N];

int n, m, s, t, fc[N], gc[N];
ll d[N], r, fd[N], gd[N];
priority_queue<pli, vector<pli>, greater<pli>> pq;

ll f(int x){
	if(fc[x]) return fd[x];
	fc[x] = 1;
	if(x == s) return fd[x] = 1;
	for(int i : re[x]) fd[x] = (fd[x] + f(i)) % M;
	return fd[x];
}

ll g(int x){
	if(gc[x]) return gd[x];
	gc[x] = 1;
	if(x == t) return gd[x] = 1;
	for(int i : de[x]) gd[x] = (gd[x] + g(i)) % M;
	return gd[x];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> s >> t;
	for(int x, y, z; m--; ){
		cin >> x >> y >> z;
		e[x].emplace_back(y, z);
		e[y].emplace_back(x, z);
	}
	fill(d + 1, d + n + 1, inf);
	d[s] = 0;
	pq.emplace(0LL, s);
	while(!pq.empty()){
		ll c; int x;
		tie(c, x) = pq.top();
		pq.pop();
		if(c > d[x]) continue;
		for(pii i : e[x]){
			if(d[i.X] < c + i.Y) continue;
			if(d[i.X] > c + i.Y){
				d[i.X] = c + i.Y;
				pq.emplace(c + i.Y, i.X);
				re[i.X].clear();
			}
			re[i.X].push_back(x);
		}
	}
	for(int i = 1; i <= n; i++) for(int j : re[i]) de[j].push_back(i);
	r = f(t) * f(t) % M;
	for(int i = 1; i <= n; i++){
		if(d[i] * 2 == d[t]) r = (r - (f(i) * g(i) % M) * (f(i) * g(i) % M) % M + M) % M;
		for(int j : de[i]) if(d[i] * 2 < d[t] && d[j] * 2 > d[t])
			r = (r - (f(i) * g(j) % M) * (f(i) * g(j) % M) % M + M) % M;
	}
	cout << r << endl;
}