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
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

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
template <class T, class U>
using Pair = std::pair<T, U>;
template <class... Ts>
using Tuple = std::tuple<Ts...>;

template <class T>
using Vector = std::vector<T>;
template <size_t N>
using Bits = std::bitset<N>;
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
constexpr Real INF = std::numeric_limits<Real>::max() / 10;
// constexpr Int INF = std::numeric_limits<Int>::max() / 3;
// constexpr Int MOD = 1000000007;
const Real PI = std::acos(-1);
// constexpr Real EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));

template <class T>
T sq(T x) { return x * x; }

using Point = std::complex<Real>;
using Segment = std::pair<Point, Point>;
using Polygon = std::vector<Point>;

Bool operator<(const Point& a, const Point& b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}

std::istream& operator>>(std::istream& is, Point& p) {
    Real x, y;
    is >> x >> y;
    p = Point(x, y);
    return is;
}

constexpr Real EPS = 1e-10;

// 宇宙船演算子
Int compare(Real a, Real b) {
    if (std::abs(a - b) < EPS) return 0;
    return a - b > 0 ? 1 : -1;
}

Real dist(Point a, Point b) {
    return std::abs(a - b);
}

Real length(Segment s) {
    return dist(s.first, s.second);
}

// inner product
Real dot(Point x, Point y) {
    return std::real(std::conj(x) * (y));
}

// outer product
Real cross(Point x, Point y) {
    return std::imag(std::conj(x) * (y));
}

// lに対するxの正射影
Point proj(Segment s, Point p) {
    Real ratio = dot(s.second - s.first, p - s.first) / sq(length(s));
    return s.first + (s.second - s.first) * ratio;
}

// lに対するpの位置
// 0: on segment
// 1: counter clockwise  -1: clockwise
// 2: online front       -2: online back
Int side(Segment s, Point p) {
    Real c = cross(s.second - s.first, p - s.first);
    if (compare(c, 0) != 0) return compare(c, 0);

    Real d = dot(s.second - s.first, p - s.first);
    if (compare(d, 0) < 0) return -2;

    return (compare(length(Segment(s.first, p)), length(s)) > 0 ? 2 : 0);
}

// bound: 線分の端点を含むか
Bool intersect(Segment s1, Segment s2, Bool bound) {
    return (side(s1, s2.first) * side(s1, s2.second) < bound) &&
           (side(s2, s1.first) * side(s2, s1.second) < bound);
}

Real dist(Segment s, Point p) {
    Point t = proj(s, p);
    if (side(s, t) == 0) return dist(p, t);
    return std::min(dist(p, s.first), dist(p, s.second));
}

Real dist(Segment s1, Segment s2) {
    if (intersect(s1, s2, true)) return 0;
    return std::min({dist(s1, s2.first),
                     dist(s1, s2.second),
                     dist(s2, s1.first),
                     dist(s2, s1.second)});
}


Bool solve() {
    Int n, s, g;
    std::cin >> n >> s >> g;
    if (n == 0) return false;

    --s, --g;
    s *= 5, g *= 5;

    Vector<Segment> segs(n * 5);
    for (Int i = 0; i < n; ++i) {
        Real x, y, theta, r;
        std::cin >> x >> y >> theta >> r;

        for (Int j = 0; j < 5; ++j) {
            segs[i * 5 + j].first =
                std::polar(r, (theta + j * 72 + 90) / 180 * PI) + Point(x, y);
            segs[i * 5 + j].second =
                std::polar(r, (theta + (j + 2) * 72 + 90) / 180 * PI) + Point(x, y);
        }
    }

    Vector<Vector<Real>> d(n * 5, Vector<Real>(n * 5, INF));
    for (Int u = 0; u < n * 5; ++u) {
        for (Int v = 0; v < n * 5; ++v) {
            d[u][v] = dist(segs[u], segs[v]);
        }
    }

    Vector<Real> dp(n * 5, INF);
    dp[s] = 0;
    MinHeap<Tuple<Real, Int>> heap;
    heap.emplace(0, s);

    while (!heap.empty()) {
        Real x;
        Int v;
        std::tie(x, v) = heap.top();
        heap.pop();
        if (compare(x, dp[v]) > 0) continue;

        for (Int u = 0; u < n * 5; ++u) {
            if (compare(dp[u], dp[v] + d[v][u]) <= 0) continue;
            dp[u] = dp[v] + d[v][u];
            heap.emplace(dp[u], u);
        }
    }

    std::cout << Fout(20) << dp[g] << std::endl;
    return true;
}

int main() {
    while (solve()) {}
    return 0;
}

