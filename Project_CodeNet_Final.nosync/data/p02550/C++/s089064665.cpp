/*input
1000 2 16
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
typedef long long int ll;
#define ld double
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
const ll maxn=2e5+5;
const ll maxlg=__lg(maxn)+2;
const ll INF64=4e18;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
const ld PI=3.14159265358979323846;
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define MP make_pair
ll mult(ll a,ll b){
    return (a*b)%MOD;
}
ll mypow(ll a,ll b){
    ll res=1LL;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}
ll n,x,m;
bool vis[maxn];
ll nxt(ll x){
    return (x*x)%m;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>x>>m;
    ll ans=0;
    vector<int> v;
    v.pb(x);
    vis[x]=1;
    ans+=x;
    x=nxt(x);
    --n;
    while(n>0 and !vis[x]){
        //cout<<x<<'\n';
        ans+=x;
        vis[x]=1;
        v.pb(x);
        x=nxt(x);
        --n;
    }
    if(n==0){
        cout<<ans;
        return 0;
    }
    REP(i,sz(v)){
        if(v[i]==x){
            ll cyc=0;
            for(int j=i;j<sz(v);j++) cyc+=v[j];
            ans+=(n/(sz(v)-i))*cyc;
            n%=(sz(v)-i);
            REP(j,n){
                ans+=v[i+j];
            }
            break;
        }
    }
    cout<<ans;
}  
