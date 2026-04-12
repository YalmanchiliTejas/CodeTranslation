#include<bits/stdc++.h>
using namespace std;
const int MOD = pow(10, 9) + 7;
using ll = long long;

int main(){
    ll n;
    ll ans = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }
    
    vector<ll> sum(n);
    ll pre = 0;
    for(int i = 0; i < n; i++){
        sum[i] = (pre%MOD + a[i]%MOD)%MOD;
        pre = sum[i];
    }
    for(int i = 0; i < n - 1; i++){
        ans += (sum[i] * a[i + 1]%MOD)%MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}