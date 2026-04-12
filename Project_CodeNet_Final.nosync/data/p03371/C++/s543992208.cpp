#include "bits/stdc++.h"
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmax(x, y) (x > (y) ? x : x = (y))
#define chmin(x, y) (x < (y) ? x : x = (y))
#define write(x) cout << (x) << endl
using namespace std;
typedef long long ll;
const int INF = 1 << 29;
const int MAX = 1e5 + 10;

ll A, B, C, X, Y;

int main()
{
    cin >> A >> B >> C >> X >> Y;

    ll ans = 1ll << 60;
    for (int nAB = 0; nAB <= max(2 * X, 2 * Y); nAB++) {
        int tmp = max(0ll, X * A - nAB / 2 * A);
        ll price = C * nAB + max(0ll, X * A - nAB / 2 * A) + max(0ll, Y * B - nAB / 2 * B);
        if (price < ans) ans = price;
    }
    write(ans);
}