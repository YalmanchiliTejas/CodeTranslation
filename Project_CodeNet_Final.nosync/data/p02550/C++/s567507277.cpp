#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 
using ll = long long int;
#define INF             1e14
#define dd              double
#define MOD             1000000007
#define my_sizeof(type) ((char *)(&type+1)-(char*)(&type)) 
#define nl              cout<<endl
#define fill(a,val)     memset(a,val,sizeof(a))
#define mp              make_pair
#define endl            "\n"
#define pb              push_back
#define ff              first    
#define ss              second
#define SIZE            200005
#define all(v)          v.begin(),v.end()
#define s(ar,n)         sort(ar,ar+n)
#define rs(ar,n)        sort(ar, ar+n, greater<ll>()) 
#define oa(a,n)         for(ll i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n)         for(ll i=0;i<n;i++)cin>>a[i];
#define maxa(ar,N)      *max_element(ar,ar+N)
#define mina(ar,N)      *min_element(ar,ar+N)
#define fastio()        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define printclock      cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order() - 0 indexing
// order_of_key() - number of elements strictly smaller
ll power(ll x, ll y){
    ll res=1;x=x;
    while(y>0){
        if(y&1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
    }
    return res;
}  
ll logtwo(ll n){
    if(n==1)
        return 0;
    return logtwo(n/2)+1;
}
//---------------------------------------GL HF------------------------------------------------------
// -------------------------------------ManavJ07----------------------------------------------------
struct Node{
    ll sum, num, nxt;
};
Node preComp[100005];
signed main()
{
    fastio();   
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll N,X,M;
    cin>>N>>X>>M;
    vector<ll> v;
    map<ll,ll> ma;
    ll cnt=0,cur=X;
    while(cnt!=N){
        v.pb(cur);
        ma[cur]++;
        cur*=cur;cur%=M;
        cnt++;
        if(ma.count(cur))
            break;
    }
    ll idx=0;
    for(ll i=1;i<cnt;i++){
        if(v[i]==cur)
            idx=i;
        v[i]+=v[i-1];
    }
    ll ans=v[cnt-1];
    ll chg=v[cnt-1];
    if(idx)
        chg-=v[idx-1];
    ll num=cnt-idx;
    ans+=((N-cnt)/num)*chg;
    if((N-cnt)%num){
        ans+=v[((N-cnt)%num)+idx-1];
        if(idx)
            ans-=v[idx-1];
    }
    cout<<ans<<endl;
}