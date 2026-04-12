#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define rep(i, n) REP(i, 0, n)
#define REP(i, a, n) for(int i=(a); i<(n); i++)

int N, M, K;
int did_num[20];
int num_did[120];
int v[120][120];
int dp[1<<16];


int main() {
    rep(i, 120) num_did[i] = -1;
    rep(i, 1<<16) dp[i] = INT_MAX;

    cin >> N >> M >> K;
    rep(i, M) { int x; cin >> x; did_num[i] = x-1; num_did[x-1] = i; }
    rep(i, N) rep(j, K) { int x; cin >> x; v[i][j] = x-1; }

    dp[(1<<M)-1] = 0;
    queue<int> que;
    que.push((1 << M) - 1);
    while(!que.empty()) {
        int s = que.front(); que.pop();
        int t = dp[s];
        rep(k, K) {
            int ns = 0;
            rep(i, M) {
                if(s>>i & 1) {
                    int src = did_num[i];
                    int tgt = v[src][k];
                    if(num_did[tgt] >= 0) ns |= 1 << num_did[tgt];
                }
            }
            if(ns == 0) {
                cout << t + 1 << endl;
                return 0;
            }
            if(dp[ns] > t + 1) {
                dp[ns] = t + 1;
                que.push(ns);
            }
        }
    }
}

