#include <bits/stdc++.h>
#define range(i, l, r) for(int (i) = (l); (i) < (r); (i)++)
#define reversed_range(i, l, r) for (int (i) = (r) - 1; (i) >= l; (i)--)
using namespace std;
template <typename T>
using vec = vector<T>;
using lint = long long;
using ulint = unsigned long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;

template <typename S, typename T>
ostream& operator <<(ostream& os, pair<S, T> p) {
    os << "(";
    os << p.first << ", " << p.second;
    return os << ")";
}

template <typename T>
ostream& operator <<(ostream& os, vec<T> v) {
    os << "[";
    for (int i = 0; i < v.size() - 1; i++) {
        os << v.at(i) << ", ";
    }
    return os << v.at(v.size() - 1) << "]";
}

template <typename T>
ostream& operator <<(ostream& os, set<T>& s) {
    os << "{";
    auto it_first_item = s.begin();
    cout << *it_first_item;
    for (auto it = ++it_first_item; it != s.end(); it++) {
        cout << ", " << *it;
    }
    return cout << "}";
}

template <typename T>
ostream& operator <<(ostream& os, unordered_set<T>& s) {
    os << "{";
    auto it_first_item = s.begin();
    cout << *it_first_item;
    for (auto it = ++it_first_item; it != s.end(); it++) {
        cout << ", " << *it;
    }
    return cout << "}";
}

template <typename K, typename V>
ostream& operator <<(ostream& os, map<K, V> m) {
    os << "{";
    auto it_first_item = m.begin();
    cout << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        cout << ", " << it->first << ": " << it->second;
    }
    return os << "}";
}

template <typename K, typename V>
ostream& operator <<(ostream& os, unordered_map<K, V> m) {
    os << "{";
    auto it_first_item = m.begin();
    cout << it_first_item->first << ": " << it_first_item->second;
    for (auto it = ++it_first_item; it != m.end(); it++) {
        cout << ", " << it->first << ": " << it->second;
    }
    return os << "}";
}

lint pow(lint num, int e, lint MOD) {
    lint result = 1;
    lint cur_num = num;
    while (e) {
        if (e & 1) {
            result *= cur_num;
            result %= MOD;
        }
        cur_num *= cur_num;
        cur_num %= MOD;
        e >>= 1;
    }
    return result;
}

const lint MOD = 1e9 + 7;
const lint max_num_grids = 2 * 1e5;
int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    lint N, M, K;
    cin >> N >> M >> K;
    vec<lint> factorial(max_num_grids + 1);
    factorial.at(0) = 1;
    range(i, 1, max_num_grids + 1) {
        factorial.at(i) = factorial.at(i - 1) * (lint)i % MOD;
    }
    vec<lint> inv_factorial(max_num_grids + 1);
    range(i, 0, max_num_grids + 1) {
        inv_factorial.at(i) = pow(factorial.at(i), MOD - 2, MOD);
    }

    lint res = 0;
    range(d, 0, N) {
        res += d * ((N - d) * M * M) % MOD;
        res %= MOD;
    }
    range(d, 0, M) {
        res += d * ((M - d) * N * N) % MOD;
        res %= MOD;
    }
    // cout << res << "\n";
    res = res * factorial.at(N * M - 2) % MOD * inv_factorial.at(N * M - K) % MOD * inv_factorial.at(K - 2);
    res %= MOD;
    cout << res << "\n";
}
