#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <queue>
#include <utility>
#include <map>
#include <tuple>
#include <set>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int ll;
typedef pair<ll, int> P;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

template<ll MOD = 1000000007>
class ModInt {
    ll n;
    static ModInt pow(ModInt x, ll p) {
        if (p == 0) {
            return 1;
        } else if (p % 2) {
            return x * pow(x, p - 1);
        } else {
            auto t = ModInt::pow(x, p / 2);
            return t * t;
        }
    }
    ModInt reverse() {
        return ModInt::pow(*this, MOD - 2);
    }

public:
    ModInt()
        : n(0) {}
    ModInt(ll _n)
        : n(_n % MOD) {}
    ModInt operator+=(const ModInt &m) {
        n += m.n;
        if (n >= MOD) {
            n -= MOD;
        }
        return *this;
    }
    ModInt operator-=(const ModInt &m) {
        n -= m.n;
        if (n < 0) {
            n += MOD;
        }
        return *this;
    }
    ModInt operator*=(const ModInt &m) {
        n *= m.n;
        if (n >= MOD) {
            n %= MOD;
        }
        return *this;
    }
    ModInt operator/=(const ModInt &m) {
        return n *= reverse(m);
    }

    ModInt operator+=(const ll l) {
        return (*this) += ModInt(l);
    }
    ModInt operator-=(const ll l) {
        return (*this) -= ModInt(l);
    }
    ModInt operator*=(const ll l) {
        return (*this) *= ModInt(l);
    }
    ModInt operator/=(const ll l) {
        return (*this) /= ModInt(l);
    }
    ModInt operator+(const ModInt &m) {
        auto t = *this;
        return t += m;
    }
    ModInt operator-(const ModInt &m) {
        auto t = *this;
        return t -= m;
    }
    ModInt operator*(const ModInt &m) {
        auto t = *this;
        return t *= m;
    }
    ModInt operator/(const ModInt &m) {
        auto t = *this;
        return t /= m;
    }
    ModInt operator+(const ll l) {
        auto t = *this;
        return t += l;
    }
    ModInt operator-(const ll l) {
        auto t = *this;
        return t -= l;
    }
    ModInt operator*(const ll l) {
        auto t = *this;
        return t *= l;
    }
    ModInt operator/(const ll l) {
        auto t = *this;
        return t /= l;
    }
    ModInt operator=(const ll l) {
        n = l % MOD;
        if (n < 0) {
            n += MOD;
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const ModInt &m) {
        out << m.n;
        return out;
    }
    friend istream &operator>>(istream &in, ModInt &m) {
        ll l;
        in >> l;
        m = l;
        return in;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--;
    T--;
    vector<vector<P>> G(N);

    REP(i, 0, M) {
        int U, V;
        ll D;
        cin >> U >> V >> D;
        U--;
        V--;
        G[U].push_back({2 * D, V});
        G[V].push_back({2 * D, U});
    }

    auto dijkstra = [&](int s, vector<ll> &cost, vector<ModInt<>> &comb) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(0, s);
        vector<bool> used(N, false);
        comb[s] = 1;
        while (pq.size()) {
            ll dist = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();
            if (used[vertex]) continue;
            cost[vertex] = dist;
            used[vertex] = true;
            for (auto &edge : G[vertex]) {
                ll ndist = edge.first;
                int nvertex = edge.second;
                if (cost[nvertex] == dist + ndist) {
                    comb[nvertex] += comb[vertex];
                } else if (cost[nvertex] > dist + ndist) {
                    cost[nvertex] = dist + ndist;
                    comb[nvertex] = comb[vertex];
                    pq.emplace(cost[nvertex], nvertex);
                }
            }
        }
    };

    const ll inf = 1LL << 60;
    vector<ll> Cost1(N, inf), Cost2(N, inf);
    vector<ModInt<>> Comb1(N, 0), Comb2(N, 0);
    dijkstra(S, Cost1, Comb1);
    dijkstra(T, Cost2, Comb2);

    auto ans = Comb1[T] * Comb1[T];
    ll stpath = Cost1[T];

    // vertex
    REP(i, 0, N) {
        if (2 * Cost1[i] == stpath && 2 * Cost2[i] == stpath) {
            ans -= Comb1[i] * Comb1[i] * Comb2[i] * Comb2[i];
        }
    }

    // edges
    REP(i, 0, N) {
        for (auto &edge : G[i]) {
            if (2 * Cost1[i] < stpath && 2 * Cost2[edge.second] < stpath && Cost1[i] + edge.first + Cost2[edge.second] == stpath) {
                ans -= Comb1[i] * Comb1[i] * Comb2[edge.second] * Comb2[edge.second];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
