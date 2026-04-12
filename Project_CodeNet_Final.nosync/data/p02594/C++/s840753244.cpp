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
signed main()
{
    fastio();   
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll X;
        cin>>X;
        if(X>=30){
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
}