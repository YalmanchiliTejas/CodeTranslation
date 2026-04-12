#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4005;
typedef pair<int, int>par;
const ll mod = 998244353;

ll dp[maxn][maxn][2];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef acm
    freopen("a.in", "r",stdin);
    #endif // acm

    int n, s;
    cin >> n >> s;

    int a;
    for( int i = 1; i <= n; i++ ){
        cin >> a;
        for( int j = 1; j <= s; j++ ){
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1])%mod;
            if( j >= a )
                dp[i][j][1] = (dp[i-1][j-a][1] + dp[i-1][j-a][0])%mod;
        }
        dp[i][a][1] = (dp[i][a][1] + i)%mod;
    }

    ll sol = 0;
    for( int i = 1; i <= n; i++ )
        sol = (sol + (dp[i][s][1] * (n-i+1))%mod)%mod;

    cout << sol << "\n";
    return 0;
}
