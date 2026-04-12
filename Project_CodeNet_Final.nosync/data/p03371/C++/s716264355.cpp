#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;
const lint INF = 1LL << 60;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    lint res = INF;

    int m = max(x, y);

    for (int z = 0; z <= 2*m; z += 2) {
        int ar = max(x - (z/2), 0), br = max(y - (z/2), 0);
        lint total = ar * a + br * b + z * c;
        res = min(res, total);
    }

    cout << res << endl;
    return 0;
}
