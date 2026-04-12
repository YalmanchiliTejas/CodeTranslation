#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

typedef long long ll;

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }

ll LCM(ll x, ll y)
{
    return x * y / GCD(x, y);
}

typedef pair<int, int> P;

//dp[i][j][k]
// N以下でi桁目までで0でない数字をj個含む（k=0なら一致，k=1なら未満）
ll dp[105][4][2];

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;

    dp[0][0][0] = 1;
    rep(i, n) rep(j, K + 1) rep(k, 2)
    {
        int d = s.at(i) - '0';
        for (int nd = 0; nd < 10; nd++) {
            int ni = i + 1, nj = j, nk = k;
            if (nd != 0) {
                nj++;
            }
            if (nj > K)
                continue;
            if (k == 0) {
                if (nd > d)
                    continue;
                if (nd < d)
                    nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }

    ll ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
}
