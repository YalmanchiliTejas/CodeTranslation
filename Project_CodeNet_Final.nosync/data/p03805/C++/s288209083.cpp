#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define rep(n, i) Rep(0, n-1, i)
#define MAX 8

int path[MAX][MAX];

int dfs(bool* flags, int n, int now){
    bool flag = true;
    int res = 0;
    rep(n, i) flag = flag && flags[i];
    if (flag) return 1;
    rep(n, i) {
        if (!flags[i] && path[now][i]) {
            flags[i] = true;
            res += dfs(flags, n, i);
            flags[i] = false;
        }
    }
    return res;
}

void solve(void){
    int n, m;
    scanf("%d%d\n",&n, &m);
    rep(m, i){
        int a, b; scanf("%d%d\n", &a, &b);
        path[a-1][b-1] = 1;
        path[b-1][a-1] = 1;
    }
    bool flags[n];
    flags[0] = true;

    cout << dfs(flags, n, 0) << '\n';
}

int main(void){
  solve();
  return 0;
}
