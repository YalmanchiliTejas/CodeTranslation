#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct interval {
    int l, r;
    ll a;

    interval(int l, int r, ll a) : l(l), r(r), a(a) {}
};

struct segtree {
    int n;
    vector<ll> t, d;

    segtree(int n) : n(n) {
        t.resize(4 * n);
        d.resize(4 * n);
    }

    void push(int i) {
        t[2 * i + 1] += d[i];
        t[2 * i + 2] += d[i];
        d[2 * i + 1] += d[i];
        d[2 * i + 2] += d[i];
        d[i] = 0;
    }

    void inc(int i, int L, int R, int l, int r, ll x) {
        if (l <= L && R <= r) {
            t[i] += x;
            d[i] += x;
        } else {
            push(i);
            int M = (L + R) / 2;
            if (l <= M)
                inc(2 * i + 1, L, M, l, r, x);
            if (r > M)
                inc(2 * i + 2, M + 1, R, l, r, x);
            t[i] = max(t[2 * i + 1], t[2 * i + 2]);
        }
    }

    void inc(int l, int r, ll x) {
        inc(0, 0, n - 1, l, r, x);
    }

    ll rmq(int i, int L, int R, int l, int r) {
        if (l <= L && R <= r)
            return t[i];
        push(i);
        int M = (L + R) / 2;
        ll result = LLONG_MIN;
        if (l <= M)
            result = max(result, rmq(2 * i + 1, L, M, l, r));
        if (r > M)
            result = max(result, rmq(2 * i + 2, M + 1, R, l, r));
        return result;
    }

    ll rmq(int l, int r) {
        return rmq(0, 0, n - 1, l, r);
    }
};

int N, M;
vector<vector<interval>> on, off;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int n = N + 2;
    on.resize(n);
    off.resize(n);
    segtree dp(n), score(n);
    while (M--) {
        int l, r;
        ll a;
        cin >> l >> r >> a;
        on[l].push_back(interval(l, r, a));
        off[r + 1].push_back(interval(l, r, a));
        score.inc(l, r, a);
    }
    for (int i = 1; i <= N; i++) {
        for (interval e : off[i])
            dp.inc(e.l, e.r, e.a);
        dp.inc(i, i, score.rmq(i, i) + dp.rmq(0, i - 1));
        for (interval e : on[i])
            dp.inc(e.l, e.r, -e.a);
    }
    for (interval e : off[N + 1])
        dp.inc(e.l, e.r, e.a);
    cout << dp.rmq(0, N) << endl;
}
