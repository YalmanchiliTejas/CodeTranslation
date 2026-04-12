#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

lint tall[60];

lint solve(int n, lint x) {
    if (n == 0) {
        if (x == 0) return 0;
        else return 1;
    }

    if (x <= 1) {
        return 0;
    }
    else if (x <= tall[n-1] + 1) {
        return solve(n-1, x-1);
    }
    else if (x == tall[n-1] + 2) {
        return solve(n-1, x-2) + 1;
    }
    else if (x <= tall[n-1] * 2 + 2) {
        return solve(n-1, tall[n-1]) + solve(n-1, x - tall[n-1] - 2) + 1;
    }
    else {
        return 2 * solve(n-1, tall[n-1]) + 1;
    }
}

int main() {
    int n;
    cin >> n;
    lint x;
    cin >> x;

    tall[0] = 1;
    rep(i, n) tall[i+1] = 2 * tall[i] + 3;

    cout << solve(n, x) << endl;
    return 0;
}