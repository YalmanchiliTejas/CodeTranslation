#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int n;
    cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];

    const ll mod = 1e9+7;

    vl dp_j(n+1);

    for(int i = n-1; i >= 0; i--){
        dp_j[i] = (dp_j[i+1] + a[i])% mod;
    }

    // rep(i,n){
    //     cout << dp_j[i] << endl;
    // }

    // rep(i,n){
    //     dp_j[i+1] = (dp_j[i] + a[i]) % mod; 
    // }

    ll ans = 0;
    rep(i,n-1){
        ll tmp = (a[i] * dp_j[i+1]) % mod;
        ans = (ans+tmp)%mod;
    }

    cout << ans << endl;
    return 0;
}