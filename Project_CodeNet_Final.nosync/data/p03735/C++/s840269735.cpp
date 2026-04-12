#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int, int> P;
const int MN = 200010;
const int INF = 2e9;
int n;
P a[MN];
int ma, mi;

ll solve1() {
    int lmi = INF, rma = 0;
    for (int i = 0; i < n; i++) {
        lmi = min(lmi, a[i].second);
        rma = max(rma, a[i].first);
    }
    return ll(ma - lmi) * (rma - mi);
}

ll solve2() {
    int dmi = INF;
    set<P> st;
    for (int i = 0; i < n; i++) {
        st.insert(P(a[i].first, i));
    }
    int last = -1;
    while (!st.empty()) {
        P x = *(st.begin());
        st.erase(st.begin());
        int v = x.first, id = x.second;
        dmi = min(dmi, st.rbegin()->first - v);
        if (id == last) break;
        if (v <= a[id].second) {
            st.insert(P(a[id].second, id));
        }
        last = id;
    }
    return ll(ma - mi) * dmi;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    ma = 0; mi = INF;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a[i] = P(x, y);
        ma = max(ma, y);
        mi = min(mi, x);
    }

    ll ans = min(solve1(), solve2());
    cout << ans << endl;
    return 0;
}