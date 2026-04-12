#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
#define rep(i,n) for (ll i=0;i<n;i++)
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll s=0;
    ll mod = 1000000007;
    rep(i,n) {
        cin >> a[i];
        s+= a[i];
    }
    ll ans = 0;
    rep(i,n){
        s = s - a[i];
        ll tmp;
        tmp = (s%mod) * a[i] % mod;
        ans += tmp;
        ans%=mod; 
    }

    cout << ans ;



    return 0;
}