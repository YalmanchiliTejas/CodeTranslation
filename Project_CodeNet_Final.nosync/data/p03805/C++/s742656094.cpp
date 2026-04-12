#include<iostream>
#include<cstring>
using namespace std;
const int BUF = 10;


int N;
bool adj[BUF][BUF];

void read() {
    int nEdge;
    memset(adj, 0, sizeof(adj));
    
    cin >> N >> nEdge;
    for (int i = 0; i < nEdge; ++i) {
        int s, t;
        cin >> s >> t;
        --s;
        --t;
        adj[s][t] = adj[t][s] = true;
    }
}


int rec(int cur, int mask, int dp[BUF][1 << BUF]) {
    int &ret = dp[cur][mask];
    if (ret != -1) return ret;
    
    if (mask == (1 << N) - 1) {
        return ret = 1;
    }
    
    ret = 0;
    for (int i = 0; i < N; ++i) {
        if (!adj[cur][i]) continue;
        if ((1 << i) & mask) continue;
        ret += rec(i, mask | (1 << i), dp);
    }
    
    return ret;
}

void work() {
    static int dp[BUF][1 << BUF];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, dp) << endl;
}


int main() {
    read();
    work();
    return 0;
}
