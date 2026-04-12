
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<pair<int,int>, null_type,less<pair<int, int> >,rb_tree_tag,tree_order_statistics_node_update > pbds;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)

#define pb push_back
#define ft first
#define sd second
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b % 2) {
            res *= a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b) {
        if(b % 2) {
            res *= a;
            res %= mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
const int N = 1e5 + 5;
int n, k, p;
const ll mod = 998244353;

signed main() {
    int n, s;
    cin >> n >> s;
    int a[n + 4];
    memset(a, 0, sizeof a);
    ll dp[n + 4][s + 4][2];  // sum of starting index of subsequences with sum j and ending at index i;
    memset(dp, 0LL, sizeof dp);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=s; j++) {
            if(j < a[i]) {
                dp[i][j][0] = dp[i-1][j][0];
            }
            else if(j == a[i]) {
                dp[i][j][0] = (dp[i-1][j][0] + i) % mod;
                dp[i][j][1] = i;
            }
            else {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j-a[i]][0]) % mod;
                dp[i][j][1] = dp[i-1][j-a[i]][0];
            }
        }
    }
    ll ans = 0;
    for(int i=1; i<=n; i++) {
        if(a[i] > s) continue;
        else if(a[i] == s) {
            ans += (i * (n - i + 1)) % mod;
            ans %= mod;
        }
        else {
            ans += ((n - i + 1) * dp[i-1][s-a[i]][0]) % mod;
            ans %= mod;
        }
    }
    cout << ans << '\n';
    return 0;
}