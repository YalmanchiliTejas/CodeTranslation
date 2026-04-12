#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
#define ft fflush(stdout)
 
 
using namespace std;
 
 
const int N = 3e5;
const int PLS = 3e5 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e16;


ll n, a[N], d, dp[10010][110];
string s;


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    cin >> d;
    dp[0][0] = 1;
    for (int i = 0; i <= 9; i++)
        dp[1][i % d]++;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < d; j++)
            for (int k = 0; k <= 9; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][((j - k) % d + 2 * d) % d]) % mod;
    ll ans = dp[n - 1][0], len = n, x = 0;
    for (int i = 0; i < n; i++) {
        ll start;
        if (i == 0)
            start = 1;
        else
            start = 0;
        for (int j = start; j < a[i]; j++)
            ans = (ans + dp[len - 1][((x - j) % d + 2 * d) % d]);
        len--;
        x = ((x - a[i]) % d + 2 * d) % d;
    }
    ll sm = 0;
    for (int i = 0; i < n; i++)
        sm += a[i];
    if (sm % d == 0)
        ans = (ans + 1) % mod;
    cout << ((ans - 1) % mod + 2 * mod) % mod;
}