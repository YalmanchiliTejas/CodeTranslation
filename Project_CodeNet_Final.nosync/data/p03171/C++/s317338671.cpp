#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
 
 
#define F first
#define S second
#define ll long long
#define pb push_back
#define db double
#define ld long double
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define piii pair<int, pii>
#define all(x) (x).begin(),(x).end()
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define int long long
 
const int N = 1e5 + 1, inf = 2e9 + 7, mod = 1e9 + 7;
const ll INF = 2e18 + 7, MOD = 1e15 + 7;

int a[5005], dp[5005][5005], sum = 0;

signed main() { __
//    freopen("lcm.in", "r", stdin);
//    freopen("lcm.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        dp[i][i] = ((n - 1) % 2) + 1 == 2 ? 0 : a[i];
    }
    //dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            if(((n - (j - i + 1)) % 2) + 1 == 2) dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            else dp[i][j] = max(a[i] + dp[i + 1][j], a[j] + dp[i][j - 1]);
        }
    }
    cout << dp[1][n] - (sum - dp[1][n]);
    return 0;
}

