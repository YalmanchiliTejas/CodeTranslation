#include<bits/stdc++.h>

#define int long long int
#define mp make_pair
using namespace std;

int n;
vector <int> v(3002);
int dp[3002][3002][2];

int fun(int start , int end , int turn)
{
    if(start >end){
        return 0;
    }
    if(dp[start][end][turn] != -1){
        return dp[start][end][turn];
    }
    if(turn == 0){
        dp[start][end][turn] = max(v[start] + fun(start+1 , end , 1) , v[end] + fun(start , end-1 , 1));
    }
    else{
        dp[start][end][turn] = min(-v[start] + fun(start+1 , end , 0) , -v[end] + fun(start , end-1 , 0));
    }
    return dp[start][end][turn];
}

int32_t main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    for (int i = 0; i < 3002; ++i) {
        for (int j = 0; j < 3002; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = fun(0 , n-1 , 0);
    printf("%lld",ans);
    return 0;
}