#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
// const int MOD = 1e9 + 7;

ll dfs(ll N, ll X) {
    ll ret = 0;
    if (N == 0 || X == 0) {
        ret = X;
    } else {
        ll len = (1LL << (N + 2)) - 3;
        ll len2 = (1LL << (N + 1)) - 3;
        ll p_num = (1LL << (N + 1)) - 1;
        ll p_num2 = (1LL << N) - 1;
        if (X >= len - 1) {
            ret = p_num;
        } else if (X > len2 + 2) {
            ret = p_num2 + 1 + dfs(N - 1, X - (len2 + 2));
        } else if (X == len2 + 2) {
            ret = p_num2 + 1;
        } else {
            ret = dfs(N - 1, X - 1);
        }
    }
    /*
    debug(N);
    debug(X);
    debug(ret);
    */
    return ret;
}

int main() {
    ll N, X;
    cin >> N >> X;
    cout << dfs(N, X) << endl;
}
