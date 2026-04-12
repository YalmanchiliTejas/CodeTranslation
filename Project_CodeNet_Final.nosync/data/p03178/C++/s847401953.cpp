#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
char a[10010];
int dp[10010][2][110];
int n,len;
int play(int now,int state,int num){
    if(dp[now][state][num]!=-1) return dp[now][state][num];
    if(now == len)    return (num == 0);
    int sum = 0;
    int ma = (state)?a[now]-'0':9;
    for(int i=0;i<=ma;i++)
        sum = (sum + play(now+1,state && (i==ma),(num+i)%n ) )%MOD;
    return dp[now][state][num] = sum;
}
int main(){
    scanf(" %s %d",a,&n);
    len = strlen(a);
    memset(dp,-1,sizeof dp);
    printf("%d\n",(play(0,1,0)-1+MOD)%MOD);
    return 0;
}
