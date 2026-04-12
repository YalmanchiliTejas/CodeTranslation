#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<ll> s(n+1);
    s[0] = 0;
    for(int i=0;i<n;i++){
        s[i+1] = s[i]+a[i];
        s[i+1] %= mod;
    }

    ll ans = 0;
    for(int i=1;i<n;i++){
        ans += a[i]*s[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}