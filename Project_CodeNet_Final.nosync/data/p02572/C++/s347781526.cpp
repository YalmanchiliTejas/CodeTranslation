//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//find_by_order(k)  returns iterator to kth element starting from 0;
//order_of_key(k) returns count of elements strictly smaller than k;
//erase,insert same as normal set

//#define      ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define        fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define        f first
#define        s second
#define        pb push_back
#define        eb emplace_back
#define        mp  make_pair
#define        forn(i,n) for(int i=0;i<n;++i)
#define        show(b) for(auto const&x: b) cout<<x<<" "
#define        sshow(b) for(auto x:b) cout<<x<<" "
#define        fix(b,val)   memset(b,val,sizeof(b))
#define        pill(b,n,v)  fill(b,b+n,v)
#define        itn          int
#define        w(t)     int t;cin>>t;while(t--)
#define        intmax    INT_MAX
#define        intmin    INT_MIN
#define        nl        "\n"
#define        prt(val)  cout<<val<<"\n"
#define        all(v)    v.begin(),v.end()
#define        vt        vector
#define        trace1(x)                cerr<<#x<<": "<<x<<endl
#define        trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define        trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define        trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define        trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define        trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef       long long int ll;
typedef       long double LD;
typedef       unsigned long long int LL;
typedef       pair<int,int> pii;
typedef       pair<long long int,int> pli;
typedef       pair<int,long long int> pil;
typedef       pair<long long int,long long int> pll;
const int N=1e5+5;
const int mod=1e9+7;
//mt19937 rnd(time(NULL));

/*------Global--------*/

/*-----Functions------*/
template<typename T>
void show2d(const vector<vector<T>>& adj)
{
    for(auto x:adj)
    {
        for(auto y:x)
        { 
           cout<<y<<" ";
        }
    cout<<"\n";
    }
}

ll modexp(ll a,ll b,ll mod)
{
    ll x=1;
    while(b)
    {
        if(b&1)
        x = ((x%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        b = b / 2;
    }
    return x;
}

bool ispalindrome(ll n)
{
    ll rev=0,n1=n;
    while(n1>0)
    {
       rev=rev*10+n1%10;
       n1/=10;
    }
    return (n==rev);
}

void rf()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int32_t main()
{
    fast;
    //rf();
    int n;
    cin>>n;
    ll a[n];
    forn(i,n)
    cin>>a[i];
    ll p[n];
    p[n-1] = a[n-1];
    for(int i=n-2; i>=0; --i)
        p[i] = (a[i]%mod + p[i+1]%mod) % mod;
    ll sum = 0;
    for(int i=0; i<n-1; ++i)
    {
        sum = ((sum%mod) + ((a[i]%mod * p[i+1]%mod)%mod)%mod) %mod;
        trace1(sum);
    }
    cout<<sum<<nl;
}