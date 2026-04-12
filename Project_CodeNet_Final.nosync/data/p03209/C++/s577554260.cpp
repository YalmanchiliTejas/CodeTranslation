#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n, ll x){
    if(n == 0)
    return 1;
    ll len = (ll)(pow(2, n + 2) + 0.1) - 3;
    ll p = (ll)(pow(2, n + 1) + 0.1) - 1;
    if(x == len)
    return p;
    if(x <= n)
    return 0;
    
    ll mid = len / 2;
    if(mid == x - 1)
    return 1LL + (ll)(pow(2, n) + 0.1) - 1;
    else if(mid < x - 1)
    return (ll)(pow(2, n) + 0.1) - 1 + 1LL + solve(n - 1, x - (2LL + (ll)(pow(2, n + 1) + 0.1) - 3LL));
    else
    return solve(n - 1, x - 1);
    
}
int main() {
    ll n, x;
    cin >> n >> x;
    cout << solve(n, x);
    
    return 0;
}