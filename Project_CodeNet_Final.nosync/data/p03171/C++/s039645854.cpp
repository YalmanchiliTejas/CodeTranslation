#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll a[3001], dp[3001][3001], pref[3001];

ll interval(int i, int j)
{
    return pref[j] - pref[i-1];
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", a + i);
        dp[i][i] = a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for (int g = 1; g <= N; g++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (i + g > N) break;
            dp[i][i+g] = max(a[i] + interval(i+1, i+g) - dp[i+1][i+g], a[i+g] + interval(i, i+g-1) - dp[i][i+g-1]);
        }
    }
    printf("%lld\n", 2LL * dp[1][N] - interval(1,N));
    return 0;
}
