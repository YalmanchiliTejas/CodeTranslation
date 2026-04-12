#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS

    string s; cin >> s;
    int k; cin >> k;
    int ss = s.size();
    ll ans = 0;

    vector<vector<vector<int>>> dp(ss+1,vector<vector<int>>(k+1,vector<int>(2)));
    dp[0][0][0] = 1;

    REP(i,ss) REP(j,k+1) REP(a,2) {
        int d = s[i] - '0';
        REP(x,10) {
            int i2 = i+1;
            int j2 = x != 0 ? j+1 : j;
            int a2 = (a == 1 || d > x) ? 1 : 0;
            if (j2 > k) continue;
            if (a2 == 0 && d < x) continue;
            dp[i2][j2][a2] += dp[i][j][a];
        }
    }

    ans = dp[ss][k][0] + dp[ss][k][1];

    cout << ans << '\n';

    return 0;
}