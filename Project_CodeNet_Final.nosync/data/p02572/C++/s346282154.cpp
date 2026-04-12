//
// Created by Abhishek Bansal on 9/01/2020.
//
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll m = 1e9+7;
long long moduloMultiplication(long long a,
                               long long b,
                               long long mod)
{
    long long res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;

    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }

    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n; cin >> n;ll a[n+1], su[n+1];su[0]=0;
    for(ll i=1;i<=n;i++) {cin >> a[i];su[i] = su[i-1] + a[i];}
    ll ans = 0;
    for(ll i=1;i<n;i++) {
        ans += moduloMultiplication(a[i], su[n]-su[i], m);
    }
    cout << ans%m;

//    string s, t; cin >> s >> t;
//    for(int i=0;i<s.length();i++) {
//        if (t[0] == s[i]) {
//
//        }
//    }

    return 0;
}