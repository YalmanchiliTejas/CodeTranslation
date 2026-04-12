#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N 3002
int N;
ll A[MAX_N];
ll dp[MAX_N][MAX_N];

ll f(int i, int j){
    if(i > j){
        return 0;
    }
    if(i == j){
        return A[i];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = max(
            A[i] - f(i+1,j),
            A[j] - f(i,j-1)
            );
}

int main() {
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%lld",A+i);
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            dp[i][j] = -1;
        }
    }
    printf("%lld",f(1,N));
}