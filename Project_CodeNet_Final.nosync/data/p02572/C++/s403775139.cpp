#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0, ans = 0, mod = 1e9+7;
    rep(i,n) cin >> a[i];
    rep(i,n-1){
        sum = (sum + a[i])%mod;
        ans = (ans + sum*a[i+1])%mod;
    }
    cout << ans << endl;
    return 0;
}