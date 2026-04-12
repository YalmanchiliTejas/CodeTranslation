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
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

// others
#include <random>
#include <limits>
#include <functional>
#include <ctime>
#include <cassert>

// type alias
using lint = long long;
using ldouble = long double;
template <class T>
using greater_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

/* ----- class ----- */

template <class Cost = int>
struct Edge {
    int from, to;
    Cost cost;
    Edge(int from = -1, int to = -1, Cost cost = 1)
        : from(from), to(to), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Edges = std::vector<Edge<Cost>>;

template <class Cost = int>
class Graph {
public:
    int size;
    std::vector<std::vector<Edge<Cost>>> path;

    explicit Graph(int N = 0) : size(N), path(size) {}
    void span(int from, int to, Cost cost = 1) {
        path[from].push_back(Edge<Cost>(from, to, cost));
    }
    std::vector<Edge<Cost>>& operator[](int v) { return path[v]; }
};

/* ----- Output Functions for Debugging ----- */

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v);
template <class T>
std::ostream& operator<<(std::ostream& os, std::set<T> v);
template <class L, class R>
std::ostream& operator<<(std::ostream& os, std::pair<L, R> p);
template <class K, class T>
std::ostream& operator<<(std::ostream& os, std::map<K, T> v);
template <class T>
std::ostream& operator<<(std::ostream& os, std::stack<T> s);
template <class T>
std::ostream& operator<<(std::ostream& os, std::queue<T> q);
template <class T>
std::ostream& operator<<(std::ostream& os, std::priority_queue<T> q);
template <class T>
std::ostream& operator<<(std::ostream& os, std::priority_queue<T, std::vector<T>, std::greater<T>> q);
template <class T>
std::ostream& operator<<(std::ostream& os, Edge<T> e);

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    os << "[";
    for (auto vv : v) os << vv << ",";
    return os << "]";
}
template <class T>
std::ostream& operator<<(std::ostream& os, std::set<T> v) {
    os << "{";
    for (auto vv : v) os << vv << ",";
    return os << "}";
}
template <class L, class R>
std::ostream& operator<<(std::ostream& os, std::pair<L, R> p) {
    return os << "(" << p.first << "," << p.second << ")";
}
template <class K, class T>
std::ostream& operator<<(std::ostream& os, std::map<K, T> v) {
    os << "{";
    for (auto vv : v) os << vv << ",";
    return os << "}";
}
template <class T>
std::ostream& operator<<(std::ostream& os, std::stack<T> s) {
    os << "[";
    while (!s.empty()) {
        os << s.top() << ",";
        s.pop();
    }
    return os << "]";
}
template <class T>
std::ostream& operator<<(std::ostream& os, std::queue<T> q) {
    os << "[";
    while (!q.empty()) {
        os << q.front() << ",";
        q.pop();
    }
    return os << "]";
}
template <class T>
std::ostream& operator<<(std::ostream& os, std::priority_queue<T> q) {
    os << "{";
    while (!q.empty()) {
        os << q.top() << ",";
        q.pop();
    }
    return os << "}";
}
template <class T>
std::ostream& operator<<(std::ostream& os, std::priority_queue<T, std::vector<T>, std::greater<T>> q) {
    os << "{";
    while (!q.empty()) {
        os << q.top() << ",";
        q.pop();
    }
    return os << "}";
}
template <class T>
std::ostream& operator<<(std::ostream& os, Edge<T> e) {
    return os << "(" << e.from << "->" << e.to << ":" << e.cost << ")";
}

/* ----- Short Functions ----- */

template <class T>
inline T sq(T a) { return a * a; }

template <class T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

template <class T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template <class T, class U>
T ipow(T b, U n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= b;
        n >>= 1;
        b *= b;
    }
    return ret;
}

// 0-indexed
template <class T, class U>
inline T kthbit(T a, U k) { return (a >> k) & 1; }

template <class T, class U>
inline T mask(T a, U k) { return a & ((1 << k) - 1); }

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < v.size(); ++i) rev[v[i]] = i;
    return rev;
}

template <class T>
T Vec(T v) { return v; }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return std::vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

/* ----- Constants ----- */

// const int INF = std::numeric_limits<int>::max() / 3;
// const ll INF = std::numeric_limits<ll>::max() / 3;
// const ld PI = acos(-1);
// const ld EPS = 1e-10;
// std::mt19937 mt(int(std::time(nullptr)));

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (auto& h : H) cin >> h;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        bool judge = true;
        for (int j = 0; j < i; ++j) {
            if (H[j] > H[i]) judge = false;
        }
        if (judge) ++ans;
    }

    cout << ans << endl;
    return 0;
}
