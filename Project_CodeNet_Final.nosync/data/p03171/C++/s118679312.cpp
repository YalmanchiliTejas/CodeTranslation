#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<128>>;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << (x) << '\n'
typedef long long lint;
const int INF = 2e9;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const lint LINF = 1e18;
typedef vector<int> vint;
typedef pair<int, int> pint;
template <class T = int> T in() {
    T x;
    cin >> x;
    return (x);
}
void print() { cout << endl; }
template <class T, class... A> void print(const T &first, const A &... rest) {
    cout << first;
    print(rest...);
}
template <class... A> void print(const A &... rest) { print(rest...); }
template <class T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
int modulo(int a, int b, int n) {
    long long x = 1, y = a;
    while(b > 0) {
        if(b % 2 == 1) {
            x = (x * y) % n; // multiplying with base
        }
        y = (y * y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
/* templates */ /* templates */ /* templates */ /* templates */ /* templates */

int MAXN = 3000;
vector<vector<bool>> flag(MAXN + 10, vector<bool>(MAXN + 10));
vector<vector<lint>> dp(MAXN + 10, vector<lint>(MAXN + 10));
vint a(MAXN + 10);

lint f(int l, int r) {
    if(flag[l][r]) {
        return dp[l][r];
    }
    flag[l][r] = true;
    if(l == r) {
        return dp[l][r] = a[l];
    }
    return dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N = in();
    rep(i, 1, N + 1) { cin >> a[i]; }
    cout << f(1, N) << endl;
}
