#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <cstring>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

constexpr int MOD = 1'000'000'007;

LL dp[10001][100][2] = {};

void solve() {
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 1;
    REP(i,0,n) {
        REP(j,0,d) {
            if (dp[i][j][0] != -1) {
                dp[i+1][(j+s[i]-'0')%d][0] = dp[i][j][0];
                REP(k,0,s[i]-'0') {
                    dp[i+1][(j+k)%d][1] = max(0LL,dp[i+1][(j+k)%d][1]);
                    dp[i+1][(j+k)%d][1] += dp[i][j][0];
                    if (dp[i+1][(j+k)%d][1] >= MOD) dp[i+1][(j+k)%d][1] -= MOD;
                }
            }
            if (dp[i][j][1] != -1) {
                REP(k,0,10) {
                    dp[i+1][(j+k)%d][1] = max(0LL,dp[i+1][(j+k)%d][1]);
                    dp[i+1][(j+k)%d][1] += dp[i][j][1];
                    if (dp[i+1][(j+k)%d][1] >= MOD) dp[i+1][(j+k)%d][1] -= MOD;
                }
            }
        }
    }
    cout << (max(0LL, dp[n][0][0]) + max(0LL, dp[n][0][1]) - 1 + MOD) % MOD << endl;
}

int main() {
    solve();
    
    return 0;
}