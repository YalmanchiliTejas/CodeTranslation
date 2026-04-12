#include <bits/stdc++.h>
using namespace std;

#define MAXN 3005

long long dp[MAXN][MAXN][2];
long long as [MAXN];

long long calc(int inicio, int fin, int p){
    if(dp[inicio][fin][p]!=-1){
        return dp[inicio][fin][p];
    }
    if(p==0){
        return dp[inicio][fin][p]=max(as[inicio]+calc(inicio+1,fin,1),as[fin]+calc(inicio,fin-1,1));
    }
    return dp[inicio][fin][p]=min(calc(inicio+1,fin,0),calc(inicio,fin-1,0));
}

int main(){
    int n;
    long long suma =0,X,rta;
    scanf("%d", &n);
    for(int i =0; i<MAXN; i++){
        for(int j =0; j<MAXN; j++){
            dp[i][j][0] = dp[i][j][1]=-1;
        }
    }
    for(int i=0; i<n; i++){
        scanf("%lld", &as[i]);
        suma+=as[i];
        dp[i][i][0]  = as[i];
        dp[i][i][1] = 0;
    }
    X = calc(0,n-1,0);
    rta = 2*X-suma;
    printf("%lld\n",rta );
}