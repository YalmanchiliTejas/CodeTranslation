#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         -92233726854775807ll
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N 200005
ll l[N],r[N],arr[N],n,m;
vi a(N),seg(4*N),lazy(4*N),in[N],out[N];
void push(ll n)
{
    seg[2*n]+=lazy[n];
    seg[2*n+1]+=lazy[n];
    lazy[2*n+1]+=lazy[n];
    lazy[2*n]+=lazy[n];
    lazy[n]=0;
}
void update(ll n,ll l,ll r,ll low,ll high,ll val)
{
    if(l>high||low>r)
        return;
    if(low<=l&&r<=high)
    {
        seg[n]+=val;
        lazy[n]+=val;
        return;
    }
    push(n);
    ll mid=(l+r)>>1;
    update(2*n,l,mid,low,high,val);
    update(2*n+1,mid+1,r,low,high,val);
    seg[n]=max(seg[2*n],seg[2*n+1]);
}
ll query(ll n,ll l,ll r,ll low,ll high)
{
    if(l>high||low>r)
        return INF;
    if(low<=l&&r<=high)
    {
        return seg[n];
    }
    push(n);
    ll mid=(l+r)>>1;
    return max(query(2*n,l,mid,low,high),query(2*n+1,mid+1,r,low,high));
    
}
void solve()
{
    cin>>n>>m;
    rep(i,0,m)
    {
        cin>>l[i]>>r[i]>>arr[i];
        in[l[i]].pb(i);
        out[r[i]].pb(i);
    }
    ll ans=0;
    ll k=0,j=0;
    rep(i,1,n+1)
    {
        for(auto u:in[i])
            update(1,1,n,1,i,arr[u]);
        ll cur=query(1,1,n,1,i);
        for(auto u:out[i])
        {
            update(1,1,n,1,l[u],-arr[u]);
        }
        update(1,1,n,i+1,i+1,cur);
        ans=max(ans,cur);
    }
    cout<<ans<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    time
    return 0;
}