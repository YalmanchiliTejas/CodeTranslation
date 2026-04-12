#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAXN 250000
#define _MOD 1000000009

int main() {
#ifdef OJ
    //freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
#endif
    std::ios_base::sync_with_stdio(false);

    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    if (X < Y) {
        swap(A,B);
        swap(X,Y);
    }

    int ans = min(Y*(A+B), 2*Y*C);
    X -= Y;
    ans += min(X*A, 2*X*C);

    cout << ans << endl;
    return 0;
}