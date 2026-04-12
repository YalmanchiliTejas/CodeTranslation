#include <atcoder/segtree>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f_max(ll a, ll b) {
    return max(a,b);
}
ll f_e() {
    return -(1LL<<60);
}

ll solve() {
    ll N, Q, t, x, v, l, r, a;
    cin >> N >> Q;
    atcoder::segtree<ll,f_max,f_e> sg(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        sg.set(i, a);
    }
    auto f_v = [&](ll ma) {return v>ma;};
    vector<ll> ans;
    for ( int q = 0; q < Q; q++ ) {
        cin >> t;
        switch ( t ) {
            case 1:
                cin >> x >> v;
                x--;
                sg.set(x,v);
                break;
            case 2:
                cin >> l >> r;
                l--, r--;
                ans.push_back(sg.prod(l, r+1));
                break;
            case 3:
                cin >> x >> v;
                x--;
                int j = sg.max_right(x, f_v) + 1;
                ans.push_back(j);
                break;
        }
    }

    for ( ll an : ans ) {
        cout << an << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}