#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll MOD = ll(1e9) + 7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    ll sum = 0;
    rep(i,n) sum += a.at(i);
    ll t = 0;
    ll ans = 0;
    rep(i,n-1){
        t += a.at(i);
        ans += (a.at(i)%MOD)*((sum - t)%MOD)%MOD;
    }
    cout << ans%MOD << endl;
}