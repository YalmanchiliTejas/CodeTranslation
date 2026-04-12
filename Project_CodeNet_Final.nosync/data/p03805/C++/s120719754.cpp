#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n, m;
    cin >> n >> m;
    auto v = make_vec<bool>(n, n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    vector<int> p(n);
    rep(i, n) p[i] = i;
    int ans = 0;
    do {
        if (p[0] != 0) continue;
        int ok = 1;
        rep(i, n - 1) {
            ok &= v[p[i]][p[i + 1]];
        }
        ans += ok;
    } while (next_permutation(all(p)));
    cout << ans << endl;
}