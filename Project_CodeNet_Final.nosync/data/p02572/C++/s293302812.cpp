#include <bits/stdc++.h>
using namespace std;
 
#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define fo(i, n) for( int i = 0; i < n; i++ )

const int INF = 1e9;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;


int main() {sws;

    int n;
    vector<ll> suf, a;
    cin >> n;
    suf.assign(n, 0);
    a.assign(n, 0);
    fo(i, n) cin >> a[i];
    suf[n - 1] = a[n - 1];
    for ( int i = n - 2; i >= 0; i-- ) {
        suf[i] = (a[i] + suf[i + 1]) % MOD;
    }

    ll ans = 0;
    fo(i, n - 1) {
        ans += (a[i] * (suf[i + 1])) % MOD;
        ans %= MOD;
    }
    // for ( auto num : suf ) cout << num << " ";
    // cout << endl;

    cout << ans << endl;

    return 0;
}