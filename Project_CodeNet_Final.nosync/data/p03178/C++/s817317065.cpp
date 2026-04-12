#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 1e4 + 5;
const int inf = 1e15;

string s;

int dp[N][105][4], d;

int solve(int pos, int m, int lim, int ok) {
    if(pos == lim) {
        if(ok == 2) return 0;
        if(m == 0)
            return 1;
        else
            return 0;
    }
    int ans = dp[pos][m][ok];
    //if(m == 0)
    //cout << pos << " " << m << " " << ok << " " << ans << "\n";
    if(ans != -1) return ans;
    if(m == 0)
        ans = 1;
    else
        ans = 0;
    int l = 0, r = 9;
    if(pos == 0) l = 1;
    for(int i = l; i <= r; i++) {
        int ck = ok;
        if(ok == 1 && i == s[pos] - '0') ck = 1;
        if(ok == 1 && i > s[pos] - '0') ck = 2;
        if(ok == 1 && i < s[pos] - '0') ck = 0;
        int lmao = solve(pos + 1, (m + i) % d, lim, ck);
        ans = (ans + lmao) % mod;
    }
    //cout << pos << " " << m << " " << ok << " " << ans << "\n";
    dp[pos][m][ok] = ans;
    return ans;
}

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> s >> d;
    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < d; j++) {
            for(int k = 0; k <= 2; k++)
                dp[i][j][k] = -1;
        }
    }
    cout << (solve(0, 0, s.length(), 1) - 1 + mod) % mod;
}

