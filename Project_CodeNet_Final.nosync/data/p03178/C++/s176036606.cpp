#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

string K;
ll D;

constexpr ll MOD = 1e9 + 7;

vector<vector<vector<ll>>> memo;

ll solve(ll i, ll j, bool equal) {
    if (i == K.size()) {
        return j == 0;
    }

    if (memo[i][j][equal] != -1) {
        return memo[i][j][equal];
    }

    ll result = 0;
    if (equal) {
        for (ll k = 0; k <= K[i] - '0'; k++) {
            (result += solve(i + 1, (j + k) % D, k == K[i] - '0')) %= MOD;
        }
    } else {
        for (ll k = 0; k < 10; k++) {
            (result += solve(i + 1, (j + k) % D, false)) %= MOD;
        }
    }
    return memo[i][j][equal] = result;
}

int main() {
    cin >> K >> D;
    memo.resize(K.size(), vector<vector<ll>>(D, vector<ll>(2, -1)));

    cout << (solve(0, 0, true) + MOD - 1) % MOD << endl;
}