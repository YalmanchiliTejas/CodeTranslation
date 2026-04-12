#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 1e9;
    rep(i, max(X, Y) + 1) {
        ans = min(ans, i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B);
    }
    cout << ans << endl;
}