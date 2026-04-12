#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
char a[10005];
int d,len;
ll dp[10005][105][3];

ll solve(int idx,int sum,int pre){

    if(idx == len){
        if(sum == 0) return dp[idx][sum][pre] = 1;
        return dp[idx][sum][pre] = 0;
    }
    if(dp[idx][sum][pre] != -1) return dp[idx][sum][pre];

    ll ret = 0;
    if(idx == 0 || pre == 1){
    for(int i = 0;i <= (a[idx]-'0'); i++){
        if(i == a[idx]-'0')
        ret = (ret % mod + solve(idx+1,(sum + i)%d, 1) % mod) % mod;
        else
        ret = (ret % mod + solve(idx+1,(sum+i)%d,0) % mod) % mod;
        }
    }
    else{
        for(int i=0;i < 10; i++){
        ret = (ret % mod + solve(idx+1,(sum + i)%d, pre) % mod) % mod;
        }
    }
    return dp[idx][sum][pre] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>d;
    len = strlen(a);
    memset(dp,-1,sizeof(dp));
    cout<<(((solve(0,0,0)-1) + mod)%mod)%mod;

    return 0;
}
