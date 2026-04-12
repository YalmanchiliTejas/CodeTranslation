#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <cassert>
#include <memory>
using namespace std;
typedef long long ll;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

ll N,S;
ll A[3010];
ll MOD = 998244353LL;

// i: 何番目か, j:合計, k: 0-Lが未確定, 1-Lが確定R未確定, 2-LとRが確定
ll dp[3010][7010][3];

int main ()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    dp[0][0][0] = 1LL;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
            (dp[i + 1][j + A[i]][1] += dp[i][j][0] * (i + 1)) %= MOD;
            (dp[i + 1][j + A[i]][2] += dp[i][j][0] * (i + 1) * (N - i)) %= MOD;

            (dp[i + 1][j][1] += dp[i][j][1]) %= MOD;
            (dp[i + 1][j + A[i]][1] += dp[i][j][1]) %= MOD;
            (dp[i + 1][j + A[i]][2] += dp[i][j][1] * (N - i)) %= MOD;

            (dp[i + 1][j][2] += dp[i][j][2]) %= MOD;
        }
    }

    cout << dp[N][S][2] << endl;

    return 0;
}
