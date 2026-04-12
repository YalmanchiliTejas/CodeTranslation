#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int> > adj;
vector<vector<int> > dp, cdp, rdp;
void dfs(int u, int p) {
    int ccnt = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        ccnt++;
        dfs(v, u);
    }
    if(!ccnt) {
        dp[u][0] = 0;
        dp[u][1] = 1;
        return;
    }
    cdp[u].resize(ccnt);
    rdp[u].resize(ccnt);
    int pos = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        cdp[u][pos] = dp[v][0];
        if(pos) cdp[u][pos] &= cdp[u][pos - 1];
        pos++;
    }
    pos = ccnt - 1;
    for(int i = adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];
        if(v == p) continue;
        rdp[u][pos] = dp[v][0];
        if(pos != ccnt - 1) rdp[u][pos] &= rdp[u][pos + 1];
        pos--;
    }
    dp[u][0] = 0;
    pos = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        dp[u][0] |= dp[v][1] & (pos == 0 || cdp[u][pos - 1]) & (pos == ccnt - 1 || rdp[u][pos + 1]);
        pos++;
    }
    dp[u][1] = cdp[u].back();
}

int main() {
    scanf("%d", &N);
    adj.resize(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp = vector<vector<int> >(N, vector<int>(2));
    cdp.resize(N);
    rdp.resize(N);
    dfs(0, -1);
    if(dp[0][0]) printf("Second");
    else printf("First");
}
