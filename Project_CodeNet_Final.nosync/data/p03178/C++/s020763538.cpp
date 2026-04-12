#include<bits/stdc++.h>
using namespace std;
string K;
int D;
int mod=1e9+7;
vector<vector<vector<int>>>dp;
int f(int i,long long sum,bool check)
{
    if(i==K.size())
    {
        if(sum==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][sum][check]!=-1)
        return dp[i][sum][check];
    int lmt=9;
    if(check)
    {
        lmt=K[i]-'0';
    }
    long long ans=0;
    for(int d=0;d<=lmt;d++)
    {
        if(check&&(d==lmt))
            ans=(ans+f(i+1,(sum+d)%D,true))%mod;
        else ans=(ans+f(i+1,(sum+d)%D,false))%mod;
    }
    return dp[i][sum][check]=ans;
}

int main(){
    cin>>K;
    cin>>D;
    dp.resize(K.size()+1,vector<vector<int>>(D+1,vector<int>(2,-1)));
    int ans=f(0,0,true);
    ans--;
    if(ans==-1)
        cout<<mod-1;
    else cout<<ans;
}
