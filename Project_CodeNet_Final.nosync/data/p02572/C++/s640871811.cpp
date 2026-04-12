#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <numeric>

#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vec vector<int>
#define vecll vector<ll>
#define pb(x) push_back(x)

using namespace std;
///////////////////////////////////////////////////////////



int main() {
    ll m = 1e9 + 7;

    ll n; cin >> n;

    ll a[n];
    ll sa[n];
    ll in;
    rep(i, n) {
        cin >> in;
        a[i] = in % m;
    }
    sa[0] = a[0];
    for (ll i = 1; i < n; i++) {
//        cout << sa[i-1] << " " << a[i] << endl;
        sa[i] = sa[i-1] + a[i];
    }

    ll ans = 0;
    for (ll j = 1; j < n; j++) {
        ans += (sa[j-1] % m) * (a[j] % m) % m;
        ans %= m;
    }
    cout << ans << endl;

    return 0;
}