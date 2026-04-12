#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

signed main(void) {
    ll n;
    vector<ll> a;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll t; cin >> t;
        a.push_back(t); 
    }

    sort(a.begin(), a.end());

    ll lsum = 0;
    for (ll i = 0; i < n / 2; i++)
        lsum += a[i];

    ll usum = 0;
    for (ll i = n / 2; i < n; i++) 
        usum += a[i];

    ll lM = a[n / 2 - 1];
    ll um = a[n / 2];
    ll um2= a[n / 2 + 1];
    
    if (n % 2 == 0) {
        ll res = usum * 2 - um;
        res -= lsum * 2 - lM;
        cout << res << endl;
    }
    else {
        ll res = (usum - um) * 2;
        res -= (lsum + um) * 2 - lM - um;
        ll res2 = (usum * 2) - um2 - um;
        res2 -= (lsum * 2);
        cout << max(res, res2) << endl;
    }
    return 0;
}