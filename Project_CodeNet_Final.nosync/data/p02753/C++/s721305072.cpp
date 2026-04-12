#ifndef COMPETITIVE_ARITHMETIC_H
#define COMPETITIVE_ARITHMETIC_H
#ifdef BUILT_LOCAL

#include "niklib.h"

#endif

#include <utility>
#include <map>

namespace arithmetic {
    class utils {
    private:
    public:

        template<typename T>
        static T gcd(T a, T b);

        template<typename T>
        static std::pair<T, T> extgcd(std::pair<T, T> a);

        template<typename T>
        static T combination(T n, T k);
    };

    template<typename T>
    class modulo {
    private:
        T n = 0;
    public:
        T mod = 1000000007;

        explicit modulo(T n_, T mod_);

        explicit modulo(T n_);

        explicit modulo();

        explicit operator T() const;

        modulo operator+(modulo e);

        modulo operator-(modulo e);

        modulo operator*(modulo e);

        modulo operator/(modulo e);

        bool operator==(modulo e) const;

        bool operator<(modulo e) const;
    };
}
#endif //COMPETITIVE_ARITHMETIC_H
#ifndef COMPETITIVE_GRAPH_H
#define COMPETITIVE_GRAPH_H

#include <map>
#include <set>
#include <utility>
#include <queue>

template<typename T>
class djikstra {
private:
    std::map<T, std::set<std::pair<T, T>>> path; //src dst cost
    std::map<T, T> dist; //dst cost
public:
    void compute(T start);

    void add_path(T src, T dst, T cost);

    T get_dist(T dst);
};

#endif //COMPETITIVE_GRAPH_H

#ifndef COMPETITIVE_NIKLIB_H
#define COMPETITIVE_NIKLIB_H

#ifdef BUILT_LOCAL

#include "graph.h"
#include "arithmetic.h"

#endif

#endif //COMPETITIVE_NIKLIB_H

#ifdef BUILT_LOCAL

#include "arithmetic.h"

#endif

template<typename T>
T arithmetic::utils::gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template<typename T>
std::pair<T, T> arithmetic::utils::extgcd(std::pair<T, T> a) {
    if (a.second == 0) return std::make_pair(a.first, 0);
    auto t = extgcd(std::make_pair(a.second, a.first % a.second));
    return std::make_pair(t.second, t.first - t.second * (a.first / a.second));
}

template<typename T>
T arithmetic::utils::combination(T n, T k) {
    if (k == T(0)) return T(1);
    return (combination(n - T(1), k - T(1)) * n) / k;
}

template<typename T>
arithmetic::modulo<T>::modulo(T n_, T mod_) {
    mod = mod_;
    n = ((n_ % mod) + mod) % mod;
}

template<typename T>
arithmetic::modulo<T>::modulo(T n_) {
    n = ((n_ % mod) + mod) % mod;
}

template<typename T>
arithmetic::modulo<T>::modulo() {
    n = 0;
}


template<typename T>
arithmetic::modulo<T>::operator T() const {
    return n % mod;
}


template<typename T>
arithmetic::modulo<T> arithmetic::modulo<T>::operator+(modulo<T> e) {
    return modulo((n + (T) e) % mod, mod);
}

template<typename T>
arithmetic::modulo<T> arithmetic::modulo<T>::operator-(modulo<T> e) {
    return modulo((n - (T) e) % mod, mod);
}

template<typename T>
arithmetic::modulo<T> arithmetic::modulo<T>::operator*(modulo<T> e) {
    return modulo((n * (T) e) % mod, mod);
}

template<typename T>
arithmetic::modulo<T> arithmetic::modulo<T>::operator/(modulo<T> e) {
    return modulo(((n * utils::extgcd(std::make_pair((T) e, -mod)).first)) % mod, mod);
}

template<typename T>
bool arithmetic::modulo<T>::operator==(modulo<T> e) const {
    return n == (T) e && mod == e.mod;
}

template<typename T>
bool arithmetic::modulo<T>::operator<(modulo<T> e) const {
    return n == (T) e ? mod < e.mod : n < (T) e;
}

template
class arithmetic::modulo<long long>;

template arithmetic::modulo<long long>
arithmetic::utils::combination(arithmetic::modulo<long long> n, arithmetic::modulo<long long> k);

template std::pair<long long, long long> arithmetic::utils::extgcd(std::pair<long long, long long> a);

#ifdef BUILT_LOCAL

#include "graph.h"

#endif

template<typename T>
void djikstra<T>::compute(T start) {
    dist.clear();
    dist[start] = 0;
    std::priority_queue<std::pair<T, T>, std::deque<std::pair<T, T>>, std::greater<>> q;
    for (auto &e:path[start]) q.push(std::make_pair(e.second, e.first));
    while (!q.empty()) {
        auto c = q.top();
        q.pop();
        if (dist.find(c.second) != dist.end()) continue;
        dist[c.second] = c.first;
        for (auto &e:path[c.second]) {
            if (dist.find(e.first) != dist.end()) continue;
            q.push(std::make_pair(c.first + e.second, e.first));
        }
    }
}

template<typename T>
void djikstra<T>::add_path(T src, T dst, T cost) {
    path[src].insert(std::make_pair(dst, cost));
}

template<typename T>
T djikstra<T>::get_dist(T dst) {
    return dist.find(dst) == dist.end() ? -1 : dist[dst];
}

template
class djikstra<long long>;

#ifdef BUILT_LOCAL

#include "niklib.h"

#endif

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef long long ll;
constexpr ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    cout << ((s[0] == s[1] && s[1] == s[2]) ? "No" : "Yes") << endl;
}