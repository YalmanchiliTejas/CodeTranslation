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
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
//#define int long long

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
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

constexpr int MOD = 998244353;

void solve() {
    int n,s;
    cin >> n >> s;
    VI a(n);
    REP(i,0,n) cin >> a[i];
    VI ru(n+1);
    REP(i,0,n) ru[i+1] = ru[i] + a[i];
    VVLL dp(n,VLL(3000+1));
    dp[0][a[0]] = 1;
    REP(i,1,n) {
        dp[i][a[i]] = i + 1;
        REP(j,0,3000+1) {
            dp[i][j] += dp[i-1][j];
            if (j >= a[i]) dp[i][j] = (dp[i][j] + dp[i-1][j - a[i]]) % MOD;
        }
    }
    LL ans = 0;
    REP(i,0,n) ans = (ans + dp[i][s]) % MOD;
    cout << ans << endl;

    return;

    REP(i,0,n) {
        REP(j,0,s+1) cout << dp[i][j] << " ";
        cout << endl;
    }
}

signed main() {
    solve();
    
    return 0;
}