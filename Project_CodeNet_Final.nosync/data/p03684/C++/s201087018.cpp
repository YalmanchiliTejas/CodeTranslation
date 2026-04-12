#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int p[200005];

int root(int x) {return p[x] < 0 ? x : p[x] = root(p[x]);}

void mer(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    int n, z = 0;
    vector<pair<int, pii>> c;
    pair<pii, int> a[100005] = {}, b[100005] = {};
    cin >> n;
    for (int i = 0; i <= n + n; i++) p[i] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i].first.first >> a[i].first.second, b[i].first.first = a[i].first.second, b[i].first.second = a[i].first.first, a[i].second = b[i].second = i;
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
    for (int i = 1; i < n; i++) c.push_back({a[i + 1].first.first - a[i].first.first, {a[i].second, a[i + 1].second}}), c.push_back({b[i + 1].first.first - b[i].first.first, {b[i].second, b[i + 1].second}});
    sort(c.begin(), c.end());
    for (pair<int, pii> i : c) {
        int u = i.second.first, v = i.second.second, w = i.first;
        if (root(u) != root(v)) {
            mer(u, v);
            z += w;
        }
    }
    cout << z;
}
