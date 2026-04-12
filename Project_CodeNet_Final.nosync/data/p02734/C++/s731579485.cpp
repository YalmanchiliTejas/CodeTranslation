#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

// d[i][s][t] = i番目まで考えたとき和がsになる場合の数
LLONG dp[3001][3001][3];

int main()
{
    int N, S;  cin >> N >> S;
    vector<int> As(N);
    for (auto &Ai : As) cin >> Ai;
    dp[0][0][0] = 1;
    // i番目まで考えたとき和がsになる場合の数を全て計算:O(NS)
    for (int i = 0; i < N; ++i)
    {
        for (int s = 0; s <= S; ++s)
        {    
            // --- Aiを和に加えない場合 --------
            // t = 0 : L, Rともに未定
            (dp[i + 1][s][0] += dp[i][s][0]) %= MOD;
            // t = 1 : Lのみ確定
            (dp[i + 1][s][1] += dp[i][s][0] + dp[i][s][1]) %= MOD;
            // t = 2 : L, Rともに確定
            (dp[i + 1][s][2] += dp[i][s][0] + dp[i][s][1] + dp[i][s][2]) %= MOD;
            // --- Aiを和に加える場合 --------
            // 和がS以下になる場合の数を全て記録していく
            int tmpSum = s + As[i];
            if (tmpSum <= S)
            {
                (dp[i + 1][tmpSum][1] += dp[i][s][0] + dp[i][s][1]) %= MOD;
                (dp[i + 1][tmpSum][2] += dp[i][s][0] + dp[i][s][1]) %= MOD;
            }
        }
    }
    cout << dp[N][S][2] << endl;
}
