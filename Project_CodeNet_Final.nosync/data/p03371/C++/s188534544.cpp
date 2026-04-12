#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = INFINITY;
    rep(i,max(2*X,2*Y)+1) {
        ll price = max(0LL, X - i / 2) * A + max(0LL, Y - i / 2) * B + i * C;
        ans = min(ans, price);
    }
    cout << ans << endl;
}
