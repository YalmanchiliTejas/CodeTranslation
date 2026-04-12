#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 5;
vector<int> G[MAXN];

int dp[MAXN][2];

void dfs(int node, int f) {
    int cnt = 0;
    for(auto temp : G[node]) {
        if(temp == f)
            continue;
        dfs(temp, node);
        dp[node][0] += max(dp[temp][0], dp[temp][1]);
        if(dp[temp][0] == dp[temp][1]) {
            cnt = 1;
        }
    }

    dp[node][1] = dp[node][0] + cnt;
}

int main() {
    //ifstream cin("D.in");
    int n; cin >> n;
    
    for(int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    

    dfs(0, -1);

    int match = max(dp[0][0], dp[0][1]);
    
    if(2 * match < n) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}