#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1000000007;


int main()
{
    ll n, res = 0;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n + 1, 0);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i + 1] = b[i] + a[i];
    }

    for(int i = 0; i < n - 1; ++i)
    {
        res += a[i] * ((b[n] - b[i + 1]) % mod); 
        res %= mod;
    }    

    cout << res << "\n";
    return 0;
}
