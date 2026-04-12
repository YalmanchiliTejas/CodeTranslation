#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr double eps = 1e-9;
constexpr ll MOD = 1000000007LL;
template <typename T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "\n" : " ");
    }
    return os;
}
template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
    t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
    for (auto &e : t) {
        fill_v(e, v);
    }
};
int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int d;
    cin >> d;
    return d;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> d(n + 1);
    vector<P> v;
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            d[i] = ask(s, i);
            v.push_back(P(d[i], i));
        }
    }
    sort(all(v));
    int b = s;
    vector<int> res;
    res.push_back(s);
    for (int i = 0; i < n - 1; i++) {
        int k = v[i].second;
        int dt = (k == t ? 0 : ask(k, t));
        int db = (b == s ? d[k] : ask(b, k));
        if (d[b] + db == d[k] && d[k] + dt == d[t]) {
            b = k;
            res.push_back(k);
        }
        if (b == t) {
            break;
        }
    }
    cout << "! ";
    cout << res;
}

