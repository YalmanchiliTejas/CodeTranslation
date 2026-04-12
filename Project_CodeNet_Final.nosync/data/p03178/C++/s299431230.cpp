#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

const int mod = 1e9 + 7;

int N, D;
char s[10005];
int dp[10005][105];

int brut()
{
    freopen("1.in", "r", stdin);

    int N, D;
    cin >> N >> D;

    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        int aux = i;
        int sum = 0;
        while(aux)
        {
            sum += aux % 10;
            aux /= 10;
        }
        if(sum % D == 0)    ans++;
    }
    return ans;
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    #endif

    scanf("%s\n", s + 1);
    scanf("%d", &D);
    N = strlen(s + 1);

    if(D == 1)
    {
        int ans = 0;
        for(int i = 1; i <= N; i++)
            ans = (1LL * ans * 10 + s[i] - '0') % mod;
        printf("%d\n", ans);
        exit(0);
    }

    auto addto = [](int &x, int y) { x += y; if(x >= mod) x -= mod; } ;

    dp[0][0] = 1;
    for(int i = 0; i < N; i++)
        for(int c = 0; c < 10; c++)
            for(int j = 0; j < D; j++)
                addto(dp[i + 1][(j + c) % D], dp[i][j]);

    int sum = 0;
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        int cif = s[i] - '0';
        for(int c = 0; c < cif; c++)
        {
            int nowsum = (sum + c) % D;
            addto(ans, dp[N - i][(D - nowsum) % D]);
        }
        sum += cif;
    }
    if(sum % D == 0)    addto(ans, 1);

    ans = (ans - 1 + mod) % mod;

    cout << ans << '\n';

    return 0;
}
