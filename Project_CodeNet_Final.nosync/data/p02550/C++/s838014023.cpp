#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"

// const ll mod = 1e9 + 7;
const ll mod = 998244353;
const ll sz = 1e6 + 5;
vector<ll> fac(sz, 1);

ll powmod(ll a, ll b) { ll res=1; a%=mod; assert(b>=0); for(;b;b>>=1) { if(b&1) res=res*a%mod; a=a*a%mod; } return res; }
ll nCr(ll n, ll r) { return ( ( ( (fac[n] * powmod(fac[n-r], mod-2)) % mod ) * powmod(fac[r], mod-2) ) % mod ); }
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a,b)) * b; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll xx, yy;
    ll res = extended_gcd(b, a%b, xx, yy); x = yy; y = xx - yy * (a / b);
    return res;
}

// * ALways PASS arrays, strings etc to functions BY REFERENCE

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // for (ll i = 2; i < sz; i++)
    //     fac[i] = (fac[i-1] * i) % mod;
    
    int t = 1;
    // cin >> t;

    while(t--) {
        ll n, x, m;
        cin >> n >> x >> m;
        
        vector<ll> arr, sm;
        map<ll, ll> mpp;
        
        arr.pb(x);
        sm.pb(x);
        mpp[x] = 0;
        int sz = 1;
        
        while (sz < n) {
            ll xx = (arr[sz-1] * arr[sz-1]) % m;
            if (mpp.count(xx))
                break;
            
            arr.pb(xx);
            sm.pb(sm.back() + xx);
            mpp[xx] = sz;
            sz += 1;
        }
        
        ll res = sm.back();
        if (sz < n) {
            ll xx = (arr[sz-1] * arr[sz-1]) % m;
            ll indx = mpp[xx];
            
            ll par_sm = sm.back();
            par_sm -= (indx == 0 ? 0 : sm[indx-1]);
            
            ll itr = (n-sz) / (sz-indx);
            res += (par_sm * itr);
            ll rem = (n-sz) % (sz-indx);
            if (rem != 0)
                res += (sm[indx + rem - 1] - (indx == 0 ? 0 : sm[indx-1]));
        }
        
        cout << res << endl;
    }
    
	return 0;
}
