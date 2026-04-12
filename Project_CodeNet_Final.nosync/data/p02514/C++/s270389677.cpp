#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n);i++)
#define mp make_pair
#define pb push_back
#define INF (1<<28)

int diff(const pair<int, int>& a, const pair<int, int>& b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int w, h, f[128][128];
char buf[128];

int main() {
    for(;;) {
        scanf("%d%d", &w, &h);
        if(w==0 && h==0) return 0;
        memset(f, 0, sizeof(f));
        int sx, sy, gx, gy;
        rep(i, h) rep(j, w) {
            scanf("%s", buf);
            if(buf[0]=='.') f[i][j] = 0;
            else if(buf[0]=='S') f[i][j]=1, sx=i, sy=j;
            else if(buf[0]=='G') gx=i, gy=j;
            else f[i][j] = atoi(buf)+1;
        }
        int m = 0;
        rep(i, h) rep(j, w) m = max(m, f[i][j]);
        vector<vector<pair<int, int> > > loc(m, vector<pair<int, int> >());
        vector<vector<int> > dp(m, vector<int>());
        rep(k, m) rep(i, h) rep(j, w) if(f[i][j]==k+1) {
            loc[k].push_back(mp(i, j));
            dp[k].push_back(INF);
        }
        dp[0][0] = 0;
        rep(k, m-1) rep(i, dp[k].size()) rep(j, dp[k+1].size()) {
            dp[k+1][j] = min(dp[k+1][j], dp[k][i]+diff(loc[k+1][j], loc[k][i]));
        }
        int ans = INF;
        rep(i, dp[m-1].size()) {
            ans = min(ans, dp[m-1][i]+diff(loc[m-1][i], mp(gx, gy)));
        }
        printf("%d\n", ans);
    }
}