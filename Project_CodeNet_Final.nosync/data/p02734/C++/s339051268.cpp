///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=998244353;
const int M=3123;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

int n,s;
int a[M+3];
int d[M+3];
int dp[M+3][M+2];
inline void yo(int &x)
{
    if(x<0)x+=mod;
    x=x%mod;
}
int solve(int pos,int sum)
{
    if(sum<0)return 0;
    int &ret=dp[pos][sum];
    if(ret!=(-1))return ret;
    ret=0;
    if(sum==0)
    {
         ret=n-(pos-1)+1;
        return ret;
    }
    if(pos>n)
    {
        return ret;
    }
    ret=solve(pos+1,sum-a[pos]);yo(ret);
    ret=ret+solve(pos+1,sum);yo(ret);
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>n>>s;
    f(i,1,n)cin>>a[i];
    int ses=0;
    for(int i=n;i>=1;i--)
    {
        d[i]=d[i+1]+solve(i+1,s-a[i]);
        ses=ses+d[i];
        yo(ses);
    }
    cout<<ses<<endl;
    return 0;

}











