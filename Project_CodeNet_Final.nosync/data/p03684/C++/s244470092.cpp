#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

struct point {
    int x, y, id;
} a[N];

bool cmp1(const point& a, const point& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

bool cmp2(const point& a, const point& b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int n;
bool visited[N];
vector<pair<ll, int> > g[N];

ll prim(int x) {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    ll ans = 0;
    pq.push({0, x});
    while(!pq.empty()) {
        pair<ll, int> p = pq.top();
        pq.pop();
        x = p.second;
        if (visited[x]) {
        	continue;
		}
        ans += p.first;
        visited[x] = true;
        for(int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].second;
            if (!visited[y]) {
            	pq.push(g[x][i]);
            }
        }
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i + 1;
	}
	sort(a, a + n, cmp1);
	for (int i = 1; i < n; i++) {
		g[a[i].id].push_back({abs(a[i].x - a[i - 1].x), a[i - 1].id});
		g[a[i - 1].id].push_back({abs(a[i].x - a[i - 1].x), a[i].id});
	}
	sort(a, a + n, cmp2);
	for (int i = 1; i < n; i++) {
		g[a[i].id].push_back({abs(a[i].y - a[i - 1].y), a[i - 1].id});
		g[a[i - 1].id].push_back({abs(a[i].y - a[i - 1].y), a[i].id});
	}
	cout << prim(1) << '\n';
	return 0;
}
