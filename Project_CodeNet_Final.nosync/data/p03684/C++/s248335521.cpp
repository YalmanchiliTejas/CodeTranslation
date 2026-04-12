#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
struct UnionFind {
    vector<int> data;

    UnionFind(int sz) { data.assign(sz, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y)
            return (false);
        if(data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    ll size(int k) { return (-data[find(k)]); }
};
int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
    }
    sort(all(x));
    sort(all(y));
    priority_queue<pair<ll, pair<int, int>>> edge;
    for(int i = 1; i < n; i++) {
        edge.push(make_pair(x[i - 1].first - x[i].first,
                            make_pair(x[i].second, x[i - 1].second)));
    }
    for(int i = 1; i < n; i++) {
        edge.push(make_pair(y[i - 1].first - y[i].first,
                            make_pair(y[i].second, y[i - 1].second)));
    }
    UnionFind uf(n);
    ll w = 0;
    while(!edge.empty()) {
        auto e = edge.top();
        edge.pop();
        if(!uf.isSame(e.second.first, e.second.second)) {
            uf.unite(e.second.first, e.second.second);
            w -= e.first;
        }
    }
    cout << w << endl;
}
