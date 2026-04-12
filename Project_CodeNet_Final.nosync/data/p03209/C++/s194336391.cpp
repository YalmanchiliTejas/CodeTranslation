#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int MOD = 1e9 + 7;

ll solve(int level, ll x) {
    if (x <= 0)
        return 0;
    if (level == 0)
        return !!x;
    ll cnt = (1LL << (level + 2)) - 3, pcnt = (1LL << level) - 1;
    ll tmp = 0;
    if (x <= cnt / 2 + 1)
        return solve(level - 1, x - 1) + (x == cnt / 2 + 1);
    else
        return solve(level - 1, x - cnt / 2 - 1) + pcnt + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll X;
    cin >> N >> X;

    cout << solve(N, X) << endl;

    return 0;
}
