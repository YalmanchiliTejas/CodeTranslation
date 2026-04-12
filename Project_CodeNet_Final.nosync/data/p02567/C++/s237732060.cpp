#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif


template<class Monoid>
class SegmentTree {

public:
    /**
     * @param N size
     * @param e identity element
     * @param operation operation to merge `data`
     * @param updater operation to update `data`
     */
    SegmentTree(size_t N, Monoid e, function<Monoid(Monoid, Monoid)> operation,
                function<Monoid(Monoid, Monoid)> updater)
            : e(e), operation(operation), updater(move(updater)) {
        n = 1;
        while (n < N) {
            n *= 2;
        }
        data = vector<Monoid>(2 * n - 1, e);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = operation(data[2 * i + 1], data[2 * i + 2]);
        }
    }

    /**
     * iの値をxに更新 ( 0-indexed )
     */
    void update(int i, Monoid x) {
        i += n - 1;
        data[i] = updater(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    /**
     * [a, b)の区間でクエリを実行
     */
    Monoid query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * 添字でアクセス( 0-indexed )
     */
    Monoid operator[](int i) {
        return data[i + n - 1];
    }

private:
    int n;
    vector<Monoid> data;
    Monoid e;
    function<Monoid(Monoid, Monoid)> operation;
    function<Monoid(Monoid, Monoid)> updater;

    Monoid query(int a, int b, int k, int l, int r) {
        // 交差しない
        if (r <= a || b <= l) return e;
        // 区間 [a, b) に l, r が含まれる
        if (a <= l && r <= b) return data[k];
        // 左の子
        Monoid c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
        // 右の子
        Monoid c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(c1, c2);
    }
};


void solve() {
    ll N, Q;
    cin >> N >> Q;
    SegmentTree<ll> segmentTree(N + 1, 0, [](ll a, ll b) { return max(a, b); }, [](ll a, ll b) { return b; });
    rep(i, N) {
        ll a;
        cin >> a;
        segmentTree.update(i + 1, a);
    }
    rep(q, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, v;
            cin >> x >> v;
            segmentTree.update(x, v);
        } else if (t == 2) {
            ll l, r;
            cin >> l >> r;
            cout << segmentTree.query(l, r + 1) << '\n';
        } else {
            ll x, v;
            cin >> x >> v;
            ll v2 = segmentTree.query(x, N + 1);
            if (v2 >= v) {
                ll ok = N;
                ll ng = x - 1;
                auto f = [&](ll idx) {
                    ll val = segmentTree.query(x, idx + 1);
                    return val >= v;
                };
                while (ok - ng > 1 && ng >= x - 1) {
                    ll mid = (ok + ng) / 2;
                    if (f(mid)) {
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                }
                cout << ok << '\n';
            } else {
                cout << N + 1 << '\n';
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
