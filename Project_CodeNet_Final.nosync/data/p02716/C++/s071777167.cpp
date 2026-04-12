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

constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    int n;
    cin >> n;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    if (n <= 3) {
        cout << *max_element(all(a)) << endl;
        return;
    }
    if (n % 2 == 0) {
        LL l = 0, r = 0;
        REP(i,0,n/2) {
            l += a[i*2];
            r += a[i*2+1];
        }
        LL ans = -(1LL<<60);
        //cout << max(l,r) << endl; 
        ans = max({ans, l, r});

        VLL lru(n), rru(n);
        lru[0] = a[0];
        lru[1] = a[1];
        rru[n-2] = a[n-2];
        rru[n-1] = a[n-1];
        REP(i,2,n) lru[i] = lru[i-2] + a[i];
        RREP(i,0,n-2) rru[i] = rru[i+2] + a[i];
        REP(i,0,n-3) {
            if (i % 2 == 1) continue;
            LL sum = lru[i] + rru[i+3];
            ans = max(ans, sum);
            //dump(sum);
        }
        cout << ans << endl;
        return;
    }

    // n > 3
    VVLL dp(n,VLL(3, -(1LL<<50)));
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    dp[2][2] = a[2];
    dp[2][0] = a[0] + a[2];
    REP(i,3,n) {
        dp[i][2] = a[i] + max({dp[i-2][2], dp[i-3][1]});
        if (i > 3) chmax(dp[i][2], a[i] + dp[i-4][0]);
        if (i < n - 1) dp[i][1] = a[i] + max({dp[i-2][1], dp[i-3][0]});
        if (i < n - 2) dp[i][0] = a[i] + dp[i-2][0];
    }
    cout << max({dp[n-1][2], dp[n-2][1], dp[n-3][0]}) << endl;

    return;

    REP(i,0,n) {
        cout << a[i] << ": ";
        REP(j,0,3) {
            cout << (dp[i][j] < -1000 ? -1000 : dp[i][j]) << " ";
        }
        cout << endl;
    }
}

signed main() {
    solve();
    
    return 0;
}