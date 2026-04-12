#include <bits/stdc++.h>
#define  ll      long long 
#define  int     ll 
#define  mod     1000000007
#define  pb      push_back
#define  pob     pop_back
#define  f1      first
#define  s2      second
#define  N       100005
#define  K       100005
#define  bol     (int)ceil((say-1)/2.0)
#define  PII     pair<int,int>
#define  PIII    pair<int,PII>
#define  PIIII   pair<PII,PII>
#define  PIIIII  pair<PIII,PII>
#define  PIIIIII pair<PIII,PIII>

using namespace std; 

string s;
int d,n;
int dp[N][102][3];

int dpf(int indis,int sum,int flag){
    sum+=d;
    sum%=d;
    if(indis==n){
        return (sum==0)?1:0;
    }
    if(dp[indis][sum][flag]!=-1)
        return dp[indis][sum][flag];
    int top=0;
    if(!flag){
        for(int i=0;i<(s[indis]-'0');i++){
            top+=dpf(indis+1,(sum+i)%d,1);
            top%=mod;
        }
        top+=dpf(indis+1,(sum+s[indis]-'0')%d,0);
        top%=mod;
    }
    else{
        for(int i=0;i<=9;i++){
            top+=dpf(indis+1,(sum+i)%d,1);
            top%=mod;
        }
    }
    dp[indis][sum][flag]=top;
    return dp[indis][sum][flag];

}



int32_t main(){
    // freopen("a.gir","r",stdin);      
    // freopen("a.cik","w",stdout);
    cin>>s;
    scanf("%lld",&d);
    n=s.size();
    memset(dp,-1,sizeof(dp));

    printf("%lld\n", (dpf(0,0,0)-1+mod)%mod);

}
