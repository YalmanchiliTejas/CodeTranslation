#include <bits/stdc++.h>
#define mn(a, b) (a < b ? a : b)
#define mx(a, b) (a > b ? a : b)
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define base 331

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int const MAXn = 3e3 + 2;

ll dp[MAXn][MAXn];
ll arr[MAXn];
int part;

int main(){

    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    part = n % 2;
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        dp[i][i] = arr[i] * (part ? 1 : -1);
        for(int j = i + 1; j <= n; j++)
            dp[i][j] = (1e15) * (((j - i + 1) % 2 == part) ? -1 : 1);
    }
    for(int d = 1; d < n; d++){
        for(int i = 1; i + d - 1 <= n; i++){
            int j = i + d - 1;
            if((j - i + 1) % 2 == part){
                dp[i][j + 1] = mn(dp[i][j + 1], dp[i][j] - arr[j + 1]);
                dp[i - 1][j] = mn(dp[i - 1][j], dp[i][j] - arr[i - 1]);
            }
            else{
                dp[i][j + 1] = mx(dp[i][j + 1], dp[i][j] + arr[j + 1]);
                dp[i - 1][j] = mx(dp[i - 1][j], dp[i][j] + arr[i - 1]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
/**
3
4 2 9
*/
