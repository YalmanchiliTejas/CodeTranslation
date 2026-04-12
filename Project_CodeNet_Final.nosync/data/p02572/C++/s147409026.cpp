/*************************************************\
           In the name of almighty ALLAH
                 MD.Faysal Hasan
                Comilla Univesity
\*************************************************/

#include<bits/stdc++.h>
using namespace std;

#define     ikarus_101  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef     long long             ll;
typedef     long double           ld;
typedef     unsigned long long    ull;
typedef     vector<ll>            vll;
typedef     pair<ll,ll>           pll;
typedef     vector<pll>           vpl;
typedef     map<ll,ll>            mll;
typedef     multiset<ll>          msl;
typedef     multimap<ll,ll>       Mll;
using pqboro=priority_queue<ll,vll,less<ll>>;
using pqchoto=priority_queue<ll,vll,greater<ll>>;

#define    all(str)       str.begin(),str.end()
#define    sajo(str)      sort(str.begin(),str.end())
#define    rev(str)       reverse(str.begin(),str.end())
#define    usajo(str)     sort(str.rbegin(),str.rend())
#define    vin(a)         for(auto &it : a) cin>>it
#define    vout(a)        for(auto it:a) cout<<it<<' ';cout<<nn
#define    vmax(a)        *max_element(all(a))
#define    vmin(a)        *min_element(all(a))
#define    pb             push_back
#define    eb             emplace_back
#define    mkp(x,y)       make_pair(x,y)
#define    F              first
#define    S              second
#define    yes            cout<<"Yes"<<nn
#define    no             cout<<"No"<<nn
#define    nn             "\n" ///endl
#define    rep(i,n)       for (i=0;i<n;++i )
#define    rep1(i,n)      for (i=1;i<=n;++i )

#define    min3(a,b,c)    min(a,min(b,c))
#define    max3(a,b,c)    max(a,max(b,c))
#define    sqr(x)         ((x)*(x))
#define    pi             2*acos(0.0)
#define    gcd(a,b)       __gcd(a,b)
#define    lcm(a,b)       (a/gcd(a,b))*b
#define    mem(a,b)       memset(a,b,sizeof (a))
#define    dec(x)         cout<<fixed<<setprecision(x)
#define    none(n)         __builtin_popcountll(n)

template < typename T > string toString ( T Number ) { stringstream ss ; ss << Number ; return ss.str() ; }
template < typename T > ll toll ( T str ) { stringstream ss ; ss << str ; ll num ; ss >> num ; return num ; }

const   int  N   =   2e5+7;
const   int  M   =   1e9+7;
const   ll  inf  =   0x7f7f7f7f7f7f7f7f;
const   int dx[] =   {+1,+2,+2,+1,-1,-2,-2,-1};
const   int dy[] =   {-2,-1,+1,+2,+2,+1,-1,-2};

int main() {ikarus_101

    ll n,m,i,j,k,x;



    cin>>n;
    vll v(n);
    vin(v);
    vll s(n+1,0);
    for(i=n-1;i>=0;i--)
        s[i] = (v[i]+s[i+1])%M;
    ll tot = 0;
    for(i=0;i<n-1;i++)
    {
        x = (v[i]*s[i+1])%M;
        tot+=x%M;
    }
    cout << tot%M << nn;








    return 0;
}
