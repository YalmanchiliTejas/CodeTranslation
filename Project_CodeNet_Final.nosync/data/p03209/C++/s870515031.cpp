#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;
const int kmax = 510000;
const int last_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

long long fact[kmax], fact_inv[kmax], inv[kmax];

void init_comb()
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < kmax; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int r)
{
    if (n < r) {
        return 0;
    }

    if (n < 0 || r < 0) {
        return 0;
    }

    return fact[n] * (fact_inv[r] * fact_inv[n - r] % mod) % mod;
}

template <typename T, T N>
class UnionFind {
    T parent_[N];
    T rank_[N];
    T size_[N];

public:
    UnionFind();
    T Root(T idx);
    bool IsSame(T x, T y);
    void Unite(T x, T y);
    T GetSize(T idx);
};

template <typename T, T N>
UnionFind<T, N>::UnionFind()
{
    for (T i = 0; i < N; i++) {
        parent_[i] = i;
        rank_[i] = 0;
        size_[i] = 1;
    }
}

template <typename T, T N>
T UnionFind<T, N>::Root(T idx)
{
    return parent_[idx] == idx ? idx : parent_[idx] = Root(parent_[idx]);
}

template <typename T, T N>
bool UnionFind<T, N>::IsSame(T x, T y)
{
    return Root(x) == Root(y);
}

template <typename T, T N>
void UnionFind<T, N>::Unite(T x, T y)
{
    x = Root(x);
    y = Root(y);
    if (x == y) {
        return;
    }

    if (rank_[x] < rank_[y]) {
        parent_[x] = y;
        size_[y] += size_[x];
    } else {
        parent_[y] = x;
        size_[x] += size_[y];
        if (rank_[x] == rank_[y]) {
            rank_[x]++;
        }
    }
}

template <typename T, T N>
T UnionFind<T, N>::GetSize(T idx)
{
    return size_[Root(idx)];
}

template <typename T>
T pow_mod(T n, T p, T m)
{
    if (p == 0) {
        return 1;
    }

    if (p % 2 == 0) {
        T t = pow_mod(n, p / 2, m);
        return t * t % m;
    }
    return n * pow_mod(n, p - 1, m) % mod;
}

template <typename T>
T nCr_mod(T n, T r)
{
    T x = 1;
    for (T i = n - r + 1; i <= n; i++) {
        x *= i;
        x %= mod;
    }

    T a = 1;
    for (T i = 1; i <= r; i++) {
        a *= i;
        a %= mod;
    }

    T y = pow_mod(a, mod - 2, mod) % mod;

    return x * y % mod;
}

