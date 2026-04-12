#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const long long MOD = 1e9 + 7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int d, n;
    cin >> s >> d;
    n = s.length();
    lli dp[n][d];
    fop (i,0,n) fop (j,0,d) dp[i][j] = 0;
    dp[0][0] = 1;
    fop (i,1,n) {
        fop (j,0,10) {
            fop (k,0,d) {
                int t = (k - j) % d;
                if (t < 0) t += d;
                dp[i][k] += dp[i - 1][t];
                if (dp[i][k] >= MOD) dp[i][k] -= MOD;
            }
        }
    }
    lli ans = 0;
    int now = 0;
    fop (i,0,n) {
        fop (j,0,s[i]-'0') {
            int t = (- now - j) % d;
            if (t < 0) t += d;
            ans += dp[n - i - 1][t];
            if (ans >= MOD) ans -= MOD;
        }
        now += (s[i] - '0');
    }
    now %= d;
    ans--;
    if (now == 0) ans++;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}