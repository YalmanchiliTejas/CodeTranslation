#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        sum -= a[i];
        ll msum = sum % mod;
        ll pro = msum * a[i];
        pro %= mod;
        ans += pro;
    }
    cout << ans%mod << endl;
    return 0; 
}
