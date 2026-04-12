#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int N = 3333;

typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

int n;
vector<int> ns;
llint dp[N][N];

llint dfs(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != INF) {
        return dp[l][r];
    }
    int m = r - l + 1;
    int delta = n - m;

    int flag = delta % 2 == 0? 1: -1;

    llint a = flag * ns[l] + dfs(l + 1, r);
    llint b = flag * ns[r] + dfs(l, r - 1);

    return dp[l][r] = delta % 2 == 0? max(a, b): min(a, b);
}

int main() {
    input(n);

    memset(dp, 0x3f, sizeof(dp));
    ns = vector<int>(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }
    print(dfs(0, n - 1));
    return 0;
}
