#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 998244353;
const int N = 10000005;
const int K = 25;
int f[N], invf[N];
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
int c(int n, int k){
    return f[n] * invf[k] % mod * invf[n - k] % mod;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    n /= 2;
    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
    invf[N - 1] = binpow(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--){
        invf[i] = invf[i + 1] * (i + 1) % mod;
    }
    int ans = binpow(9, n);
    for (int i = 0; i < n; i++){
        ans = (ans - c(n + n, i) * binpow(2, i + 1) % mod + mod) % mod;
    }
    cout << ans;
}
