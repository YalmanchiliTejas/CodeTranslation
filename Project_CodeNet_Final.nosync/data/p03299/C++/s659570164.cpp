/*     !ya khoda!     */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define ld long double

#define pp push
#define po pop()
#define pb push_back
#define pf push_front
#define pob pop_back()
#define pof pop_front()
#define I insert
#define E erase

#define F first
#define S second

#define mkp make_pair
#define pll pair<ll,ll>
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define all(a) a.begin(),a.end()

#define coutghat(x)      cout<<tolower(x);
#define coutashar(x,d)   cout<<fixed<<setprecision(x)<<(ld)d
#define IOS ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)
//#define poow(a,b,M)   b?(poow((a*a)%M,b/2)%M * (b&1?a))%M:1 ;
/*==========================================================================*/
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll poow(ll x,ll n,ll Mod=1e9+7) { return (n==0?1:poow(x*x%Mod,n/2)*(n&1?x:1)%Mod); }
//#pragma optimize O3
// 107,109, 211,223, 307, 401,409, 503,509, 601,607, 701,709, 809, 907, 1009
/*==========================================================================*/
const int N=1e2+100 , M=1e6+10  , SQ=550 , LG=21 , base=2;
const int mod=1e9+7 , MOD=1e9+9;
const ll  INF=1e9   , inf=1e18 , super_inf=~0ull/4;
ll n,a[N];
/*==========================================================================*/
pll solve(ll l , ll r)
{   ll res=0,t=1,w=1,d=0,e=INF,z=l;
    if(l>r)   return mkp(1,1);
    for(int i=l;i<=r;i++)   e=min(e,a[i]);

    for(int i=l;i<=r;i++)
    {   a[i]-=e;
        if(a[i]==0)
        {   pll f=solve(z,i-1);
            t*=f.S  ,  t%=mod;
            w*=f.F  ,  w%=mod;
            d++     ,  z=i+1;
        }
    }

    pll f=solve(z , r);

    t*=f.S  ,  t%=mod;
    w*=f.F  ,  w%=mod;
    res+=(poow(2,d)*w)%mod   ,   res%=mod;
    res+=(poow(2,e)*t)%mod   ,   res%=mod;
    res+=(t*((poow(2,e)-2+mod)%mod))%mod;
    res%=mod;

    return mkp(res,(poow(2,e)*t)%mod);
}
/*==========================================================================*/
int main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)   cin>>a[i];

    pll res=solve(1,n);

    cout<<(res.F-res.S+mod)%mod;
    return 0;
}
