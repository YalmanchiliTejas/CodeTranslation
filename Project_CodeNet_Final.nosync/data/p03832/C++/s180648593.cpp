#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pi acos(-1.0)
#define pii pair<int,int>
#define Lson L, mid, ls[rt]
#define Rson mid+1, R, rs[rt]
#define sys system("pause")
#define intxt freopen("in.txt","r",stdin)
const int maxn=1e3+10;
using namespace std;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
inline void umax(int &p,int q){if(p<q)p=q;}
inline void umin(int &p,int q){if(p>q)p=q;}
inline ll read()
{
    ll x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,k,t,a,b,c,d;
ll C[maxn][maxn],dp[2][maxn];
void init()
{
    C[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int main()
{
    int i,j;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    init();
    dp[t][n]=1;
    for(int i=a;i<=b;i++)
    {
        for(int j=0;j<=n;j++)dp[t^1][j]=dp[t][j];
        ll tmp=1;
        for(int j=1;j<=d;j++)
        {
            if(j*i>n)break;
            tmp=tmp*C[i*j][i]%mod*qpow(j,mod-2)%mod;
            if(j<c)continue;
            for(int k=i*j;k<=n;k++)
            {
                dp[t^1][k-i*j]=(dp[t^1][k-i*j]+dp[t][k]*C[k][i*j]%mod*tmp%mod)%mod;
            }
        }
        t^=1;
    }
    printf("%lld\n",dp[t][0]);
    //system("Pause");
    return 0;
}
