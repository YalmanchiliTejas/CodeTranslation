#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

using namespace std;

typedef long long int lli;

int main () {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> D(M);
    vector<int> is(N, -1);
    REP (i, 0, M) {
        cin >> D[i];
        is[D[i] - 1] = i;
    }
    vector<vector<int>> v(N, vector<int>(K));
    REP (i, 0, N) REP (j, 0, K) cin >> v[i][j];
    int size = 1 << M;
    const int inf = 1 << 30;
    vector<int> dp(size, inf);
    queue<int> q;
    q.push(size - 1);
    dp[size - 1] = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        REP (i, 0, K) {
            int bt = 0;
            REP (j, 0, M) {
                if ((t >> j) & 1) {
                    int nxt = v[D[j] - 1][i] - 1;
                    if (is[nxt] != -1) {
                        bt |= (1 << is[nxt]);
                    }
                }
            }
            if (dp[bt] > dp[t] + 1) {
                q.push(bt);
                dp[bt] = dp[t] + 1;
            }

        }
    }
    cout << dp[0] << endl;
    return 0;
}