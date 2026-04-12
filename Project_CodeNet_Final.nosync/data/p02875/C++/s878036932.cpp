#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=10000005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;
 
ll p[maxn],inv[maxn];
//inv[0]=inv[1]=1;
//inv[i]=1LL*(Mod-Mod/i)*inv[Mod%i]%Mod;
//S(n,m)=S(n,m−1)+C(​​n m​​),S(n,m)=2S(n−1,m)−C(​​n−1 m​​)
ll ksm(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res%Mod;
}
 
ll C(int n,int m)
{
    return p[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main()
{
    sync;
    int n;
    cin>>n;
    p[0]=inv[0]=1;
    for(int i=1;i<=maxn-2;i++)
    {
        p[i]=p[i-1]*i%Mod;
//        inv[i]=ksm(p[i],Mod-2);
    }
    inv[maxn-2]=ksm(p[maxn-2],Mod-2);     //阶乘的逆元
    for(int i=maxn-3;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
    ll ans=0;
    for(int i=n/2+1;i<=n;i++)
        ans=(ans+1ll*C(n,i)*ksm(2,n-i)%Mod)%Mod;
    ans=(ksm(3,n)-ans*2%Mod+Mod)%Mod;
    cout<<ans<<endl;
    
    return 0;
}
