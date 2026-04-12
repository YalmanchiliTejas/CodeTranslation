#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1e9+7

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll m = MOD;
    int n;
    cin >> n;
    vector<ll> a, rui;
    rui.push_back(0);
    rep(i, n){
        ll x;
        cin >> x;
        a.push_back(x);
        rui.push_back(x+rui[i]);
    }

    ll sum=0;
    rep(i, n-1){
        sum = (sum + (a[i] * ((rui[n] - rui[i+1]) % m)) % m) % m;
    }

    cout << sum << endl;
    return 0;
}