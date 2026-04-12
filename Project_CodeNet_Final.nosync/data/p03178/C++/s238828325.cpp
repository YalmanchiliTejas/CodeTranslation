#include <bits/stdc++.h>
#define prt_cs                  printf("Case %lld: ",cs)
#define sqr(x)                  (x)*(x)
#define ms(a,b)                 memset(a, b, sizeof(a))
#define db                      double
#define ll                      long long int
#define MOD                     1000000007
#define PI                      2*acos(0.0)
#define pii                     pair< int, int >
#define READ                    freopen("in.txt","r",stdin)
#define WRITE                   freopen("out.txt","w",stdout)
#define gcd(a, b)               __gcd(a, b)
#define lcm(a, b)               (((a)*(b))/gcd(a,b))
#define MAX                     10005

using namespace std;

string A;

int d;
ll dp[MAX][2][101][2];

ll solve(int idx,string A,int lim,int sum,int zero)
{
    if(idx==A.size())
    {
        if(sum%d==0 && zero==0)return 1;
//        cerr<<">> "<<sum<<endl;
        return 0;
    }
    if(dp[idx][lim][sum][zero]!=-1)return dp[idx][lim][sum][zero];
    int ans=0,num=9;
    if(lim)
    {
        num=A[idx]-'0';
    }
    for(int i=0;i<=num;i++)
    {
        int z=0;
        if(zero==1 && i==0)z=1;
        ans+=solve(idx+1,A,lim&&(i==num),(sum+i)%d,z);
        if(ans>=MOD)ans%=MOD;
    }
    return dp[idx][lim][sum][zero]=ans%MOD;
}

int main()
{
//    READ;
//    WRITE;
        cin>>A>>d;
        ms(dp,-1);
        ll ans=solve(0,A,1,0,1);
        printf("%lld\n",ans);
    return 0;
}
