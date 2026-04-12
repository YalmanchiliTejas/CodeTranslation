#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<pii , pii>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 200005

ll n , s;
ll a[MAXX];
ll p[MAXX];

int main()
{
    _FastIO;

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        if(!i)
            p[0] = a[0];
        else
            p[i] = p[i - 1] + a[i];
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += (a[i] * ((s - p[i]) % 1000000007));
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}
