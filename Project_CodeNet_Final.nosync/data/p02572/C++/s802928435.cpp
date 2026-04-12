#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    ll const mod = 1000000007;
    ll n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    // 累積和を計算
    ll sm[n];
    sm[n-1] = a[n-1];
    for(ll i = n - 1; i > 0; i--){
        sm[i-1] = sm[i] + a[i-1];
        sm[i-1] %= mod;
    }
    ll ans = 0;
    rep(i, n - 1){
        ans += a[i] * (sm[i+1]);
        ans %= mod;
    }

    // ll ans = 0;
    // rep(i, n - 1){
    //     for (int j = i + 1; j < n; j++){
    //         ans += a[i] * a[j];
    //         ans %= mod;
    //     }
    // }

    // rep(i, n) cout << sm[i] << endl;
    cout << ans % mod << endl;
    // cout << mod << endl;
}