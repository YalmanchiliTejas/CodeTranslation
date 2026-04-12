#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define MOD 1000'000'007

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int i, n, m, j;
    cin >> n;
    vector<ll> v(n), suff(n, 0);
    for (i = 0; i < n; i++)
        cin >> v[i];
    suff[n - 1] = v[i - 1];
    for(i = n - 2; i >= 0; i--)
        suff[i] = (suff[i + 1] + v[i]) % MOD;
    ll ans = 0;
    for(i = 0; i < n - 1; i++)
        ans = (ans + v[i] * suff[i + 1])%MOD;
    
    cout << ans << endl;
}