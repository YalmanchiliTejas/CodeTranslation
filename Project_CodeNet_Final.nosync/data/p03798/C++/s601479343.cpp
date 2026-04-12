#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
// template<class T> T gabs(const T& x) { return max(x, -x); }
// #define abs gabs

i64 n;
string s;

// false: S, true: W
vector<bool> f(bool c, bool d) {
    vector<bool> t(n);
    t[0] = c;
    t[1] = d;
    for (int i = 1; i < n + 1; ++i) {
        int l = (i - 1 + n) % n, m = i % n, r = (i + 1) % n;
        bool a = s[m] == 'x';
        bool b = a ^ t[m];
        bool x = b ^ t[l];
        if (i >= n - 1) {
            if (t[r] != x) {
                return vector<bool>();
            }
        } else {
            t[r] = x;
        }
    }
    return t;
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            auto t = f(i, j);
            if (!t.empty()) {
                for (int i = 0; i < n; ++i) {
                    cout << "SW"[t[i]];
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}