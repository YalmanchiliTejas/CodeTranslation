#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
const int inf = INT_MAX / 2;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long a, b, t;
    long long ans = inf;
    for (int i = 0; i <= max(X, Y) * 2; i += 2) {
        a = (X - i / 2) * A;
        b = (Y - i / 2) * B;
        if (a < 0) a = 0;
        if (b < 0) b = 0;
        t = a + b + C * i;
        chmin(ans, t);
    }

    cout << ans << endl;
}