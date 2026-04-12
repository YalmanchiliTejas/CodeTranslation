#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)
        cin >> a[i];
    ll sum = a[n - 1];
    ll ans = 0;
    rep (i,n - 1){
        ans += a[n - 2 - i] * sum;
        ans %= mod;
        sum += a[n - 2- i];
        sum %= mod;
    }
    cout << ans << endl;
}