template <typename T>
bool is_prime(T n)
{
    if (n == 1) {
        return false;
    }

    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool is_leap(T y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

template <typename T>
void next_day(T& y, T& m, T& d)
{
    d++;

    if (d > last_days[m - 1] + (m == 2 && is_leap(y) ? 1 : 0)) {
        d = 1;
        m++;
    }

    if (m > 12) {
        y++;
        m = 1;
    }
}

template <typename T>
T fib(T n)
{
    T a = 0, b = 1;
    for (T i = 0; i < n; i++) {
        T t = a;
        a = b;
        b = a + t;
    }

    return a;
}

// Note that the order of this function is O(n**n).
template <typename T>
std::vector<size_t> calculate_ranks(const std::vector<T>& v)
{
    std::vector<T> sorted = v;

    std::sort(sorted.begin(), sorted.end());

    std::map<T, long long> m;
    for (auto i = 0LU; i < v.size(); i++) {
        m.insert(std::make_pair(sorted[i], i));
    }

    std::vector<size_t> rank(v.size());

    for (auto i = 0LU; i < v.size(); i++) {
        rank[i] = m.find(v[i])->second + 1;
    }

    return rank;
}

template <typename T>
std::map<T, T> prime_factors_and_num(T n)
{
    std::map<T, T> m;
    for (T i = 2; i <= n; i++) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }

    return m;
}

inline long long calculate_sum(const std::vector<long long>& v)
{
    return std::accumulate(v.begin(), v.end(), 0LL);
}

template <typename T, T N>
class Graph {
    std::vector<std::vector<T>> weights_;
    std::vector<T> predecessors_;
    std::vector<T> shortest_path_estimate_;
    std::vector<std::vector<T>> edges_;

    void InitializeSingleSource(T start);
    void Relax(T v, T u);

public:
    Graph(std::vector<std::vector<T>> weights, std::vector<std::vector<T>> edges);
    Graph(std::vector<std::vector<T>> weights, T inf);

    T BellmanFord(T start, T end);
    T Dijkstra(T start, T end);
};

template <typename T, T N>
Graph<T, N>::Graph(std::vector<std::vector<T>> weights, std::vector<std::vector<T>> edges)
{
    weights_ = weights;
    predecessors_ = std::vector<T>(N, -1);
    shortest_path_estimate_ = std::vector<T>(N, mod);
    edges_ = edges;
}

template <typename T, T N>
Graph<T, N>::Graph(std::vector<std::vector<T>> weights, T inf)
{
    weights_ = weights;
    predecessors_ = std::vector<T>(N, -1);
    shortest_path_estimate_ = std::vector<T>(N, inf);
    edges_ = std::vector<std::vector<T>>(N, std::vector<T>());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (weights_[i][j] != inf) {
                edges_[i].push_back(j);
            }
        }
    }
}

template <typename T, T N>
void Graph<T, N>::InitializeSingleSource(T start)
{
    for (int i = 0; i < N; i++) {
        shortest_path_estimate_[i] = mod;
        predecessors_[i] = -1;
    }

    shortest_path_estimate_[start] = 0;
}

template <typename T, T N>
void Graph<T, N>::Relax(T u, T v)
{
    if (shortest_path_estimate_[v] > shortest_path_estimate_[u] + weights_[u][v]) {
        shortest_path_estimate_[v] = shortest_path_estimate_[u] + weights_[u][v];
        predecessors_[v] = u;
    }
}

template <typename T, T N>
T Graph<T, N>::BellmanFord(T start, T end)
{
    InitializeSingleSource(start);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            for (auto edge : edges_[j]) {
                Relax(j, edge);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (auto edge : edges_[i]) {
            if (shortest_path_estimate_[edge] > shortest_path_estimate_[i] + weights_[i][edge]) {
                fprintf(stderr, "Graph contains negative circle!\n");
                exit(1);
            }
        }
    }

    return shortest_path_estimate_[end];
}

template <typename T, T N>
T Graph<T, N>::Dijkstra(T start, T end)
{
    InitializeSingleSource(start);
    std::set<T> s;

    auto compare_d = [=](const T& x, const T& y) {
        return shortest_path_estimate_[x] > shortest_path_estimate_[y];
    };

    std::priority_queue<T, std::vector<T>, decltype(compare_d)> q(compare_d);
    for (int i = 0; i < N; i++) {
        q.push(i);
    }

    while (q.size()) {
        T u = q.top();
        q.pop();
        s.insert(u);
        for (auto v : edges_[u]) {
            Relax(u, v);
        }
    }

    return shortest_path_estimate_[end];
}

int main()
{
    long long n, x;
    std::cin >> n >> x;

    std::vector<long long> dp(n + 1, 1);
    std::vector<long long> pate(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * 2 + 3;
        pate[i] = pate[i - 1] * 2 + 1;
    }

    auto f = [=](auto f, long long n, long long x) -> long long {
        if (n == 0) {
            return x <= 0 ? 0 : 1;
        }

        if (x <= n) {
            return 0;
        }

        if (x <= 1 + dp[n - 1]) {
            return f(f, n - 1, x - 1);
        }

        return pate[n - 1] + 1 + f(f, n - 1, x - 2 - dp[n - 1]);
    };

    std::cout << f(f, n, x) << std::endl;
}
