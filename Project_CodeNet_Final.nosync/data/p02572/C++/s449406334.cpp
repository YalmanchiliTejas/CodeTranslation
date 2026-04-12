/*
power code taken from geeks for geeks
*/
// cout << setprecision (2) << fixed << 1.2;

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


const ll INF = 1e18 + 5;
const ll MAX_N = 1e5 + 5;
const ll MODD = 1e9 + 7;
const ld PI = 3.14159265358979323846;

ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
double max(double a,double b){return a>b?a:b;}
double min(double a,double b){return a<b?a:b;}

ll modd(ll a){if(a<0LL) return a*-1LL;return a;}
ld modd(ld a){if(a<0.0) return a*-1.0;return a;}

ll modulo(ll a){return (a + MODD) % MODD; }

ll power(ll k, ll p){
    if (p == 0)
        return 1LL;
 
    ll P = power(k, p/2LL);
    P = (P * P) % MODD;
 
    if (p % 2 == 1)
        P = (P * k) % MODD;
 
    return P;
}


struct p_str {
    ll a, b;
};



void solve() {
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0LL;
    ll c = a[0];
    for(ll i = 1; i < n; i++) {
        ans = modulo(ans + a[i] * c);

        c = modulo(c + a[i]);
    }

    cout << ans << endl;
}

int main(){


  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    


    ll t=1;

    // cin >> t;

    


    while(t--){
        
        solve();
    }
    
    return 0;
}