#include "bits/stdc++.h"
using namespace std;
typedef long long li;

// arc090

template <long long mod>
struct modint {
    long long x;

    modint<mod>(): x(0LL) {}
    modint<mod>(const long long _data) {
        if (_data < 0) {
            x = (_data % mod + mod) % mod;
        } else if (_data >= mod) {
            x = _data % mod;
        } else {
            x = _data;
        }
    }

    bool operator==(const modint<mod>& op) const {
        return x == op.x;
    }

    bool operator!=(const modint<mod>& op) const {
        return !((*this) == op);
    }

    modint<mod> operator-() const {
        if (x == 0) {
            return modint(0);
        }
        return modint(mod - x);
    }

    modint<mod> operator+(const modint<mod>& op) const {
        const long long newdata = x + op.x;
        if (newdata >= mod) {
            return modint<mod>(newdata - mod);
        } else {
            return modint<mod>(newdata);
        }
    }

    modint<mod>& operator+=(const modint<mod>& op) {
        x = (*this + op).x;
        return *this;
    }

    modint<mod> operator-(const modint<mod>& op) const {
        return *this + (-op);
    }

    modint<mod>& operator-=(const modint<mod>& op) {
        x = (*this - op).x;
        return *this;
    }

    modint<mod> operator*(const modint<mod>& op) const {
        return modint<mod>(x * op.x % mod);
    }

    modint<mod>& operator*=(const modint<mod>& op) {
        x = (*this * op).x;
        return *this;
    }

    modint<mod> pow(const long long n) const {
        if (n == 0) {
            return modint<mod>(1);
        }
        modint<mod> sq = pow(n / 2);
        if (n & 1) {
            return (*this) * sq * sq;
        } else {
            return sq * sq;
        }
    }

    modint<mod> inverse() const {
        return pow(mod - 2);
    }

    modint<mod> operator/(const modint<mod>& op) const {
        return (*this) * op.inverse();
    }

    friend modint<mod> operator/(const long long dividend, const modint<mod>& divisor) {
        return modint<mod>(dividend) / divisor;
    }

    static modint<mod> factorial(const long long n) {
        static std::vector<modint<mod>> cache(1, 1);

        while (cache.size() <= n) {
            modint<mod> next = cache.back() * cache.size();
            cache.push_back(next);
        }
        return cache[n];
    }

    static modint<mod> combination(const long long n, const long long k) {
        if (k < 0 || n < k) {
            return modint<mod>(0);
        }

        if (n < 1e6) {
            return factorial(n) / (factorial(k) * factorial(n - k));
        }

        modint<mod> ret(1);
        for (int i = 1; i <= k; ++i) {
            ret = ret * modint<mod>(n - i + 1) / modint<mod>(i);
        }
        return ret;
    }
};

typedef modint<1000000007> mint;

struct result {
    vector<li> dists;
    vector<mint> counts;
};

struct edge {
    li next, cost;
};

result calc(const vector<vector<edge>>& graph, const li start) {
    const li n = graph.size();
    const li inf = 1LL << 60;
    vector<li> dists(n, inf);
    vector<mint> counts(n, 0);

    priority_queue<pair<li, li>> q;
    q.emplace(0, start);
    dists[start] = 0;
    counts[start] = 1;

    while (not q.empty()) {
        auto t = q.top();
        q.pop();

        const auto dist = -t.first;
        const auto pos = t.second;

        if (dist > dists[pos]) {
            continue;
        }

        for (int idx = 0; idx < graph[pos].size(); ++idx) {
            const auto e = graph[pos][idx];
            const li ndist = dist + e.cost;
            const li next = e.next;

            if (dists[next] < ndist) {
                continue;
            }
            if (ndist < dists[next]) {
                dists[next] = ndist;
                counts[next] = 0;
                q.emplace(-ndist, next);
            }
            counts[next] += counts[pos];
        }
    }

    return {dists, counts};
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    li n, m;
    cin >> n >> m;
    li s, t;
    cin >> s >> t;
    s--; t--;

    vector<vector<edge>> graph(n);
    for(int i = 0; i < m; ++i) {
        li u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    auto takahashi = calc(graph, s);
    auto aoki = calc(graph, t);

    const li min_dist = takahashi.dists[t];
    mint ans = takahashi.counts[t] * aoki.counts[s];
    for (int i = 0; i < n; ++i) {
        if (takahashi.dists[i] == aoki.dists[i] && takahashi.dists[i] + aoki.dists[i] == min_dist) {
            ans -= (takahashi.counts[i] * aoki.counts[i]).pow(2);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int idx = 0; idx < graph[i].size(); ++idx) {
            auto e = graph[i][idx];
            const auto j = e.next;
            const auto d = e.cost;
            if (takahashi.dists[i] + d + aoki.dists[j] == min_dist && takahashi.dists[i] * 2 < min_dist && aoki.dists[j] * 2 < min_dist) {
                ans -= (takahashi.counts[i] * aoki.counts[j]).pow(2);
            }
        }
    }
    cout << ans.x << endl;
    return 0;
}