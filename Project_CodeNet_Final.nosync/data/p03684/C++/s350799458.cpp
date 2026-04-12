#include <bits/stdc++.h>
using namespace std;
const int base = (int) 1e9+7;
const int maxn = (int) 1e5 + 5;
#define x first
#define y second
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
int n, m;
pii a[maxn];
pip c[maxn];
bool fre[maxn];
bool mycmp1(pip u, pip v) {
	return u.y.x < v.y.x;
}
bool mycmp2(pip u, pip v) {
	return u.y.y < v.y.y;
}
int ABS(int x) { return x>0?x:-x;}
vector<int> ds[maxn];
int d[maxn];
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;	
		c[i].x = i;
		c[i].y = a[i];
	}
	sort(c+1, c + 1 + n, mycmp1);
	for(int i = 2; i <= n; ++i) {
		int u = c[i].x, v = c[i-1].x;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}
	sort(c+1, c + 1 + n, mycmp2);
	for(int i = 2; i <= n; ++i) {
		int u = c[i].x, v = c[i-1].x;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}
	priority_queue< pii, vector<pii>, greater<pii> > q;
	q.push(pii(0, 1));
	for(int i = 1; i <= n; ++i) d[i] = base;
	d[1] = 0;
	while (!q.empty()) {
		pii p = q.top(); q.pop();
		int u = p.y, ts = p.x;
		fre[u] = 1;
		for(int i = 0; i < ds[u].size(); ++i) {
			int v = ds[u][i], ts1 = min(ABS(a[u].x-a[v].x), ABS(a[u].y-a[v].y));
			if (!fre[v] && d[v] > ts1) {
				d[v] = ts1;
				q.push(pii(ts1, v));
				//cout << v << " " << ts1 << endl;
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += d[i];
		//cout << d[i] << endl;
	}
	cout << ans << endl;
	return 0;
}