#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

#define rep(i ,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

int main(){
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll ans = 0, x = 0;
    rep(i, n){
        ans = (ans + a[i]*x)%mod;
        x = (x + a[i])%mod;
    }
    cout << ans%mod << endl;
    return 0;
}