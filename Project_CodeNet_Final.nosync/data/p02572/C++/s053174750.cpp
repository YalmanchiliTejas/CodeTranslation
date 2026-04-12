#include <bits/stdc++.h> 
using namespace std; 

const int mod = 1e9 + 7;

using ll = long long;

int solve(const vector<ll>& A, ll n)  {
    ll sum = A[0];
    ll res = 0;
    for(int i=1; i<n; i++) {
        res = (res + (sum * A[i]) % mod) % mod;
        sum = (sum + A[i]) % mod;
    }
    return res;
} 
int32_t main() 
{ 
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll& i : arr) cin >> i;
    cout << solve(arr, n) << '\n';
} 
