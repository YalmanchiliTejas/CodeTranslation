#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <cmath>
#include <cstdio>

using namespace std;

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif




void solve() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll cost = 0;
    if (C * 2 < A + B) {
        ll m = min(X, Y);
        cost += m * C * 2;
        X -= m;
        Y -= m;
    }
    if (C * 2 < A) {
        cost += C * 2 * X;
        Y -= X;
        X = 0;
    }
    if ( Y > 0 && C * 2 < B) {
        cost += C * 2 * Y;
        X -= Y;
        Y = 0;
    }
    if (X > 0){
        cost += A * X;
    }
    if (Y > 0) {
        cost += B * Y;
    }
    cout << cost << '\n';
}


int main() {
    solve();
    return 0;
}
