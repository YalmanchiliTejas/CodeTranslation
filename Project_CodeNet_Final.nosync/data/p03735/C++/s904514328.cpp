#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;

using P = pair<int, int>;
const ll INF = 4e18;
int n;
V<P> a;
ll amin, amax;

ll solve1() {
    ll bmin = INF, bmax = 0;
    for (auto &p : a) {
        bmin = min<ll>(bmin, p.second);
        bmax = max<ll>(bmax, p.first);
    }
    return (amax-bmin)*(bmax-amin);
}

ll solve2() {
    set<P> st;
    for (int i = 0; i < n; i++) {
        st.emplace(a[i].first, i);
    }
    int last = -1;
    ll ans = INF;
    while (true) {
        int id, v; tie(v, id) = *st.begin();
        st.erase(st.begin());
        ans = min<ll>(ans, st.rbegin()->first-v);
        if (id == last) break;
        st.emplace(a[id].second, id);
        last = id;
    }
    return ans*(amax-amin);
}

int main() {
    scanf("%d", &n);
    amin = INF; amax = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        a.emplace_back(x, y);
        amin = min<ll>(amin, x);
        amax = max<ll>(amax, y);
    }

    ll ans = min(solve1(), solve2());
    printf("%lld\n", ans);
    return 0;
}