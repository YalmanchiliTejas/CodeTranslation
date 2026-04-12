#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7LL;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), cum(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cum[i+1] = (cum[i] + a[i]) % MOD;
    }
    ll sum = 0;
    for(int i = 0; i+1 < n; i++){
        ll temp = (cum[n]-cum[i+1] + MOD) % MOD;
        temp = temp * a[i] % MOD;
        sum = (sum + temp) % MOD;
    }
    cout << sum << endl;
    return 0;
}