#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];

    int res = 0;
    int m = -1;

    rep(i, n) {
        m = max(m, h[i]);
        if (m == h[i]) res++;
    }
    cout << res << endl;
    return 0;
}
