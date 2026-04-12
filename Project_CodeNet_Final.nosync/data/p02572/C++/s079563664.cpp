#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll k[n];
    ll mod = 10e8 + 7;
    for(int i = 0; i < n; i++){
        k[i] = sum;
        k[i] %= mod;
        sum -= a[i];
    }

    ll ans = 0;
    
    for(int i = 0; i < n - 1; i++){
        ans += a[i] * k[i + 1];
        ans %= mod;
    }

    cout << ans << endl;
}