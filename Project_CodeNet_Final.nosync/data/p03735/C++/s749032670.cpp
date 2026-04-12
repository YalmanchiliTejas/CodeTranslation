#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<long long> x(n), y(n);
    multiset<pair<long long, long long>> b;
    long long maxr = 0, minr = 1e9, maxb = 0, minb = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        maxr = max(maxr, max(x[i], y[i]));
        minr = min(minr, max(x[i], y[i]));
        maxb = max(maxb, min(x[i], y[i]));
        minb = min(minb, min(x[i], y[i]));
        b.emplace(min(x[i], y[i]), max(x[i], y[i]));
    }
    long long ans = (maxr - minr) * (maxb - minb); 
    long long delta = maxr - minb;
    while (true) {
        long long mul = b.rbegin()->first - b.begin()->first;
        ans = min(ans, delta * mul);
        auto it = *b.begin();
        if (it.first >= it.second) break;
        b.erase(b.begin());
        b.emplace(it.second, it.first);
    }
    cout << ans << "\n";
    return 0;
}