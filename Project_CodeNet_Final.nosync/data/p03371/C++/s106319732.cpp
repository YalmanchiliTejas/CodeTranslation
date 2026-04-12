#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    ll A, B, C, ans = 1e18;
    int X, Y;
    cin >> A >> B >> C >> X >> Y;
    rep(i, max(X, Y) + 1) {
        ll cost = A * max(0, X - i) + B * max(0, Y - i) + C * i * 2;
        if (cost < ans) ans = cost;
    }
    cout << ans << endl;
}