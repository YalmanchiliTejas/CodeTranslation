#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    rep(i, n) cin >> a[i];
    b[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 1;i--){
        b[i - 1] = (b[i] + a[i - 1])%1000000007;
    }
    ll ans = 0;
    rep(i,n-1){
        ans = (ans + a[i] * b[i + 1]) % 1000000007;
    }
    cout << ans << endl;
}