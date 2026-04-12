#include <map>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

bool compare(P p, P q) { return p.second < q.second; }

int main() {
    int n; cin >> n;
    vector<P> ps;
    for (int i = 0; i < n; i++) { int x, y; cin >> x >> y; ps.push_back(P(x, y)); }
    sort(ps.begin(), ps.end());
    map<P, vector<pair<int, P> > > adj;
    for (int i = 1; i < n; i++) {
        P prev = ps[i-1], cur = ps[i];
        adj[prev].push_back(make_pair(cur.first - prev.first, cur));
        adj[cur].push_back(make_pair(cur.first - prev.first, prev));
    }
    sort(ps.begin(), ps.end(), compare);
    for (int i = 1; i < n; i++) {
        P prev = ps[i-1], cur = ps[i];
        adj[prev].push_back(make_pair(cur.second - prev.second, cur));
        adj[cur].push_back(make_pair(cur.second - prev.second, prev));
    }
    long long ans = 0;
    priority_queue<pair<int, P>, vector<pair<int, P> >, greater<pair<int, P> > > q;
    set<P> v;
    P p = *ps.begin();
    v.insert(p);
    for (auto x : adj[p]) q.push(x);
    while (!q.empty()) {
        auto e = q.top(); q.pop();
        if (v.find(e.second) != v.end()) continue;
        ans += e.first;
        v.insert(e.second);
        for (auto x : adj[e.second]) q.push(x);
    }
    cout << ans << endl;
}
