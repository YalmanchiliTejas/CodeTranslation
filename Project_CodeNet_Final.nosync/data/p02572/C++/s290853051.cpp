#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> Sa(n);
    Sa[0] = a[0];
    repi(i, n) Sa[i] = Sa[i-1] + a[i];

    ll sum = 0;
    ll MOD = 1000000007;
    rep(i, n) {
        ll v = a[i] * ((Sa[n - 1] - Sa[i]) % MOD);
        sum = (sum + (v % MOD)) % MOD;
    }
    put(sum);
    return 0;
}