#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod=1e9+7;

string x;
int dp[10005][101][2];
int d;

int dfs(int i,int sum, bool smaller){
    if(i==(int)x.size()){
        return (sum%d == 0);
    }
    if(dp[i][sum][smaller] != -1){
        return dp[i][sum][smaller];
    }

    int lower_limit, upper_limit;
    if(i==0) lower_limit=1;
    else lower_limit=0;
    int t=x[i]-'0';
    if(smaller) upper_limit=9;
    else upper_limit=t;


    int ans=0;
    for(int digit=0; digit<=upper_limit; ++digit){
        int t=x[i]-'0';
        bool f=smaller;
        if(digit < t){
            f|=1;
        }
        ans=(ans+dfs(i+1,(sum+digit)%d,f))%mod;
    }
    return dp[i][sum][smaller]=ans;
}

int main() {
    IOS
    cin>>x>>d;
    memset(dp, -1, sizeof(dp));
    cout<<(dfs(0,0,0)-1+mod)%mod;
    return 0;
}