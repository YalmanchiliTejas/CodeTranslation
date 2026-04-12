#include<bits/stdc++.h>
#define oo 1000000007
using namespace std;
long long b,ans,k;
string a;
long long dp[10005][105][2];
vector<long long>num;
long long solve(long long idx, long long cnt, bool tight)
{
    if(idx==-1)
        return (cnt%k==0);
    if(dp[idx][cnt][tight]!=-1 && !tight)
    return dp[idx][cnt][tight];
    long long limit=(tight)?num[idx]:9;
    long long res=0;
    for(int i=0;i<=limit;i++)
    {
        long long newtight=(num[idx]==i)?tight:0;
        res=res+solve(idx-1,(cnt+i)%k,newtight);
    }
        dp[idx][cnt][tight]=res%oo;
        return res%oo;
}
long long khoitao(string a)
{
     memset(dp,-1,sizeof(dp));
     num.clear();
     for(int i=a.size()-1;i>=0;i--)
        num.push_back(a[i]-'0');
     return solve(num.size()-1,0,1);
}
main()
{
    cin>>a>>k;
    cout<<(khoitao(a)-1+oo)%oo;
}
