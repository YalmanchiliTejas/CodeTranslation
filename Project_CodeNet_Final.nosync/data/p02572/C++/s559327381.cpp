#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
const ll mod = 1e9 + 7;
ll powmod(ll a, ll b) { ll res=1; a%=mod; assert(b>=0); for(;b;b>>=1) { if(b&1) res=res*a%mod; a=a*a%mod; } return res; }
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a,b)) * b; }
ll gcd2(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {   x = 1;  y = 0;  return a;   }
    ll xx, yy;
    ll res = gcd2(b, a%b, xx, yy);
    x = yy;     y = xx - yy * (a / b);
    return res;
}

// ll nCr(ll n, ll r) {
//     return ( ( ( (fac[n] * powmod(fac[n-r], mod-2)) % mod ) * powmod(fac[r], mod-2) ) % mod );
// }
// const ll sz = 1e6 + 5;
// vector<ll> fac(sz, 1);

// * ALways PASS arrays, strings etc to functions BY REFERENCE

int main() {
    // for (int i = 1; i < sz; i++)
    //     fac[i] = (fac[i-1] * i) % mod;
    
    int t = 1;
    // cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<ll> arr(n+1);
        vector<ll> posm(n+1);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        for (int i = n-1; i >= 0; i--)
            posm[i] = (arr[i] + posm[i+1]) % mod;
        
        ll res = 0;
        for (int i = 0; i < n-1; i++) {
            ll val = (arr[i] * posm[i+1]) % mod;
            res = (res + val) % mod;
        }
        
        cout << res << endl;
    }
    
	return 0;
}
