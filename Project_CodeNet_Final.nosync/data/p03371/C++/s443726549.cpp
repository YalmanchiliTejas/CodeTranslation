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

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;
    int ans = 0;
    if (A + B > C) {
        int a = min(X, Y);
        ans += C * a;
        X -= a;
        Y -= a;
    }
    if (A > C) {
        ans += C * X;
        X = 0;
    }
    if (B > C) {
        ans += C * Y;
        Y = 0;
    }
    ans += A * X;
    ans += B * Y;
    cout << ans << endl;
}
