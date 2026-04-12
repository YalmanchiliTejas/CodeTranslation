#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*********** Constants ***********/
const auto INF = static_cast<ll>(1e15);
const auto MOD = static_cast<ll>(1e9 + 7);

/*********** Variables ***********/
ll N;
vector<ll> A;
vector<vector<ll>> DP;

/*********** Functions ***********/
void initialize() {
    cin >> N;
    A.resize(N);
    for (auto& item : A) cin >> item;
    DP.resize(N + 1, vector<ll>(N + 1, 0));
}

void solve() {
    for (ll len = 1; len <= N; len++) {
        for (ll i = 0; i + len <= N; i++) {
            ll j = i + len;
            if ((N - len) % 2) {
                DP[i][j] = min(DP[i + 1][j] - A[i], DP[i][j - 1] - A[j - 1]);
            }
            else {
                DP[i][j] = max(DP[i + 1][j] + A[i], DP[i][j - 1] + A[j - 1]);
            }
        }
    }
}

void output() {
    cout << DP[0][N] << endl;
}

int main() {
    initialize();
    solve();
    output();
    return 0;
}
