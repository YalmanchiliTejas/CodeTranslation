#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx,tune=native")
//Use above if bruteforcing with lots of small operations. Or just use it anytime, there's no downside.
//AVX is better slightly
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;

ll inv(ll a, ll b){
    return (a > 1 ? b - inv(b%a, a)*b/a : 1);
}

#define rc(s) return cout << s, 0
#define fi first
#define se second
#define L (nod << 1)
#define R (L | 1)
#define smax(X, Y) ((X) > (Y) ? (X) : (Y))
#define smin(X, Y) ((X) < (Y) ? (X) : (Y))

const int MOD = 998244353;
const int N = 3010;

const ld e = 2.71828182845904523536028747;
const ld PI = 3.14159265359;
const ll inf = (1LL<<62);
const int iinf = (1<<30);
//CLOCKS_PER_SEC

int n, s, dp[N][N];
ll ans;

int main(){
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(0); cin.tie(0);
    //ifstream cin ("test.in");
    cin >> n >> s;
    for (int i=1, x; i<=n; i++){
        cin >> x;
        for (int j=1; j<=s; j++) dp[i][j] = dp[i-1][j];
        if (x == s) ans = (ans + i * (n - i + 1)) % MOD;
        for (int j=s; j>=x; j--){
            if (j == s) ans = (ans + 1LL * (n - i + 1) * dp[i-1][j-x]) % MOD;
            else if (j == x) dp[i][j] = (dp[i][j] + i) % MOD;
            else dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;
        }
    }
    cout << ans;
    return 0;
}
