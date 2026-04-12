/* ****Ragnar7 _Lawliet_**** */
/* First, solve the problem.Then write the code. */
#include<bits/stdc++.h>
#define ll          long long
#define ld             long double
#define hell        1000000007
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const ll N = 200005;
ll n,q;
vector<ll> a(N),seg(4*N),lazy(4*N);
void build(ll cur,ll st,ll end)
{
    if(st==end)
    {
        seg[cur]=a[st];
        return;
    }
    ll mid=(st+end)>>1;
    build(2*cur,st,mid);
    build(2*cur+1,mid+1,end);
    seg[cur]=max(seg[2*cur],seg[2*cur+1]);                    /* 1-change */
}
void updaterange(ll cur,ll st,ll end,ll l,ll r,ll val)
{
    if(lazy[cur]!=0)                                    /* 2-change */
    {
        seg[cur]+=lazy[cur];                    /* 3-change */
        if(st!=end)
        {
            lazy[2*cur]+=lazy[cur];                        /* 4-change */
            lazy[2*cur+1]+=lazy[cur];                   /* 5-change */
        }
        lazy[cur]=0;                                    /* 6-change */
    }
    if(st>end||st>r||end<l) return;
    if(l<=st&&end<=r)
    {
        seg[cur]+=val;                        /* 7-change */
        if(st!=end)
        {
            lazy[2*cur]+=val;                           /* 8-change */
            lazy[2*cur+1]+=val;                         /* 9-change */
        }
        return;
    }
    ll mid=(st+end)>>1;
    updaterange(2*cur,st,mid,l,r,val);
    updaterange(2*cur+1,mid+1,end,l,r,val);
    seg[cur]=max(seg[2*cur],seg[2*cur+1]);                  /* 10-change */
}
ll query(ll cur,ll st,ll end,ll l,ll r)
{
    if(st>end||st>r||end<l) return LLONG_MIN;
    if(lazy[cur]!=0)
    {
        seg[cur]+=lazy[cur];                /* 11-change */
        if(st!=end)
        {
            lazy[2*cur]+=lazy[cur];                    /* 12-change */
            lazy[2*cur+1]+=lazy[cur];                  /* 13-change */
        }
        lazy[cur]=0;
    }
    if(st>=l&&end<=r) return seg[cur];
    ll mid=(st+end)>>1;
    ll ans1=query(2*cur,st,mid,l,r);
    ll ans2=query(2*cur+1,mid+1,end,l,r);
    return max(ans1,ans2);                                 /* 14-change */
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);
    #endif
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll> > left[n+5] ,right[n+5];
        ll x,y,z;
        for(ll i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            left[x].push_back({x,z});
            right[y].push_back({x,z});
        }
        ll ans = 0;
        for(ll i=1;i<=n+1;i++)
        {
            for(auto j:left[i])
                updaterange(1,1,n,1,j.first,j.second);
            ll curr = query(1,1,n,1,i);
            ans = max(ans,curr);
            for(auto j:right[i])
                updaterange(1,1,n,1,j.first,-1*j.second);
            updaterange(1,1,n,i+1,i+1,curr);
        }
        cout<<ans;
    }

    
    time
    return 0;
}