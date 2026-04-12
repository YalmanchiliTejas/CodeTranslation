#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll tot_sum = 0;
    for(int i=0;i<n;i++){
        tot_sum += a[i];
    }
    ll ans = 0;
    for(int i=0;i<n-1;i++){
        tot_sum -= a[i];
        ll temp_sum = tot_sum%MOD;
        ll temp = temp_sum*a[i];
        temp %= MOD;
        ans += temp;
        ans %= MOD;
    }
    cout << ans << endl;
}