#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int D = (int) 1e2 + 10;
const int N = (int) 1e4 + 10;
const int mod = (int) 1e9 + 7;

int n, d;
string s;
int memo[2][D][N];

int dp(int at, int md, bool bounded) {
    if(at == n) return md == 0;
    int &ans = memo[bounded][md][at];
    if(ans != -1) return ans;
    ans = 0;
    int mx = bounded ? s[at]-'0' : 9;
    for(int i = 0; i <= mx; ++i) {
        ans += dp(at + 1, (md + i) % d, bounded && i == mx);
        ans %= mod;
    }
    return ans;
}

void solve() {
    cin >> s >> d;
    n = s.length();
    memset(memo, -1, sizeof(memo));
    int ans = dp(0, 0, true) - 1;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    solve();
    return 0;
}