#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
using piii = pair<ll, pair<ll, int>>;

ll solve() {
    ll N, x, y;
    cin >> N;
    vector<ll> X(N), Y(N);
    set<piii> sx, sy;
    for ( int i = 0; i < N; i++ ) {
        cin >> x >> y;
        if ( x > y ) swap(x,y);
        X[i] = x;
        Y[i] = y;
        sx.insert(piii(x,pii(y,i)));
        sy.insert(piii(y,pii(x,i)));
    }
    ll m = 1e18;
    for(;;) {
        ll xmin = sx.begin()->first;
        ll xmax = sx.rbegin()->first;
        ll ymin = sy.begin()->first;
        ll ymax = sy.rbegin()->first;
        m = min(m, (ymax - ymin) * (xmax - xmin));
        piii v = *sx.begin();
        int i = v.second.second;
        if ( Y[i] == v.first ) break;
        piii u = piii(Y[i], pii(X[i], i));
        sx.erase(v);
        sx.insert(u);
        sy.erase(u);
        sy.insert(v);
    }
    return m;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}