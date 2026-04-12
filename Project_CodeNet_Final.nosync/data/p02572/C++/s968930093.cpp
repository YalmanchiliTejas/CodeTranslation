#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n);++i)
using namespace std;
using ll = long long; 
using P = pair<int,int>;
int mod = 1000000007;
int main(void){
    int n;cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    } 
    vector<ll> sum(n);
    sum[0] = a[0];
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll tmp = (sum[n-1]-sum[i]) % mod;
        ans += a[i]*tmp;
        ans %= mod;
    }
    cout << ans << endl;
	return 0;
}
