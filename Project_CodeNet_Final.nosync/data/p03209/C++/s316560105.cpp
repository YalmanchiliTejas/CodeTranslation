#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

ll N, X;
vector<ll> memo(51, -1);
vector<ll> num(51);

ll dfs(int level) {
    if (memo[level] != -1 && X >= num[level]) {
        X -= num[level];
        return memo[level];
    }
    ll ret = 0;
    X--; // bun
    if (X > 0) ret += dfs(level - 1);
    if (X > 0) {
        // patty
        X--;
        ret++;
    }
    if (X > 0) ret += dfs(level - 1);
    if (X > 0) {
        // bun
        X--;
        memo[level] = ret;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memo[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= 50; i++) num[i] = 2 * num[i-1] + 3;

    cin >> N >> X;
    cout << dfs(N) << endl;
}