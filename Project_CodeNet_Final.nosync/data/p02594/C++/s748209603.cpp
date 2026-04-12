#include<bits/stdc++.h>
using namespace std;
// -----------------<fast IO>------------------
#define IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FLSH             fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x)     cout << fixed << setprecision(x);
// -----------------<TypeDef Start>------------------
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
// -----------------<Constants>------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);

const int INF=1e9;

int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;
ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}
ll lcm(ll a,ll b)
{
    return(a/gcd(a,b)*b);
}
/*ll gcdExtended(ll a,ll b,ll *x,ll *y)
{
    if(a==0)
    {
        *x=0,*y=1;
        return(b);
    }
    ll x1,y1;
    ll gcd=gcdExtended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return(gcd);
}*/
ll power(ll a,ll b,ll p)
{
    ll res=1;
    a%=p;
    while(b>0)
    {
        if(b&1)
        res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return(res);
}
/*ll modInverse(ll a, ll m)
{
    ll x,y;
    ll g = gcdExtended(a, m,&x,&y);
    return((x%m+m)%m);
}*/
/*long combi(int n,int k)
{
    long ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}*/
/*struct cmp{
    bool operator()(const pair<ll,ll>&a,const pair<ll,ll>&b)
    const{
        int lena=a.second-a.first+1;
        int lenb=b.second-b.first+1;
        if(lena==lenb) return a.first<b.first;
        return lena>lenb;
    }
};*/
void solve()
{
    int n;
    cin>>n;
    if(n>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

int main()
{
    IOS
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return(0);
}
