#include <bits/stdc++.h>
#include <stdio.h>

#define INF 1e18
#define REP(i, n) for (int i=0; i<n; i++)
#define print(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << endl

const double PI=3.141592653589793238462643383279502884197169399375105820974944;

typedef long long ll;

using namespace std;

ll a(int i, vector<ll> &vecA) {
    if (i == 0) return 1;
    if (vecA[i-1] != -1) {
        return 2ll * vecA[i-1] + 3;
    } else {
        return 2ll * a(i-1, vecA) + 3;
    }
}

ll p(int i, vector<ll> &vecP) {
    if (i == 0) return 1;
    if (vecP[i-1] != -1) {
        return 2ll * vecP[i-1] + 1;
    } else {
        return 2ll * p(i-1, vecP) + 1;
    }
}

ll f(int n, ll x, vector<ll> &a, vector<ll> &p) {
    if (x == 1) {
        if (n == 0) return 1;
        else return 0;
    } else if (x < a[n-1] + 2) {
        return f(n-1, x-1, a, p);
    } else if (x == a[n-1] + 2) {
        return p[n-1] + 1;
    } else if (x < a[n]) {
        return p[n-1] + 1 + f(n-1, x-2-a[n-1], a, p);
    } else {
        return p[n];
    }
}

void solve() {
    int N;
    ll X;
    cin >> N >> X;

    vector<ll> A(N+1, -1), P(N+1, -1);
    REP(i, N+1) {
        A[i] = a(i, A);
        P[i] = p(i, P);
    }
    ll ans = f(N, X, A, P);
    cout << ans << endl;
}

signed main() {
    solve();
}
