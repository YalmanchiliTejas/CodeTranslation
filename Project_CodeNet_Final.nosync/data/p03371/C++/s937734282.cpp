#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;



int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int res = Inf;
    rep (i, max(x, y) + 1) {
        int tmp = i * c * 2 + max(x - i, 0) * a + max(y - i, 0) * b;
        res = min(res, tmp); 
    }
    res = min(res, a * x + b * y);
    cout << res << endl;
    
    return 0;
}

