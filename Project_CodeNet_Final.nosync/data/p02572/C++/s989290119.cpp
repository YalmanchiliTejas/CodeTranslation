// AUTHOR: ROSHAN SRIVASTAVA
// WEBSITE: https://www.youtube.com/channel/UC6uQdd7kLLOdlHSVklhV7Cw

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n; 

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    vector <ll> a(n);
    for(int i =0 ; i < n; i++) 
        cin >> a[i];

    ll sum = 0;
    ll ans = 0;

    for(int i = n - 2; i >= 0; i--) {
        sum += a[i + 1];
        sum %= mod;
        ans += ((sum * a[i]) % mod);
        ans %= mod;
    }


    cout << ans << endl;
    return 0;
}