#include "bits/stdc++.h"

using namespace std;

#define ll long long int

static const int maxn = 3000 + 5;

int N;
ll score[maxn];
ll dp[maxn][maxn][2];
bool memoize[maxn][maxn][2];

inline ll solve(int i, int j, int turn)
{
    if (i > j)
        return 0;
    ll &ret = dp[i][j][turn];
    bool &mem = memoize[i][j][turn];
    if (mem)
        return ret;
    mem = 1;
    if (turn == 0)
    {
        if (i == j)
        {
            ret = (-score[i] + solve(i + 1, j, 1));
        }
        else
        {
            ll takeFront = -score[i] + solve(i + 1, j, 1);
            ll takeBack = -score[j] + solve(i, j - 1, 1);
            ret = min(takeFront, takeBack);
        }
    }
    else
    {
        if (i == j)
        {
            ret = score[i] + solve(i + 1, j, 0);
        }
        else
        {
            ll takeFront = score[i] + solve(i + 1, j, 0);
            ll takeBack = score[j] + solve(i, j - 1, 0);
            ret = max(takeFront, takeBack);
        }
    }
    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> score[i];
    cout << (solve(1, N, 1));
}
