#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> ans(n);

    if(n % 2 == 0){
        for(ll i = 0; i < n/2; i++){
            ans[n/2+i] = a[i*2];
        }
        for(ll i = 0; i < n/2; i++){
            ans[n/2-i-1] = a[i*2+1];
        }
    }else{
        for(ll i = 0; i < n/2; i++){
            ans[n/2+1+i] = a[i*2+1];
        }
        for(ll i = 0; i <= n/2; i++){
            ans[n/2-i]   = a[i*2];
        }
    }

    for(ll i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

