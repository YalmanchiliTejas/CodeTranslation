#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 1e5+100;

int n;

vector<int> v[N];

bool ok = 1, dp[N][3];

void dfs(int x, int px = -1) {
    for(int u: v[x]) {
        if(u != px) dfs(u, x);
    }
    int zero=0, one=0;
    for(int u: v[x]) {
        if(u != px) {
            if(dp[u][0]) zero++;
            if(dp[u][1]) one++;
        }
    }
    if(zero + one != (int)v[x].size() - (px != -1)) return;
    if(zero == 1) {
        dp[x][1] = 1;
    }
    if(zero == 0) {
        dp[x][0] = 1;
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0, u1, u2 ; i < n - 1 ; i++ ) {
        cin >> u1 >> u2;
        u1--;
        u2--;
        v[u1].PB(u2);
        v[u2].PB(u1);
    }
    dfs(0);
    cout << ((dp[0][1]) ? "Second" : "First") << '\n';
}
