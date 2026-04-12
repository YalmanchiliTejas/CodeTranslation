#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int n, m;
static const int MAX = 8;
int G[MAX][MAX];

void solve(){
    int res = 0, sub;
    int dp[(1<<n)][n];
    for (int i = 0; i < (1<<n); i++){
        for (int j = 0; j < n; j++){
            if (i == 1 && j == 0) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    for (int i = 1; i < (1<<n); i++){
        for (int j = 0; j < n; j++){
            if (!(i & (1<<j))) continue;
            sub = i ^ (1<<j);
            for (int k = 0; k < n; k++){
                if (!(sub & (1<<k))) continue;
                if (G[k][j] == 1) dp[i][j] += dp[sub][k];
            }
        }
    }
    for (int i = 0; i < n; i++) res += dp[(1<<n) - 1][i];
    cout << res << endl;
}

int main(){
    sc(n) sc(m)
    int x, y;
    fill((int*)G, (int*)(G + n), 0);
    for (int i = 0; i < m; i++){
        sc(x) sc(y)
        x--; y--;
        G[x][y] = 1;
        G[y][x] = 1;
    }
    solve();
    return 0;
}