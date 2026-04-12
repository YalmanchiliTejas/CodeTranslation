#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
 
int power(int a, int b, int c){
    int ans = 1;
    while(b){
        if(b&1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int f[N];

signed main() {
    IOS;
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = (f[i-1]*i) % mod;
    int ans = (m*n * (m*n - 1) * (m + n)) % mod;
    ans = (ans * f[m*n - 2]) % mod;
    ans = (ans * power(f[k-2], mod-2, mod)) % mod;
    ans = (ans * power(f[n*m - k], mod - 2, mod)) % mod;   
    ans = (ans * power(6, mod-2, mod)) % mod;
    cout << ans;
    return 0;
}