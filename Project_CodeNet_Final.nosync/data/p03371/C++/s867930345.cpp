#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int A, B, C, X, Y, ans = 1e9;
    cin >> A >> B >> C >> X >> Y;
    rep(i, max(X, Y) + 1) {
        ans = min(ans, 2 * i * C + max(0, X - i) * A + max(0, Y - i) * B);
    }
    cout << ans << "\n";
}