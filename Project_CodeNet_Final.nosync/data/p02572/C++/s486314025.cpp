#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    rep(i,n) cin >> a[i];
    ll sum = 0;
    for(int i = n-1; i >= 1; i--){
        sum += a[i];
        sum %= mod;
        ans += (a[i-1] * sum) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}