#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string k;
    int d;
    ll dp[10001][2][100];

    cin >> k >> d;

    memset(dp, 0, sizeof(dp));

    dp[0][1][(k[0] - '0') % d] = 1;
    for (int i = 0; i < (k[0] - '0'); i++)
    {
        dp[0][0][i % d] += 1;
    }

    for (int i = 0; i < k.size() - 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int l = 0; l < 100; l++)
            {

                if (dp[i][j][l] < 1)
                    continue;

                if (j == 1)
                {
                    (dp[i + 1][1][(l + (k[i + 1] - '0')) % d] += dp[i][j][l]) %= MOD;
                    for (int m = 0; m < (k[i + 1] - '0'); m++)
                    {
                        (dp[i + 1][0][(l + m) % d] += dp[i][j][l]) %= MOD;
                    }
                }
                else
                {
                    for (int m = 0; m < 10; m++)
                    {
                        (dp[i + 1][0][(l + m) % d] += dp[i][j][l]) %= MOD;
                    }
                }
            }
        }
    }

    cout << (dp[k.size() - 1][0][0] + dp[k.size() - 1][1][0] - 1 + MOD) % MOD << endl;

    return 0;
}