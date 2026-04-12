#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e5 + 10;
int x[maxN], y[maxN];
int p[maxN];
int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (rand() & 1) swap(a, b);
    p[a] = b;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > byX, byY;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        byX.emplace_back(x[i], i);
        byY.emplace_back(y[i], i);
    }
    sort(byX.begin(), byX.end());
    sort(byY.begin(), byY.end());
    vector < pair < int, pair < int, int > > > edges;
    for (int i = 0; i + 1 < n; i++) {
        edges.emplace_back(byX[i + 1].first - byX[i].first, make_pair(byX[i].second, byX[i + 1].second));
        edges.emplace_back(byY[i + 1].first - byY[i].first, make_pair(byY[i].second, byY[i + 1].second));
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (auto it : edges) {
        if (unite(it.second.first, it.second.second)) ans += it.first;
    }
    cout << ans;
    return 0;
}