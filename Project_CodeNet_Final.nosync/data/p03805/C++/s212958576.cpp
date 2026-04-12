#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> G[10];
long long memo[10][1000];
long long solve(int i, int used) {
    if (memo[i][used] != -1) return memo[i][used];
    if (used == (1 << N)-1) return 1;
    long long res = 0;
    for (auto x: G[i]) {
        if ((used & (1 << x)) == 0) {
            res += solve(x, used+(1 << x));
        }
    }
    return memo[i][used] = res;
}
int main () {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 1000; j++) 
            memo[i][j] = -1;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << solve(0, 1) << endl;
}