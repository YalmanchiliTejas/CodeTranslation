#if __has_include("../library/Basic/Debug.hpp")

#include "../library/Basic/Debug.hpp"

#else

/* ----- Header Files ----- */
// IO
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm
#include <algorithm>
#include <cmath>
#include <numeric>

// container
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>

// others
#include <random>
#include <limits>
#include <functional>
#include <ctime>
#include <cassert>
#include <cstdint>


/* ----- Type Alias ----- */
using Bool = bool;
using Int = long long int;
using Real = long double;
using Char = char;
using String = std::string;
template <class... Ts>
using Tuple = std::tuple<Ts...>;

template <class T>
using Vector = std::vector<T>;
template <class T>
using Matrix = Vector<Vector<T>>;
template <class T>
using Queue = std::queue<T>;
template <class T>
using Stack = std::stack<T>;
template <class T>
using Deque = std::deque<T>;

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using Set = std::set<T>;
template <class T, class U>
using Map = std::map<T, U>;

template <class T, class... Us>
using Func = std::function<T(Us...)>;

template <class T>
T genv(T v) { return v; }

template <class T, class... Ts>
auto genv(size_t l, Ts... ts) {
    return Vector<decltype(genv<T>(ts...))>(l, genv<T>(ts...));
}

template <class Cost = Int>
struct Edge {
    Int src, dst;
    Cost cost;
    Edge(Int src = -1, Int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = Int>
using Edges = Vector<Edge<Cost>>;
template <class Cost = Int>
using Graph = Vector<Vector<Edge<Cost>>>;

#endif

/* ----- Misc ----- */
void fastio() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

struct Fout {
    Int precision;
    Fout(Int precision) : precision(precision) {}
};
std::ostream& operator<<(std::ostream& os, const Fout& fio) {
    os << std::fixed << std::setprecision(fio.precision);
    return os;
}


/* ----- Constants ----- */
// constexpr Int INF = std::numeric_limits<Int>::max() / 3;
// constexpr Int MOD = 1000000007;
// constexpr Real PI = acos(-1);
// constexpr Real EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));

struct UnionFind {
    Vector<Int> par;

    UnionFind(Int n) : par(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    Int find(Int v) {
        return par[v] == v ? v : par[v] = find(par[v]);
    }

    void unite(Int u, Int v) {
        u = find(u), v = find(v);
        par[v] = u;
    }
};

Map<Int, Int> compress(Vector<Int>& xs) {
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    Map<Int, Int> rev;
    for (Int i = 0; i < xs.size(); ++i) rev[xs[i]] = i;
    return rev;
}

Bool solve() {
    Int n;
    std::cin >> n;
    if (n == 0) return false;

    Vector<Int> lx(n), rx(n), ly(n), ry(n);
    Vector<Int> xs{-1, 1000001}, ys{-1, 1000001};
    for (Int i = 0; i < n; ++i) {
        std::cin >> lx[i] >> ry[i] >> rx[i] >> ly[i];
        xs.push_back(lx[i]), xs.push_back(rx[i]);
        ys.push_back(ly[i]), ys.push_back(ry[i]);
    }

    Int h, w;
    {
        auto revx = compress(xs), revy = compress(ys);
        h = xs.size(), w = ys.size();
        for (auto& x : lx) x = revx[x];
        for (auto& x : rx) x = revx[x];
        for (auto& y : ly) y = revy[y];
        for (auto& y : ry) y = revy[y];
    }

    Matrix<Int> imos(h, Vector<Int>(w, 0));
    for (Int i = 0; i < n; ++i) {
        imos[lx[i]][ly[i]] += (1LL << i);
        imos[lx[i]][ry[i]] -= (1LL << i);
        imos[rx[i]][ly[i]] -= (1LL << i);
        imos[rx[i]][ry[i]] += (1LL << i);
    }

    for (Int x = 0; x < h; ++x) {
        for (Int y = 1; y < w; ++y) {
            imos[x][y] += imos[x][y - 1];
        }
    }
    for (Int y = 0; y < w; ++y) {
        for (Int x = 1; x < h; ++x) {
            imos[x][y] += imos[x - 1][y];
        }
    }

    UnionFind uf(h * w);
    for (Int x = 0; x < h; ++x) {
        for (Int y = 0; y < w; ++y) {
            for (Int d = 0; d <= 1; ++d) {
                Int nx = x + d, ny = y + (1 - d);
                if (nx >= h || ny >= w) continue;

                if (imos[x][y] == imos[nx][ny]) {
                    uf.unite(x * w + y, nx * w + ny);
                }
            }
        }
    }

    Set<Int> gs;
    for (Int v = 0; v < h * w; ++v) {
        gs.insert(uf.find(v));
    }

    std::cout << gs.size() << std::endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}

