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

int main() {
    lint n, k;
    cin >> n >> k;

    lint res = 0;

    if (k == 0) {
        cout << n * n << endl;
        exit(0);
    }

    for (int b = k+1; b <= n; b++) {
        lint t = n / b;
        res += t * (b-k);
        lint t2 = n % b;
        res += max(0LL, t2 - k + 1);
    }

    cout << res << endl;
    return 0;
}