#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
const int maxn = 2e5+10;
long long dp[2][maxn];
// dp[0] at least, dp[1] at most
long long save[maxn];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &save[i]);
    }
    dp[0][1] = 0;
    dp[1][1] = save[1];
    dp[0][2] = max(save[1], save[2]);
    dp[1][2] = dp[0][2];
    for(int i=3; i<=n; i++){
        if(i%2){
            dp[0][i] = max(dp[0][i-2]+save[i], dp[0][i-1]);
            dp[1][i] = dp[1][i-2] + save[i];
        }else{// least == most
            // we may pich the even item
            dp[0][i] = max(dp[1][i-1], dp[0][i-2]+save[i]);
            dp[1][i] = dp[0][i];
        }
    }
    printf("%lld\n", dp[0][n]);
    return 0;
}

