#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
vector<int> num;
string a;
int dp[10005][180][3],k;
int cal(int pos,int du,int f)
{
    if(pos==num.size())
    {
        if(du==0)
            return 1;
        return 0;
    }
    if(dp[pos][du][f]!=-1)
        return dp[pos][du][f]%MOD;
    int res=0,Limit;
    if(f==0)
        Limit=num[pos];
    else
        Limit=9;
    for(int i=0; i<=Limit; i++)
    {
        int nf=f;
        int temp=(du+i)%k;
        if(f==0&&i<Limit)
            nf=1;
        res+=cal(pos+1,temp,nf);
    }
    dp[pos][du][f]=res%MOD;
    return res;
}
int chuyen(string x)
{
    num.clear();
    for(int i=0; i<x.size(); i++)
        num.push_back(x[i]-'0');
    memset(dp,-1,sizeof(dp));
    int res=cal(0,0,0);
    return res;
}
main()
{
    cin>>a;
    cin>>k;
    int temp1=chuyen(a);
    cout<<(temp1-1+MOD)%MOD<<endl;

}
