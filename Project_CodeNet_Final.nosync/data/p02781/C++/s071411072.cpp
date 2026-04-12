/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>

#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>

#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

// type
#include <cstdint>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

int dp[105][2][5];

signed main() {
    string str;
    int K;
    cin >> str >> K;
    int N = str.size();

    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= K; k++) {
                for (int n = 0; n < 10; n++) {
                    int num = str[i] - '0';
                    if (j == 0 && n > num) continue;
                    dp[i+1][j || n < num][(n == 0) ? k : k+1] += dp[i][j][k];
                }
            }
        }
    }

    int ret = 0;
    for (int j = 0; j < 2; j++) {
        ret += dp[N][j][K];
    }

    cout << ret << endl;
    return 0;
}