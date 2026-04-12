#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e4 + 5, mod = 1e9 + 7;
typedef long long ll;
ll dp[maxn][2][105];
int k[maxn];
char tmp[maxn];
int main()
{
//    freopen("in", "r", stdin);
    int d;
    scanf("%s", tmp);
    int n = strlen(tmp);
    scanf("%d", &d);
    for(int i = 0; i < n; i++)
        k[i] = tmp[n-i-1] - '0';
    for(int i = 0; i <= 9; i++){
        if(i <= k[0]){
            dp[0][0][i%d] += 1;
        }else{
            dp[0][1][i%d] += 1;
        }
    }
    for(int i = 1; i < n; i++){
        for(int r = 0; r < d; r++){
            for(int x = 0; x < k[i]; x++){
                int q = ((r-x)%d + d) % d;
                dp[i][0][r] =(dp[i][0][r] + dp[i-1][0][q] + dp[i-1][1][q]) % mod;
            }
            int q = ((r-k[i])%d + d) % d;
            dp[i][0][r] = (dp[i][0][r] + dp[i-1][0][q])%mod;
            dp[i][1][r] = (dp[i][1][r] + dp[i-1][1][q])%mod;
            for(int x = k[i] + 1; x <= 9; x++){
                int q = ((r-x)%d + d) % d;
                dp[i][1][r] =(dp[i][1][r] + dp[i-1][0][q] + dp[i-1][1][q]) % mod;

            }
        }
    }
    cout<<(dp[n-1][0][0] + mod - 1) % mod<<endl;
    return 0;
}
