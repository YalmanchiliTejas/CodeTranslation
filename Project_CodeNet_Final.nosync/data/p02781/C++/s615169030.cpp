#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
using pii = pair<int, int>;
int dp[105][2][5],k,n,val[105];
char s[105];
int solve(int lak, int isless, int n1){
    if(dp[lak][isless][n1] != -1) return dp[lak][isless][n1];
    if(lak == n){
        if(n1 > 1) return 0;
        if(n1 == 0) dp[lak][isless][n1] = 1;
        else if(isless == 1) dp[lak][isless][n1] = 9;
        else dp[lak][isless][n1] = val[lak];
        return dp[lak][isless][n1];
    }
    int &rec = dp[lak][isless][n1];
    rec = 0;
    int ub = (isless == 1) ? 9 : val[lak];
    rec += solve(lak+1, isless || (val[lak] > 0), n1);
    if(n1 == 0) return rec;
    for(int i = 1;i <= ub; i++){
        int x = (isless == 1) ? 1  : (val[lak] > i ? 1 : 0);
        rec += solve(lak+1,x,n1-1);
    }
    return rec;
}
int main(){
    scanf("%s%d",s+1,&k);
    n = strlen(s+1);
    for(int i = 0;i <=n;i++){
        for(int j=0;j<2;j++){
            for(int l =0;l<=k;l++) dp[i][j][l]  =  -1;
        }
    }
    for(int i = 1;i <= n;i++) val[i] = s[i] -'0';
    printf("%d",solve(0,0,k));


}
