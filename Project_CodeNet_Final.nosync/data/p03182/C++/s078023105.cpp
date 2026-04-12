#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & -x)

using namespace std;

const ll INF = 1000000000 * 200005;

struct Data {
    ll cost;
    int l, r;
};

struct AINT {
    vector<ll> aint, lazy;

    AINT(int n) {
        aint.resize(n * 4 + 1, 0);
        lazy.resize(n * 4 + 1, 0);
    }

    void update(int from, int to, ll toadd, int node, int le, int ri) {
        if(from <= le && ri <= to) {
            lazy[node] += toadd;
            aint[node] += toadd;
        } else {
            int mid = (le + ri) / 2;
            if(from <= mid)
                update(from, to, toadd, node * 2, le, mid);
            if(mid < to)
                update(from, to, toadd, node * 2 + 1, mid + 1, ri);

            aint[node] = lazy[node] + max(aint[node * 2], aint[node * 2 + 1]);
        }
    }

    ll query(int from, int to, int node, int le, int ri) {
        if(from <= le && ri <= to)
            return aint[node];
        int mid = (le + ri) / 2;
        ll ans = -INF;
        if(from <= mid)
            ans = query(from, to, node * 2, le, mid);
        if(mid < to)
            ans = max(ans, query(from, to, node * 2 + 1, mid + 1, ri));
        ans += lazy[node];

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<Data> v(m + 1, {0, 0, 0});
    vector<ll> start(n + 2, 0);
    vector< vector<pair<int, int>> > en(n + 1);
    for(int i = 1; i <= m; i ++) {
        cin >> v[i].l >> v[i].r >> v[i].cost;
        start[v[i].l] += v[i].cost;
        en[v[i].r].push_back({v[i].l, v[i].cost});
    }

    n ++;
    vector<ll> dp(n + 1, 0);
    AINT aint(n);
    for(int i = 1; i <= n; i ++) {
        aint.update(0, i - 1, start[i], 1, 0, n);
        for(auto it : en[i - 1])
            aint.update(0, it.first - 1, -it.second, 1, 0, n);

        dp[i] = aint.query(0, i - 1, 1, 0, n);
        aint.update(i, i, dp[i], 1, 0, n);
    }

    cout << dp[n];

    return 0;
}
