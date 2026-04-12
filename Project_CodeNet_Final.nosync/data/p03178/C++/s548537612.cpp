#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define maxN 100005

inline int add(int x,int y) { x+=y; if(x>=mod) x-=mod; return x; }

int dp[maxN][2][101];
vector<int> v;
int len;

void PUSH(string x)
{
    for(auto u:x) v.push_back(u-'0');
}

int sol(int index,int flag,int sum,int D)
{
    if(index==len)
    {
        if(sum%D==0) return 1;
        else return 0;
    }

    int &r=dp[index][flag][sum];
    if(r!=-1) return r;

    int res=0;
    if(flag) for(int i=0;i<10;i++) res=add(res,sol(index+1,1,(sum+i)%D,D));
    else
    {
        for(int i=0;i<=v[index];i++)
        {
            if(i<v[index]) res=add(res,sol(index+1,1,(sum+i)%D,D));
            else if(i==v[index]) res=add(res,sol(index+1,0,(sum+i)%D,D));
        }
    }

    return r=res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    string s;
    cin>>s;

    PUSH(s);
    len=v.size();

    int d=0;
    cin>>d;

    memset(dp,-1,sizeof(dp));
    int ans=sol(0,0,0,d)-1;
    if(ans<0) ans+=mod;
    cout<<ans%mod<<"\n";
    return 0;
}