#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i < (int)vec.size(); ++i) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
    os << "{";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
void dump_func() {
    cerr << "\n";
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) == 0) {
        cerr << " ";
    } else {
        cerr << ", ";
    }
    dump_func(std::move(tail)...);
}
#define dump(...) cerr << "[" << to_string(__LINE__) << "]"        \
                       << "    " << string(#__VA_ARGS__) << " = ", \
                  dump_func(__VA_ARGS__)

using ll = long long;
using ld = long double;
using VI = vector<int>;
using VL = vector<double>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PI = pair<int, int>;
using PL = pair<ll, ll>;
using VPI = vector<PI>;
using VPL = vector<PL>;
using VS = vector<string>;

#define ln '\n'
#define REP(t, n) for (int t = 0; t < (n); ++t)
#define FOR(t, a, b) for (int t = (a); t <= (b); ++t)
#define FORR(t, a, b) for (int t = (a); t >= (b); --t)
#define ALL(c) (c).begin(), (c).end()
#define CAUTO const auto&

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << "Yes" << ln;
    } else {
        cout << "No" << ln;
    }

    return 0;
}
