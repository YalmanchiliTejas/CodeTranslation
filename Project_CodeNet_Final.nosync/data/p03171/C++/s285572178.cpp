#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll tab [3007];
ll dp [3][3007][3007];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&tab[i]);
        dp[0][i][i] = -tab[i];
        dp[1][i][i] = tab[i];
    }

    for(int d = 1; d <= n; d++){
        for(int i = 1; i <= n - d; i++){
            dp[0][i][i + d] = min(dp[1][i][i + d - 1] - tab[i + d], dp[1][i + 1][i + d] - tab[i]);
            dp[1][i][i + d] = max(tab[i + d] + dp[0][i][i + d - 1], tab[i] + dp[0][i + 1][i + d]);
        }
    }
    printf("%lld\n",dp[1][1][n]);
    return 0;
}
