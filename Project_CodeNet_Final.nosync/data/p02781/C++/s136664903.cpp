#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#define rep(i, s, g) for (i = s; i <= g; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1e9 + 7;

int ctoi(char c)
{
    return (int)(c - 48);
}

int main(void)
{
    int K;
    string N;
    ll ans;
    int i, j, k;
    int d;
    static int dp[110][4][2];

    cin >> N >> K;

    int l = N.size();

    dp[0][0][0] = 1;

    rep(i, 0, l - 1)
    {
        int nd = ctoi(N[i]);
        rep(j, 0, 3)
        {
            rep(k, 0, 1)
            {

                rep(d, 0, 9)
                {
                    int ni = i + 1, nj = j, nk = k;
                    if (d != 0)
                    {
                        nj++;
                        if (nj > K)
                        {
                            continue;
                        }
                    }

                    if (k == 0)
                    {
                        if (nd < d)
                        {
                            continue;
                        }
                        else if (nd > d)
                        {
                            nk = 1;
                        }
                    }

                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[l][K][0] + dp[l][K][1] << endl;
}