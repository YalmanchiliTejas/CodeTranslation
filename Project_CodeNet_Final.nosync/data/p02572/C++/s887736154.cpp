#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main () {
    ll n ;
    cin >> n ;
    vector<ll> a (n) ;
    rep(i, n) cin >> a[i] ;
    vector<ll> b = a ;
    ll tot = 0 ;
    rep(i, n) tot += a[i] ;
    rep(i, n){
        if(i == 0) continue ;
        a[i] += a[i - 1] ;
    }
    ll ans = 0 ;
    rep(i, n){
        ans += b[i] * ((tot - a[i])%mod) ;
        ans %= mod ;
    }
    cout << ans << endl ;
}