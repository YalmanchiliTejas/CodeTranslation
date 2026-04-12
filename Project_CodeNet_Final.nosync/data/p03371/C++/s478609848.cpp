#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int res = 0;
    if(A + B > 2*C) {
        int d = min(X, Y);
        res += d*2*C;
        X -= d;
        Y -= d;
    }
    if(A > 2*C) {
        int d = X;
        res += d*2*C;
        X = 0;
        Y -= min(d, Y);
    }
    if(B > 2*C) {
        int d = Y;
        res += d*2*C;
        Y = 0;
        X -= min(d, X);
    }
    res += A*X + B*Y;
    cout << res << endl;
    return 0;
}

