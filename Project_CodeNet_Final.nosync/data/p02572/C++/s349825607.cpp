#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
    int n; cin >> n;
    vector<ll> a(n), s(n);
    for(int i=0; i<n; ++i){cin >> a[i];}
    s[0] = 0;
    for(int i=0; i<n-1; ++i){
        s[i+1] = (s[i] + a[n-1-i])%mod;
    }
    ll res = 0;
    for(int i=0; i<n; ++i){
        res += (a[n-1-i] * s[i])%mod;
    }
    res %= mod;
    cout << res << endl;
    return 0;
}