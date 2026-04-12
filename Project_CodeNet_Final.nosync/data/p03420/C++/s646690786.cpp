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
const int INF = 1e9;
// const int MOD = 1e9 + 7;

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    for (int b = K + 1; b <= N; b++) {
        ans += ((N - (b - 1)) / b + 1) * (b - K);
        if (K <= N % b && N % b < b - 1) ans += N % b - K + 1;
    }
    cout << ans << endl;
}
