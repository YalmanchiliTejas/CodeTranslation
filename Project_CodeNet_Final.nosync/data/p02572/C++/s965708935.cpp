#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    rep(i, n){
        sum -= a[i];
        ans = (ans + a[i] * (sum % mod)) % mod; 
    }
    cout << ans << endl;
    return 0;
}