#include<bits/stdc++.h>
#define ll long long
#define debug(x) {cerr<<#x<<" = "<<(x)<<endl;}
#define M(x) memset(x,0,sizeof(x))
#define dalao main
#define MOD 1000000007
using namespace std;
inline ll ksc(ll x,ll y,ll p)
{//计算x乘y的积，对p取模
    ll res=0;//加法初始化
    while(y){
        if(y&1)res=(res+x)%p;//模仿二进制
        x=(x<<1)%p; y>>=1;//将x不断乘2达到二进制
    }return res;
};
ll a[200005],pro=0,qzh[200005];
int dalao()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    qzh[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qzh[i] = (qzh[i-1]+a[i]) % MOD;
    }
    for(int i=n;i>=2;i--)
    {
        ll temp = ksc(a[i],qzh[i-1],MOD);
        pro = (pro+temp) % MOD;
    }
    cout<<pro%MOD;
    return 0;
}
