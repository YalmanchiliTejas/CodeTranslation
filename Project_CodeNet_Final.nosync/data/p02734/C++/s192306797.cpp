//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
           
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
           
using namespace std;
using namespace __gnu_pbds;
           
//#define int long long
  
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
           
using matrix = vector<vector<ll>>;
template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
           
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
  
void FAST_IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
    #ifndef _offline
    //freopen("mincost.in", "r", stdin);
    //freopen("mincost.out", "w", stdout);
    #endif
}

const int mod = 998244353;
const int MAXN = 3030;
int arr[MAXN], dp[MAXN];

signed main() {
    FAST_IO();
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = MAXN - 1; j >= arr[i]; --j) {
            dp[j] += dp[j - arr[i]];
            if (dp[j] >= mod) {
                dp[j] -= mod;
            }
        }
        dp[arr[i]] += i + 1;
        if (dp[arr[i]] >= mod) {
            dp[arr[i]] -= mod;
        } 
        ans += dp[s];
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << '\n';
}   