// 7/4
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<ll> a(51);

ll f(ll N, ll X) {
    if (N == 0) return 1;  // はじめにパティは１枚。

    if (X == 1) return 0;  // 一番下はバン。
    if (X <= 1 + a[N-1]) return f(N-1, X-1);
    if (X <= 2 + a[N-1]) return f(N-1, a[N-1]) + 1;
    if (X <= 2 + 2 * a[N-1]) return f(N-1, a[N-1]) + 1 + f(N-1, X-a[N-1]-2);
    else return 2 * f(N-1, a[N-1]) + 1;
    // return ret;
}

int main() {
    ll N, X;
    cin >> N >> X;
    a[0] = 1;
    rep(i, 50) a[i+1] = a[i] * 2 + 3;
    cout << f(N, X) << endl;
    return 0;
}