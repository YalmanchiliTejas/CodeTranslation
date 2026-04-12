#include <bits/stdc++.h>
using namespace std;

#define MAXN 3005

long long dp[MAXN][MAXN];
long long as [MAXN];

long long calc(int inicio, int fin, int p){
    if(dp[inicio][fin]!=-1){
        return dp[inicio][fin];
    }
    if(p==0){
        return dp[inicio][fin]=max(as[inicio]+calc(inicio+1,fin,1),as[fin]+calc(inicio,fin-1,1));
    }
    return dp[inicio][fin]=min(calc(inicio+1,fin,0),calc(inicio,fin-1,0));
}

int main(){
    int n;
    long long suma =0,X,rta;
    scanf("%d", &n);
    for(int i =0; i<MAXN; i++){
        for(int j =0; j<MAXN; j++){
            dp[i][j] =-1;
        }
    }
    for(int i=0; i<n; i++){
        scanf("%lld", &as[i]);
        suma+=as[i];
        if(n%2==1){
            dp[i][i]  = as[i];
        }
        else{
            dp[i][i] = 0;
        }
    }
    X = calc(0,n-1,0);
    rta = 2*X-suma;
    printf("%lld\n",rta );
}