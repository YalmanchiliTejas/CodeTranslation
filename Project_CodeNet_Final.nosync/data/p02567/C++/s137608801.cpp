#include <bits/stdc++.h>

#include <atcoder/all>
typedef long long ll;
#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (ll i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (ll i = ((ll)(n)-1); i >= 0; --i)
#define rreps(i, n) for (ll i = ((ll)(n)); i > 0; --i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repc2(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -1;
}

int target;

bool f(int v) {
    return v < target;
}

int n, q;
int main() {
    cin >> n >> q;
    vector<int> v(n + 1);
    reps(i, n) cin >> v[i];
    segtree<int, op, e> st(v);

    rep(i, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int x, v;
            cin >> x >> v;
            st.set(x, v);
        } else if (c == 2) {
            int l, r;
            cin >> l >> r;
            cout << st.prod(l, r + 1) << endl;
        } else {
            int x;
            cin >> x >> target;
            int res = st.max_right<f>(x);
            cout << res << endl;
        }
    }
    return 0;
}