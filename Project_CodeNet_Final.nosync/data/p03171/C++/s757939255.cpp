#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1000000007

int N;
ll dp[3100][3100];
int main()
{
    cin >> N;
    ll a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }
    for (int leng = 1; leng <= N; leng++)
    {
        for (int i = 0; i + leng <= N; i++)
        {
            int j = i + leng;
            if ((N - leng) % 2 == 0)
            {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }
    cout << dp[0][N] << endl;
}
