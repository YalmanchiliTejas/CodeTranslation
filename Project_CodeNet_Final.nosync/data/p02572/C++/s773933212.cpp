#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


ll a[200010];


ll l[35];

ll power(ll m, ll n){

    l[0]=m;
    for(ll i=1; i<35; i++){
        l[i] = (l[i-1]*l[i-1]) % MOD;
    }
    /*
    rep(i,35){
        cout << l[i] << " ";
    }
    cout << endl;
    */

    ll tmp = n;
    ll ans = 1;
    rep(i,35){
        if(tmp%2==1){
            ans = (ans*l[i]) % MOD;
        }
        tmp /= 2;
        //cout << ans << " ";
    }
    //cout << endl;
    return ans%MOD;

}


void solve(){

    ll n;
    cin >> n;
    ll s = 0;
    rep(i,n){
        cin >> a[i];
        s = (s + a[i])%MOD;
    }
    ll all=0;
    all = (s*s)%MOD;
    rep(i,n){
        all = (all - (a[i]*a[i])%MOD + MOD) % MOD;
    }

    ll x = power(2, MOD-2);
    cout << (all*x)%MOD << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
