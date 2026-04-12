#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sm(n, 0);
    const ll mod = 1000000007;
    sm[0] = a[0];
    rep1(i, n) sm[i] = (sm[i-1] + a[i]) % mod;

    ll res = 0;
    rep1(i, n){
        res = (res + a[i]*sm[i-1]) % mod;
    }

    cout << res << endl;

    return 0;
}