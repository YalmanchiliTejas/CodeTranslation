//2020-04-09 16:04:39
//#pragma GCC optimize("-Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//order_of_key(x) : number of items less than x
//find_by_order(x) : iterator to x

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()

const ld pi=3.14159265359;
ll INF=1e18+10;
ll MOD=998244353;
ll mod=1e9+7;

inline ll add(ll a,ll b,ll m){
    if((a+b)>=m)return (a+b)%m;
    return a+b;
}

inline ll mul(ll a,ll b,ll m){
    if((a*b)<m)return a*b;
    return (a*b)%m;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    ll cost1=a*x+b*y;
    ll cost2=0;
    if(x<y)
    {
        cost2=(2*x*c);
        cost2+=((y-x)*b);
    }
    else
    {
        cost2=(2*y*c);
        cost2+=((x-y)*a);
    }
    ll cost3=(max(x,y))*c*2;
    cout<<min(cost1,min(cost2,cost3));
}