//bismillahir rahmanir rahim            //Author:Fayed Anik
 
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
/*
template <typename T>  using ordered_set =
    tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
    rb_tree_tag, tree_order_statistics_node_update>;
*/

#define         ll                          long  long
#define         lf                          double
#define         pb(x)                       push_back(x)
#define         ull                         unsigned long long
#define         sfl(a)                      scanf("%lld",&a)
#define         sf(a)                       scanf("%d",&a)
#define         pf(a)                       printf("%d\n",a)
#define         pfl(a)                      printf("%lld\n",a)
#define         FOR(x,n)                    for(ll x=1;x<=n;++x)
#define         pii                         pair< ll , ll >
#define         mp(a,b)                     make_pair(a,b)
#define         mod                         1000000007
#define         INF                         2e18
#define         f1                          first
#define         f2                          second
#define         all(v)                      v.begin(),v.end()
#define         PI                          acos(-1)
#define         printminusone               printf("-1\n")
#define         bug                         printf("bug")
#define         FILEIN                      freopen("in.txt","r",stdin)
#define         FILEOUT                     freopen("out.txt","w",stdout)
 
//ll SET(ll mask,ll pos){ return mask = (mask | (1ll<<pos)); }
//ll RESET(ll mask,ll pos){ return mask = mask & ~(1ll<<pos); }
//bool CHECK(ll mask,ll pos) { return (bool) (mask & (1ll<<pos)); }
//priority_queue <ll, vector<ll>, greater<ll> > pq;

#define lim 100005
ll a[lim],b[lim];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    sfl(n);
    FOR(i,n){
        sfl(a[i]);
    }
    for(ll i=0;i<=n;i++){
        if(i==0){
            b[i]=-INF;
        }
        else{
            b[i]=INF;
        }
    }
    ll val,pos;
    for(ll i=n;i>=1;i--){
        val = a[i];
        pos = upper_bound(b,b+n+1,val)-b;
        b[pos]=val;
    }
    for(ll i=n;i>=1;i--){
        if(b[i]!=INF){
            pfl(i);
            return 0;
        }
    }
}