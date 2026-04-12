#include <bits/stdc++.h>

#define ll long long int

using namespace std;


ll f(ll n, ll x, vector<ll> const & A, vector<ll> const & P) {
    if (x < 1) return 0;
    if (n == 0) return 1;
    if (x > 1 && x <= A[n-1] + 1) return f(n-1, x-1, A, P);
    if (x >= (1 + A[n-1] + 1)) return P[n-1] + 1 + f(n-1, x - (1 + A[n-1] + 1), A, P);
    return 0;
}

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> A(n+1,1), P(n+1,1);

    for (ll i = 1; i <=n; ++i) {
        A[i] = 2 * A[i-1] + 3;
        P[i] = 2 * P[i-1] + 1;
    }
    ll res = f(n, x, A, P);
    cout << res << endl;
}
