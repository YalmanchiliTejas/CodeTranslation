#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <numeric>
#include <string>
#include <bitset>
#include <functional>

using ld = long double;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using ll = int;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using str = std::string;
using vstr = std::vector<str>;

template<typename T> bool chmin(T a, T &b) { return a < b ? b = a, true : false; }
template<typename T> bool chmax(T a, T &b) { return a > b ? b = a, true : false; }

constexpr ld PI = 3.141592653589793L;
constexpr ld EPS = std::numeric_limits<ld>::epsilon();

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }
bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

/*------------------------------------------------------------------------*/

struct edge {
    ll cost, from, to;

    edge(ll &c, ll &f, ll &t) : cost(c), from(f), to(t) {  }

    bool operator<(edge &x) { return cost < x.cost; }
    bool operator>(edge &x) { return cost > x.cost; }
    bool operator==(edge &x) { return cost == x.cost; }
};

struct union_find {
    vll data;

    union_find(ll &size) : data(size, -1) {  }

    ll root(ll &x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    bool merge(ll x, ll y) {
        if ((x = root(x)) == (y = root(y))) return false;

        if (data[x] > data[y]) std::swap(x, y);

        data[x] += data[y], data[y] = x;

        return true;
    }
};

void solve();

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15);

    solve();
}

void solve() {
    ll n;
    std::cin >> n;

    std::vector<pll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        std::cin >> x[i].first >> y[i].first;
        x[i].second = y[i].second = i;
    }

    auto compare = [](pll &a, pll &b) {
        return a.first != b.first ? a.first < b.first
                                  : a.second < b.second;
    };
    std::sort(x.begin(), x.end(), compare);
    std::sort(y.begin(), y.end(), compare);

    std::deque<edge> es;
    for (ll i = 0; i < n - 1; i++) {
        ll cost_x = x[i + 1].first - x[i].first;
        ll cost_y = y[i + 1].first - y[i].first;
        es.push_back(edge(cost_x, x[i].second, x[i + 1].second));
        es.push_back(edge(cost_y, y[i].second, y[i + 1].second));
    }

    auto kruskal = [&]() {
        std::sort(es.begin(), es.end());

        ll res = 0; union_find uf(n);
        for (edge e : es) if (uf.merge(e.from, e.to))
            res += e.cost;

        return res;
    };

    std::cout << kruskal() << '\n';
}
