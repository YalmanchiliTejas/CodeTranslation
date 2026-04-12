#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
#include <numeric>

using namespace std;
#define INF 99999
#define _GLIBCXX_DEBUG
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REPS(i,a,n) for(int i=(a);i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define fi first
#define se second
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vint a(M);
    vint b(M);
    REP(i, M) cin >> a[i] >> b[i];

    int adj[N][N];
    REP(i, N)REP(j, N)adj[i][j] = 0;

    REP(i, M){
        adj[a[i]-1][b[i]-1] = 1;
        adj[b[i]-1][a[i]-1] = 1;
    }

    int univ = (1 << N) - 1;
    int dp[1 << N][N];

    REP(S, 1 << N){
        REP(v, N){
            dp[S][v] = 0;
        }
    }
    dp[1][0] = 1;

    REPS(S, 2, (1 << N)+1) REP(v, N){
        int S2 = S & (univ ^ (1 << v)); // S \ {v}
        dp[S][v] = 0;
        REP(u, N) {
            if (((1 << u) & S2) && adj[u][v]){
                dp[S][v] += dp[S2][u];
            }
        }
    }

//    REP(S, 1 << N){
//        REP(v, N){
//            cout << dp[S][v] << " ";
//        }
//        cout << endl;
//    }

    int ans = 0;
    REP(u, N){
        ans += dp[univ][u];
    }
    cout << ans;
}