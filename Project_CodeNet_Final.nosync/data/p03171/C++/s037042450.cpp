#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

const ll N = 3e3 + 5, MOD = 1e15 + 7;
const double C = 1;

ll n;
ll a[N];
ll dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 0; i <= n + 1; i++)
        for (int j = i; j <= n + 1; j++)
            dp[i][j] = - MOD;
    for (int l = 0; l < n; l++)
        for (int i = 1; i + l <= n; i++)
            dp[i][i + l] = max (a[i] - dp[i + 1][i + l], a[i + l] - dp[i][i + l - 1]);
    cout<<dp[1][n]<<endl;
    return 0;
}
