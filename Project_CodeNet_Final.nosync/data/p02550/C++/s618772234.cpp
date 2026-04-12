#include <bits/stdc++.h>
using namespace std;

#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
//#define ld long double
#define mod 998244353
#define inf 100000000000010
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF LONG_MAX
#define PI 3.1415926535897932384626
#define mpp make_pair
#define fi first
#define se second
#define pb push_back
#define rep(x,j,n)for(int x=j;x<n;x++)
#define repr(x,n,j)for(ll x=n;x>j;x--)
#define all(x) (x).begin(), (x).end()

typedef vector<pair<ll,ll>> vpi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pi;
typedef long double ld;
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




ll builtin_popcount(ll x)
{
    ll cnt = 0;
    for(ll i=60;i>=0;i--)
    {
        if((1LL<<i)&x)cnt++;
    }
    return cnt;
}

ll addmod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    return (a+b)%mod;
}
ll mulmod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll submod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    a-=b;
    if(a<0)a+=mod;
    return a%mod;
}
struct CustomCompare
{
    bool operator()(ll a,ll b)
    {
        return a>b;
    }
};
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

const int mxn = 2e5 + 10;
ll tree[mxn];

void update(ll i,ll val)
{
    while(i<mxn)
    {
        tree[i]=addmod(tree[i],val);
        i+=i&-i;
    }
}
ll query(ll i)
{
    ll ans = 0;
    while(i>0)
    {
        ans = addmod(tree[i],ans);
        i-=i&-i;
    }
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);

ll n,x,m; cin>>n>>x>>m;
vi arr(m);
arr[x] = 1;

vi pref(m+1);
pref[1] = x;
ll pos ;
ll res = n-1,ans;
for(ll i=2;res;i++,res--)
{
    ll val = (x*x)%m;
    if(arr[val])
    {
        pos = arr[val],ans = i-1;
        break;
    }
    arr[val] = i;
    pref[i]=pref[i-1]+val;
    x = val;
    //cout<<x<<" ";
}
//cout<<pos<<endl;
if(res==0)cout<<pref[n]<<endl;
else
{
    ll sum = pref[ans] - pref[pos-1] ;
    ll len = ans-pos+1;
    //cout<<pos<<endl;
    n-=(pos-1);
    ll i = n/len , j = n%len;

    cout<<sum*i + pref[pos-1] + (pref[pos-1+j]-pref[pos-1]) <<endl;
}
return 0;
}
/*
4
1
1 2 1

*/
