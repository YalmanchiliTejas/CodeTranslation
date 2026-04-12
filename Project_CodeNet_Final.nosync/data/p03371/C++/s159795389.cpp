//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
typedef long long Int;
#define rep(i,a,b) for(Int i=a;i<b;++i)
#define rrep(i,a,b) for(Int i=a;i>=b;--i)
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    Int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

    Int res = LLONG_MAX;
    for(Int numAB = 0; numAB <= max(X, Y); ++numAB) {
        Int bill = 0;
        bill += numAB * 2 * C;

        Int curX = X - numAB;
        Int curY = Y - numAB;
        if (curX > 0) bill += curX * A;
        if (curY > 0) bill += curY * B;

        res = min(res, bill);
    }

    cout << res << endl;
}
