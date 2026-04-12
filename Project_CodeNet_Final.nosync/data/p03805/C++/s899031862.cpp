#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <ctime>

using namespace std;
#define RN cout << "\r\n";
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef long long int ll;
typedef pair<ll, ll> P;

// combination
const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void dfs(int &a, vector<vector<bool>> &graph, int &ans, vector<bool> &passed, int current) {
    bool complete = true;
    REP(i, a) {
        if (!passed[i]) {
            complete = false;
        }
    }
    if (complete) {
        ans++;
        return;
    }
    REP(j, a) {
        if (graph[current][j] && !passed[j]) {
            vector<bool> new_passed(passed);
            new_passed[j] = true;
            dfs(a, graph, ans, new_passed, j);
        }
    }
    return;
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<bool>> graph;
    graph = vector<vector<bool>>(a, vector<bool>(a, false));
    REP(i, b) {
        int c, d;
        cin >> c >> d;
        graph[c - 1][d - 1] = true;
        graph[d - 1][c - 1] = true;
    }
    int ans = 0;
    vector<bool> passed(a, false);
    passed[0] = true;
    dfs(a, graph, ans, passed, 0);
    cout << ans << endl;
    return 0;
}
