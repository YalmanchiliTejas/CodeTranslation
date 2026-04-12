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
// constexpr Int INF = std::numeric_limits<Int>::max() / 3;
// constexpr Int MOD = 1000000007;
// constexpr Real PI = acos(-1);
// constexpr Real EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));

int main() {
    Int m;
    std::cin >> m;

    for (Int i = 0; i < m; ++i) {
        Int init, year, n;
        std::cin >> init >> year >> n;

        Int ans = 0;
        for (Int j = 0; j < n; ++j) {
            Int type, cost;
            Real per;
            std::cin >> type >> per >> cost;

            Int money = init, gain = 0;
            for (Int t = 0; t < year; ++t) {
                gain += money * per;
                if (type == 1) {
                    money += gain;
                    gain = 0;
                }
                money -= cost;
            }

            ans = std::max(ans, money + gain);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

