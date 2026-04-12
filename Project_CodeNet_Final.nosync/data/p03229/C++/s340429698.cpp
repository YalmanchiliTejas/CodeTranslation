#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](ll a, ll b){ 
        return a > b;
    });
    int ai = 1, bi = 0;
    ll l = a[0], r = a[0];
    ll ans = 0;
    while ( ai + bi < n ) {
        ll ad = max(abs(l - a[ai]), abs(r - a[ai]));
        ll bd = max(abs(l - b[bi]), abs(r - b[bi]));
        if( ad > bd ) {
            if ( abs( l - a[ai] ) < abs( r - a[ai] ) ) r = a[ai];
            else                                       l = a[ai];
            ++ai;
        }
        else {
            if ( abs( l - b[bi] ) < abs( r - b[bi] ) ) r = b[bi];
            else                                       l = b[bi];
            ++bi;
        }
        ans += max(ad, bd);
    }
    cout << ans << endl;
    return 0;
}
