#include <bits/stdc++.h>

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

template <typename First, typename Second>
istream& operator>>(istream& is, pair<First, Second>& v);

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <typename First, typename Second>
istream& operator>>(istream& is, pair<First, Second>& v) {
    is >> v.first >> v.second;
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (const auto& x : v) {
        os << x << ' ';
    }
    return os;
}

// *** SOLUTION BEGIN ***

void solve() {
    int n;
    cin >> n;
    Vi a(n);
    cin >> a;
    Vi idx(n);
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
    }
    sort(begin(idx), end(idx), [&a](int x, int y) {
        return a[x] < a[y];
    });
    Vi ans(n);
    int mid = n / 2;
    for (int i = 0; i < mid; ++i) {
        ans[idx[i]] = a[idx[mid]];
    }
    for (int i = mid; i < n; ++i) {
        ans[idx[i]] = a[idx[mid - 1]];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
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
