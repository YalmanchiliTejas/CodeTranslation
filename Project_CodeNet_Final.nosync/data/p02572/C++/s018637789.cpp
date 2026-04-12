#include"bits/stdc++.h"
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) {
        return(b);
    }
    else {
        return(gcd(b, a % b));
    }
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ll  sum = 0;
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
        sum %= 1000000007;
    }
    ll ans = 0;
    for (ll t : a) {
        sum -= t;
        if (sum < 0)sum += 1000000007;
        ans += t * sum;
        ans %= 1000000007;
    }
    cout << ans;
}

/*
*/
