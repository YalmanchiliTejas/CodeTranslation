#pragma gcc optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int d,a,b,i2,pos,dp[102],res,tmp[102];
char k[10002];
int main()
{
    scanf("%s",&k);
    for(; k[pos]!=0; ++pos) a+=k[pos]-'0';
    scanf("%d",&d);
    dp[0]=1;
    a%=d;
    if(a==0) ++res;
    while(--pos>=0){
        if(k[pos]!='0'){
            b=k[pos]-'0';
            a-=b;
            while(a<0) a+=d;
            if(a) i2=d-a; else i2=0;
            for(int i=0; i<b; ++i){
                res+=dp[i2--];
                if(i2<0) i2+=d;
                if(res>=MOD) res-=MOD;
            }
        }
        tmp[0]=0;
        i2=d-1;
        for(int i=0; i<9; ++i){
            tmp[0]+=dp[i2--];
            if(i2<0) i2+=d;
            if(tmp[0]>=MOD) tmp[0]-=MOD;
        }
        for(int i=1; i<d; ++i){
           tmp[i]=tmp[i-1]+dp[i-1]-dp[++i2%d];
           if(tmp[i]>=MOD) tmp[i]-=MOD;
           else if(tmp[i]<0) tmp[i]+=MOD;
        }
        for(int i=0; i<d; ++i){
           dp[i]=dp[i]+tmp[i];
           if(dp[i]>=MOD) dp[i]-=MOD;
        }
    }
    if(--res<0) res+=MOD;
    printf("%d",res);
    return 0;
}