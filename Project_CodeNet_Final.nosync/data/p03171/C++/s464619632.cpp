#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int N; ll s[3002], dp[3002][3002];
int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%lld", &s[i]); dp[i][i] = s[i]; s[i] += s[i-1]; 
    }
    for(int len=1; len < N; len++){
        for(int i=1; i+len<=N; i++){
            int j = i + len;
            dp[i][j] = s[j] - s[i-1] - min(dp[i+1][j], dp[i][j-1]);
        }
    }
    printf("%lld\n", 2*dp[1][N] - s[N]);
}