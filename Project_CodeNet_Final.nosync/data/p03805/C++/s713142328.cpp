#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long llong;

static const int MAX = 10;
int M[MAX][MAX];
int dp[1<<MAX][MAX];
int n, m;

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) M[i][j] = 0;
    }

    int x, y;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        x--; y--;
        M[x][y] = 1;
        M[y][x] = 1;
    }

    dp[1][0] = 1;

    int cnt;
    int sub;
    for (int i = 0; i < (1<<n); i++){
        for (int j = 0; j < n; j++){
            if (!(i & (1<<j))) continue;

            sub = i ^ (1<<j);
            for (int k = 0; k < n; k++){
                if (M[j][k] == 1) dp[i][j] += dp[sub][k];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += dp[(1<<n) - 1][i];
    }
    cout << ans << endl;
    return 0;
}