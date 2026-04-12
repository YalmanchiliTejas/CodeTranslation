#include <bits/stdc++.h>
using namespace std;

#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define mod 1000000007
#define inf 100000000000010
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF LONG_MAX
#define PI 3.1415926535897932384626
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define rep(x,j,n)for(int x=j;x<n;x++)
#define all(x) (x).begin(), (x).end()

typedef vector<pair<ll,ll>> vpi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pi;

bool isprime(ll n)
{
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0||n%3==0)return false;
    for(ll i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)return false;
    }
    return true;
}

ll modexp(ll a,ll b,ll m)
{
    ll r=1;
    a=a%m;
    while(b>0)
    {
        if(b&1)r=(r*a)%m;
        b = b>>1;
        a=(a*a)%m;
    }
    return r%m;
}

struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs < rhs;
    }
};


ll builtin_popcount(ll x)
{
    ll cnt = 0;
    for(ll i=60;i>=0;i--)
    {
        if((1LL<<i)&x)cnt++;
    }
    return cnt;
}

ll addmod(ll a,ll b,ll r)
{
    a%=r;
    b%=r;
    return (a+b)%r;
}
ll mulmod(ll a,ll b,ll r)
{
    a%=r;
    b%=r;
    return (a*b)%r;
}
/*
const int mxn = 5*(1e6) +10;
vi spf(mxn);
void sieve()
{
    for(ll i =0;i<mxn;i++)spf[i]  = i;
    for(ll i=2;i<mxn;i+=2)spf[i] = 2;
    for(ll i = 3;i*i<mxn;i++)
    {
        if(spf[i]==i)
        {
            for(ll j = i*i;j<mxn;j+=i)
            {
                if(spf[j]==j)spf[j] = i;
            }
        }
    }
}
*/


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
ll sum = 0,ans =0;
ll n; cin>>n;
vi arr(n);
rep(i,0,n)cin>>arr[i],sum+=arr[i];
rep(i,0,n)
{
    sum-=arr[i];
    ans=addmod(ans,mulmod(sum,arr[i],mod),mod);

}
cout<<ans<<"\n";
return 0;
}
/*
1
4
1 2
2 3
3 4
2
2 2
*/
