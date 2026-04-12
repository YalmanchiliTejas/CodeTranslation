#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
        return *this;
    }
    modular operator+(modular rhs) {
        return modular(*this) += rhs;
    }
    modular operator-(modular rhs) {
        return modular(*this) -= rhs;
    }
    modular operator*(modular rhs) {
        return modular(*this) *= rhs;
    }
    modular operator/(modular rhs) {
        return modular(*this) /= rhs;
    }
    bool operator==(modular rhs) {
        return value == rhs.value;
    };
    bool operator!=(modular rhs) {
        return value != rhs.value;
    };
    bool operator<(modular rhs) {
        return value < rhs.value;
    }
};
template <long long mod>
string to_string(modular<mod> x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, modular<mod> x) {
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
};
const long long mod = 1e9 + 7;
using mint = modular<mod>;

struct edge {
    int from, to;
    ll cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    s--, t--;
    vector<edge> e(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        g[u].emplace_back(i);
        g[v].emplace_back(i);
        e[i] = {u, v, d};
    }
    vector<ll> dist(n, 1e18);
    vector<mint> cnt(n);
    dist[s] = 0;
    cnt[s] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dist[v]) continue;
        for (int id : g[v]) {
            int to = e[id].from ^ e[id].to ^ v;
            ll cost = e[id].cost;
            if (dist[v] + cost == dist[to]) {
                cnt[to] += cnt[v];
            }
            if (dist[v] + cost < dist[to]) {
                cnt[to] = cnt[v];
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }
    ll mx = dist[t];
    ll ds = mx / 2;
    ll dt = mx - ds - 1;
    vector<bool> iss(n);
    mint ans = cnt[t];
    ans *= ans;
    for (int i = 0; i < n; i++) {
        if (dist[i] <= ds) {
            iss[i] = true;
        } else {
            dist[i] = 1e18;
            cnt[i] = 0;
        }
    }
    cnt[t] = 1;
    dist[t] = 0;
    pq.push({0, t});
    while (!pq.empty()) {
        int v = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dist[v]) continue;
        for (int id : g[v]) {
            int to = e[id].from ^ e[id].to ^ v;
            ll cost = e[id].cost;
            if (iss[to]) continue;
            if (dist[v] + cost == dist[to]) {
                cnt[to] += cnt[v];
            }
            if (dist[v] + cost < dist[to]) {
                cnt[to] = cnt[v];
                dist[to] = dist[v] + cost;
                pq.push({dist[to], to});
            }
        }
    }
    vector<mint> st(n);
    debug(ans);
    for (int i = 0; i < m; i++) {
        if (iss[e[i].from] == iss[e[i].to]) continue;
        if (dist[e[i].from] + dist[e[i].to] + e[i].cost != mx) continue;
        if (dist[e[i].from] * 2 == mx) {
            st[e[i].from] += cnt[e[i].to];
        } else if (dist[e[i].to] * 2 == mx) {
            st[e[i].to] += cnt[e[i].from];
        } else {
            ans -= cnt[e[i].from] * cnt[e[i].to] * cnt[e[i].from] * cnt[e[i].to];
        }
    }
    for (int i = 0; i < n; i++) {
        ans -= cnt[i] * cnt[i] * st[i] * st[i];
    }
    cout << ans << endl;
    return 0;
}