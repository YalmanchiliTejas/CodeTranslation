#include <bits/stdc++.h>

using namespace std;
#define sint(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sll(a) scanf("%lld",&a)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define mem(a,i) memset(a,i,sizeof(a))
#define pb push_back
#define int long long
#define ll long long
#define lson node<<1
#define rson (node<<1)+1
#define endl "\n"

const int maxn=2e6+10;
const ll mod=1e9+7;
const double pi=acos(-1);

ll qpow(ll a,ll n)
{
    ll b=1;
    while(n)
    {
        if(n&1)
            b=b*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return b;
}
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
//int prime[maxn],s,v[maxn];
//void prime_init()
//{
//    for(int i=2; i<=maxn; i++)
//    {
//        if(!v[i])
//        {
//            prime[s++]=i;
//            for(int j=1; j*i<=maxn; j++)
//                v[i*j]=1;
//        }
//    }
//}

signed main()
{
    int n;
    cin>>n;
    if(n>=30)
        cout<<"Yes";
    else 
        cout<<"No";
    return 0;
}
