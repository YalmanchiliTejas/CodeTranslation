#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;


ll L[50+1];
ll P[50+1];

ll dfs(ll m, ll x) {
    if (x == 0) return 0;
    if (m == 0) return x;

    if (2 * x < L[m]) {
        return dfs(m-1, max(0LL, x-1));
    } else {
        return P[m-1] + 1 + dfs(m-1, min(L[m-1], x-2-L[m-1]));
    }
}


int main() 
{
    ll n, k;
    cin >> n >> k;
    L[0] = 1;
    P[0] = 1;
    for(int i=1; i<=n; i++) {
        L[i] = 2*L[i-1] + 3;
        P[i] = 2*P[i-1] + 1;
    }

    ll ans = dfs(n, k);
    cout << ans << endl;

    return 0;
}
