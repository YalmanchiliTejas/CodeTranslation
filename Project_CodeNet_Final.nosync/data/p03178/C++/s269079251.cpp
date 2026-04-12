#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
vector<int> num;
int dp[20000][200][3];
int g;
string s;
int getsum(int id,int sum,int tight)
{
    if(id==num.size())
    {
        if(sum%g==0)
            return 1;
        else return 0;
    }
    if(dp[id][sum][tight]!=-1&&tight!=0)
        return dp[id][sum][tight];
    int res=0;
    int k;
    if(tight==0)
        k=num[id];
    else
        k=9;
    for(int i=0;i<=k;i++)
    {
         int newtight=tight;
        if(tight==0&&i<k)
            newtight=1;
        res=(res+getsum(id+1,(i+sum)%g,newtight))%MOD;
    }
    if(tight!=0)
        dp[id][sum][tight]=res;
    return (res+MOD)%MOD;
}
int solve(string s)
{
    num.clear();
    for(int i=0;i<s.size();i++)
        num.push_back(s[i]-48);
    memset(dp,-1,sizeof(dp));
    return getsum(0,0,0);
}
void nhap()
{
    cin>>s;
    cin>>g;
    cout<<((solve(s)-1)+MOD)%MOD<<'\n';
}
 main()
{
    nhap();
}
