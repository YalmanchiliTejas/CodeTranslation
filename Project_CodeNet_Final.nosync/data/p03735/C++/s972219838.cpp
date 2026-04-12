#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
const int kInf = 1'000'000'000 + 5;
int x[kN], y[kN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    int a = min(*min_element(x, x + n), *min_element(y, y + n));
    int b = max(*max_element(x, x + n), *max_element(y, y + n));
    int c = -kInf, d = kInf;
    for (int i = 0; i < n; ++i) {
        c = max(c, min(x[i], y[i]));
        d = min(d, max(x[i], y[i]));
    }
    assert(c >= a && b >= d);
    long long ans = 1LL * (c - a) * (b - d);
    int df = b - a;
    vector<int> g(x, x + n);
    for (int i = 0; i < n; ++i) g.push_back(y[i]);
    for (int i = 0; i < n; ++i) if (x[i] > y[i]) swap(x[i], y[i]);
    sort(g.begin(), g.end());
    g.resize(unique(g.begin(), g.end()) - g.begin());
    vector<int> od(n);
    iota(od.begin(), od.end(), 0);
    sort(od.begin(), od.end(), [&](int i, int j) { return x[i] < x[j]; });
    int z = *min_element(y, y + n);
    multiset<int> p;
    for (int i = 0; i < n; ++i) p.insert(x[i]);
    for (int i = 0, j = 0; i < g.size(); ++i) {
        if (g[i] > z) break;
        while (j < n && x[od[j]] < g[i]) {
            p.erase(p.find(x[od[j]]));
            p.insert(y[od[j++]]);
        }
        ans = min(ans, 1LL * df * (*p.rbegin() - g[i]));
    }
    printf("%lld\n", ans);
    return 0;
}
