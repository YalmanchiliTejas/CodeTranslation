#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    for(int i = 1; i < n; i++) sum += a[i];
    sum %= MOD;
    ll ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        ans = (ans + (sum * a[i]) % MOD) % MOD;
        sum = (sum - a[i+1]) % MOD;
        sum = (sum + MOD) % MOD;
    }
    cout << (ans + MOD) % MOD << endl;
}

