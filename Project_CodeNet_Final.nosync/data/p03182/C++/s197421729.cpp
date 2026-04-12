#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Seg {
private:
    int n;
    vector<ll> tree, lazy; 

    inline void flush(int no, int l, int r) {
        if (l != r) {
            lazy[no*2] += lazy[no];
            lazy[no*2+1] += lazy[no];
        }
        tree[no] += lazy[no];
        lazy[no] = 0;
    }

    void upd(int no, int l, int r, int a, int b, ll val) {
        flush(no, l, r);
        if (a <= l and r <= b) {
            lazy[no] += val;
            return;
        }

        int m = (l+r)/2;

        if (a <= m) upd(no*2, l, m, a, b, val);
        if (b > m) upd(no*2+1, m+1, r, a, b, val);

        flush(no*2, l, m);
        flush(no*2+1, m+1, r);

        tree[no] = max(tree[no*2], tree[no*2+1]);
    }

    ll get(int no, int l, int r, int a, int b) {
        flush(no, l, r);
        if (a <= l and r <= b) {
            return tree[no];
        }

        int m = (l+r)/2;

        if (b <= m) return get(no*2, l, m, a, b);
        if (a > m) return get(no*2+1, m+1, r, a, b);

        return max(
            get(no*2, l, m, a, b),
            get(no*2+1, m+1, r, a, b)
        );
    }

public:
    Seg(int n) : n(n), tree(n*4), lazy(n*4) {};

    void upd(int a, int b, ll val) {
        upd(1, 1, n, a, b, val);
    }

    ll get(int a, int b) {
        return get(1, 1, n, a, b);
    }
};

struct Interval {
    int l, r, w;

    bool operator<(Interval const& rhs) const {
        return l < rhs.l;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<Interval> v(m);

    for (auto& i : v) {
        cin >> i.l >> i.r >> i.w;
    }

    sort(v.begin(), v.end());

    int at = m-1;
    vector<ll> dp(n+1);
    Seg seg(n+1);

    for (int i = n; i >= 0; i--) {
        dp[i] = seg.get(i+1, n+1);

        if (i != 0) {
            seg.upd(i, i, dp[i]);
        }

        while (at >= 0 and v[at].l >= i) {
            seg.upd(v[at].l, v[at].r, v[at].w);
            at--;
        }
    }

    cout << dp[0] << "\n";
}