#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=(a),i##Len_=(b);i<i##Len_;i++)
const char* LF = "\n";
namespace{struct _{_(){
    cin.tie(0);
    ios::sync_with_stdio(false);
}}a;}

array<ll, 51> A, P;

ll f(int n, ll x) {
    if (n == 0) {
        if (x <= 0)
            return 0;
        else
            return 1;
    }
    else if (x == 1LL) {
        return 0;
    }
    else if (x <= 1LL + A[n - 1]) {
        return f(n - 1, x - 1LL);
    }
    else {
        return P[n - 1] + 1LL + f(n - 1, x - 2LL - A[n - 1]);
    }
}

signed main() {
    ll N, X;
    cin >> N >> X;

    A[0] = 1;
    P[0] = 1;
    FOR(i, 1, 51) {
        A[i] = A[i-1] * 2 + 3;
        P[i] = P[i-1] * 2 + 1;
    }

    cout << f(N, X) << LF;

    return 0;
}
