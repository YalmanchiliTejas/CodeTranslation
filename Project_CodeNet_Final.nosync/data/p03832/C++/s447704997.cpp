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
const int mod = 1e9 + 7;
const int N = 2005;
const int K = 10;
int f[N], invf[N], dp[N][N];
int cnt;
map < pair < int, int >, int > mp;
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
int solve(int n, int a, int b, int c, int d){
    if (n == 0) return 1;
    if (a > b) return 0;
    if (n < 0) return 0;
    if (dp[n][a] != -1) return dp[n][a];
    int res = solve(n, a + 1, b, c, d);
    int x = binpow(invf[a], c - 1);
    for (int i = c; i <= d && n - i * a >= 0; i++){
        x = x * invf[a] % mod;
        cnt++;
        res = (res + f[n] * invf[i] % mod * invf[n - i * a] % mod * x % mod * solve(n - a * i, a + 1, b, c, d)) % mod;
    }
     //   cout << n << " " << a << " " << res << " " << x << " " << c << " " << d << endl;
    return dp[n][a] = res;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invf[i] = binpow(f[i], mod - 2);
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    cout << solve(n, a, b, c, d) << endl;
}
