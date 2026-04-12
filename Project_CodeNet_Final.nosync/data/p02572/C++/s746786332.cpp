/*
ID: sstfmsc1
TASK: milk2
LANG: C++
*/
#include <bits/stdc++.h>
 
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define forin(i, n) for ( int i = 0; i < (int)n; ++i )
#define MAXN 50000
#define INF 1000000
typedef long long ll;
const char nl = '\n';
ll MOD = (ll)(1e9 + 7);
 
void solve()
{
    int n; cin >> n;

    vector<ll> a(n);
    ll suma = 0;
    forin(i, n) { cin >> a[i]; suma += a[i]; }

    ll ans = 0;
    forin(i, n)
    {
        suma -= a[i];
        //cout << suma << nl;
        //cout << ( ( a[i] % MOD ) * ( suma % MOD ) ) % MOD << nl;
        ans = ( ans + ( ( a[i] % MOD ) * ( suma % MOD ) ) % MOD ) % MOD;

        //cout << ans << nl << nl;
    }

    cout << ans << nl;
    return;
}
 
int main()
{
    //freopen("milk2.in", "r", stdin);
    //freopen("milk2.out", "w", stdout);
    IOS
 
    solve();
    
    
    return 0;
}