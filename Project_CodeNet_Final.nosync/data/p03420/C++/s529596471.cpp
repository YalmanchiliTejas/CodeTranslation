#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>

using namespace std;

constexpr int MOD = 1000000007;

using Long = long long;
template<typename T>
using V = vector<T>;
template<typename T>
using Vv = V<V<T>>;
using Vb = V<bool>;
using Vvb = V<Vb>;
using Vi = V<int>;
using Vvi = V<Vi>;
using Vl = V<Long>;
using Vvl = V<Vl>;
using Vd = V<double>;
using Vvd = V<Vd>;
using Vs = V<string>;

template<typename T>
T read() {
    T res;
    cin >> res;
    return res;
}

template<typename T>
V<T> readV(int n) {
    V<T> res((size_t) n);
    for (int i = 0; i < n; ++i) {
        res[i] = read<T>();
    }
    return res;
}

template<typename T>
Vv<T> readVv(int n, int m) {
    Vv<T> res((size_t) n, V<T>((size_t) m));
    for (int i = 0; i < n; ++i) {
        res[i] = readV<T>(m);
    }
    return res;
}

// *** SOLUTION BEGIN ***

void solve() {
    int n, k;
    cin >> n >> k;
    Long ans = (Long)n * k;
    for (int b = k + 1; b <= n; ++b) {
        ans += max(0LL, k * Long((n + 1) / b) + min((n + 1) % b, k) - 1);
    }
    ans = (Long)n * n - ans;
    cout << ans;
}

// *** SOLUTION END ***

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}
