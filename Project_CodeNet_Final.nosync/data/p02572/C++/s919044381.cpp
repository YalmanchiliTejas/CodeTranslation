#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll pow(ll a, ll x) {
    ll ret = 1;
    while(1) {
        if (x == 0) break;
        if (x&1) ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return pow(a, mod-2);
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> a_accum(n+1, 0);
    rep(i, n) {
        cin >> a[i];
        a_accum[i+1] = (a_accum[i] + a[i]) % mod;
    }
    ll ans = 0;
    rep(i, n) {
        ll tmp = ((a_accum[n] - a[i]) < 0) ? a_accum[n] - a[i] + mod : a_accum[n] - a[i];
        ans = (ans + tmp * a[i] % mod) % mod;
    }
    //cout << inv(2LL) << endl;
    cout << ans * inv(2LL) % mod << endl;

    return 0;
}
