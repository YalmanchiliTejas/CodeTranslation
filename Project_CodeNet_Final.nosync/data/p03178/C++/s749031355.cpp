#include<bits/stdc++.h>
#define oo 1000000007
using namespace std;
long long dp[10005][105][2],d;
vector<long long>num;
string s;
long long solve(long long idx, long long sum, long long tight)
{
    if(idx==num.size())
        return(sum%d==0);
    if(dp[idx][sum][tight]!=-1)
        return dp[idx][sum][tight];
    long long k=(tight)?num[idx]:9;
    long long res=0;
    for(int i=0;i<=k;i++)
    {
        long long newtight=(num[idx]==i)?tight:0;
        res=(res+solve(idx+1,(sum+i)%d,newtight))%oo;
    }
    dp[idx][sum][tight]=res;
    return res;
}
long long khoitao(string s)
{
    num.clear();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=s.size()-1;i++)
        num.push_back(s[i]-'0');
    return solve(0,0,1);
}
main()
{
    cin>>s>>d;
    cout<<(khoitao(s)-1+oo)%oo;
}
