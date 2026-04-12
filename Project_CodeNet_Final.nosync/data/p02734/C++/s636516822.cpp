#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define mem(i, j) memset(i, j, sizeof(i))
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define dep(i, j, k) for(int i = k; i >= j; i--)
#define pb push_back
#define make make_pair
#define INF INT_MAX
#define inf LLONG_MAX
#define PI acos(-1)
#define fir first
#define sec second
using namespace std;

const int N = 1e6 + 5;

const LL mod = 998244353;

LL ksm(LL a, LL b) { LL ans = 1LL; while(b) { if(b & 1) ans = ans * a % mod; a = a * a % mod; b >>= 1; }  return ans; }

LL dp[N];
int a[N];

void solve() {

    int n, m;
    scanf("%d %d", &n, &m);
    rep(i, 1, n) {
        scanf("%d", &a[i]);
    }

    LL ans = 0;

    rep(i, 1, n) {
        if(a[i] == m) ans = (ans + 1LL * i * (n - i + 1) % mod) % mod;
        else if(m > a[i]) ans = (ans + dp[m - a[i]] * (n - i + 1) % mod) % mod;
        dep(j, a[i], m) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            if(j == a[i]) dp[j] = (dp[j] + i) % mod;
        }
    }

    printf("%lld\n", ans);

}


int main() {
//    int _; scanf("%d", &_);
//    while(_--) solve();


    solve();

    return 0;
}
