#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#define BIT(nr) (1ULL << (nr))
#define int long long
#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }


using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N+1);
    vector<map<int, pair<int, int>>> dp(N+1);
    REPS(i, N) { 
        cin >> A[i];
    }

    dp[0][0] = mp(0, 0);

    function<int(int, int, bool)> rec = [&](int i, int j, bool used) -> int {
        if (!((i - 1) / 2 <= j && j <= (i + 1) / 2)) {
            return -LL_HALFMAX;
        }
        
        // 停止条件
        if (i == 0 && j != 0) {
            return -LL_HALFMAX;
        }

        
        // 既に評価済みのノード
        if (dp[i].count(j) == 1) {
            if (used) {
                return dp[i][j].second;
            }
            else {
                return dp[i][j].first;
            }
        }

        int f = max(rec(i - 1, j, false), rec(i - 1, j, true));
        int s = rec(i - 1, j - 1, false) + A[i];

        dp[i][j] = mp(f, s);

        return used ? s : f;
    };

    int ans = max(rec(N, (N) / 2, true), rec(N, (N) / 2, false));

    cout << ans << "\n";

    return 0;
}
