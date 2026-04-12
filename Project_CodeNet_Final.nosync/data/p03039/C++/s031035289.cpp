#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

#define CIN(T, x) T x; cin >> x;
#define CINS(T, x, N) vector<T> x(N); for(int i = 0; i < (N); i++) { cin >> x[i]; }
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << "\n";
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << "\n";

ll MOD = 1e9+7;
ll powMod(ll a, ll b) { // a^b mod M
    ll ans = 1; ll temp = a;
    while (b > 0) {
        if ( b % 2 == 1 ) ans = (ans * temp) % MOD;
        temp = (temp * temp) % MOD;
        b = b / 2;
    }
    return ans;
}
ll nCkMod(ll n, ll k) { // nCk mod M
    ll ans = 1, temp = 1, mink = min(k, n-k);
    for (ll i = 0; i < mink; i++) {
        ans = (ans * (n - i)) % MOD;
    }
    for (ll i = 0; i < mink; i++) {
        temp = (temp * (i + 1)) % MOD;
    }
    return (ans * powMod(temp, MOD - 2)) % MOD;
}


int main() {

    CIN(ll, N);
    CIN(ll, M);
    CIN(ll, K);
    ll ans;

    ans = ( ( M * M * N * (N-1) * (N+1) + N * N * M * (M-1) * (M+1) ) / 6 ) % MOD;
    ans = ( ans * nCkMod( N * M - 2, K - 2)) % MOD;

    cout << ans << "\n";
    return 0;
}