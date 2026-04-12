#include <bits/stdc++.h>

using namespace std;
//FILE *fi=freopen("1.txt","r",stdin);
string a;
int m;
long long d[100001][101][2];
const long long mod=1e9+7;
int n;
long long d__p(int step,int sum,int tt)
{
    if(step==n)
    {
        return d[step][sum][tt] = sum==0;
    }
    if(d[step][sum][tt]!=-1)
        return d[step][sum][tt];
    int limit=9;
    if(tt)
    {
        limit=a[step]-'0';
    }
    long long res=0;
    for(int j=0;j<=limit;j++)
    {
        res=res+d__p(step+1,(sum+j)%m,tt && j==limit);
        res%=mod;
    }
    return d[step][sum][tt]=res;
}
int main()
{
    cin>>a;
    cin>>m;
    n=a.length();
    memset(d,-1,sizeof d);
    cout<<(d__p(0,0,1)-1+mod)%mod;
    return 0;
}
