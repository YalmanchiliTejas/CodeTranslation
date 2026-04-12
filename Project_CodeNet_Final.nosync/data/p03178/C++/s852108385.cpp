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

ll POWER (ll x, ll y, ll mod){
    ll ans = 1, c = x;
    while (y){
        if ((y & 1) == 1)
            ans = ans * c % mod;
        c = c * c % mod;
        y /= 2;
    }
    return ans;
}

const ll N = 1e4 + 6, MOD = 1e9 + 7;
const double C = 1;

string S;
int n;
int D;
ll dp[N][105][2];

int main()
{
    ios::sync_with_stdio(false);
    cin>>S>>D;
    n = (int)S.size();
    S = "#" + S;
    dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < D; j++){
            for (int c = 0; c < 10; c++){
                int x = (j - c + D * 11) % D;
                dp[i][j][0] += dp[i - 1][x][0];
                if (c < S[i] - '0')
                    dp[i][j][0] += dp[i - 1][x][1];
                if (c == S[i] - '0')
                    dp[i][j][1] += dp[i - 1][x][1];
            }
            for (int l = 0; l < 2; l++)
                dp[i][j][l] %= MOD;
        }
    cout<<(dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD<<endl;
    return 0;
}
