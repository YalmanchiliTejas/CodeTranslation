#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 1e4 + 5;

string n;
ll d, dp[N][2][105];

ll solve(int i, int j, ll val) {
    if (i == (int) n.size()) 
        return val == 0;
    ll& ret = dp[i][j][val];
    if (~ret) return ret;
    ret = 0;
    int cur = n[i] - '0';
    if (j) {
        for (int nxt = 0; nxt < 10; ++nxt)
            (ret += solve(i + 1, 1, (val + nxt) % d)) %= MOD;
    } else {
        (ret += solve(i + 1, 0, (val + cur) % d)) %= MOD;
        for (int nxt = 0; nxt < cur; ++nxt)
            (ret += solve(i + 1, 1, (val + nxt) % d)) %= MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n >> d;
    memset(dp, -1, sizeof(dp));
    cout << ((solve(0, 0, 0) - 1) % MOD + MOD) % MOD << endl;
}
