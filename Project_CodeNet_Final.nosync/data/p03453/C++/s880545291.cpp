#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

#if !ONLINE_JUDGE
#define debug
#endif

using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define mem(a, b) memset(a, (b), sizeof(a))
#define repd(i,k) for(int i=k;i>=0;i--)
#define rep(i,k) for(int i=0;i<k;i++)
#define repn(i,k1,k2) for(ll i=k1;i<k2;i++)
#define sz(x) (ll)(x).size()
#define ff first
#define ss second

#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ee6 (ll)1000001
#define ee5 (ll)100001

#define trav(a, v) for(auto& a : v)

#define tt ll t;cin>>t; while(t--)
typedef long long int ll;
 
typedef pair<ll, ll> pr;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<pr> vpr;
typedef vector<vpr>vvpr;
typedef vector<vi> vvi;

//*X.find_by_order(2) element at index=2
//X.order_of_key(1) how many elements strictly less than 1

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

#ifdef debug
#define dbg(...) { cerr<<"[ "; dump(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.ff<<","<<x.ss<<")";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
 
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const unordered_map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
} 
 
template <typename Arg1>
void dump(const string name, Arg1&& arg1){
    cerr << name << " : " << arg1 << " ] " << endl;
}
 
template <typename Arg1, typename... Args>
void dump(const string names, Arg1&& arg1, Args&&... args){
    const string name = names.substr(0,names.find(','));
    cerr<<name<<" : "<<arg1<<" | ";
    dump(names.substr(1+(int)name.size()), args...);
}
#else
    #define dbg(args...)
#endif
 
ll powmod(ll x, ll y) 
{ 
    ll res = 1;  
    x = x % MOD;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % MOD; 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;   
    } 
    return res; 
} 
vector<pair<ll,ll> >g[ee5];
ll distp[ee5],distq[ee5];
ll waysp[ee5],waysq[ee5];

ll n,m;
void go(ll s,ll dist[]){
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> >  >pq;
    pq.push(mp(0,s));
    
    rep(i,n)dist[i]=1e16;

    while(!pq.empty()){
        pair<ll,ll> p=pq.top();
        pq.pop();        
        if(p.ff>dist[p.ss])continue;
        dist[p.ss]=p.ff;
        
        for(auto e:g[p.ss]){
            if(dist[p.ss]+e.ss<dist[e.ff]){
                dist[e.ff]=dist[p.ss]+e.ss;
                pq.push(mp(dist[e.ff],e.ff));
            }
        }
    }/*
    rep(i,n)
        cout<<dist[i]<<" "; */    
}

void solve(ll s,ll dist[],ll ways[]){
    vector<pair<ll,ll> >v;
    rep(i,n){
        v.eb(dist[i],i);
    }
    sort(all(v));
    ways[s]=1;
    for(auto e:v){
        
        for(auto nei:g[e.ss]){
            if(dist[nei.ff]+nei.ss==e.ff)
                ways[e.ss]=(ways[e.ss]+ways[nei.ff])%MOD;
        }
    }/*
    rep(i,n)
        cout<<ways[i]<<" ";*/
}


vector<pair<pair<ll,ll>,ll> >edges;
int main()
{
    #if !ONLINE_JUDGE
    //freopen("03.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    ll s,t;cin>>s>>t;
    s--;t--;
    rep(i,m){
        ll u,v,d;cin>>u>>v>>d;
        u--;v--;
        g[u].eb(v,d);
        g[v].eb(u,d);
        edges.pb(mp(mp(u,v),d));
    }
    
    go(s,distp);
    solve(s,distp,waysp);
    
    go(t,distq);
    solve(t,distq,waysq);

    ll ans=0;
    rep(i,n){
        if(distp[i]+distq[i]==distp[t] and distp[i]==distq[i]){
            
            ans=(ans-waysp[i]*waysq[i]%MOD*waysp[i]%MOD*waysq[i]%MOD)%MOD;            
            ans=(ans+MOD)%MOD;
        }
    }
    
    for(auto e:edges){
        ll x=e.ff.ff;
        ll y=e.ff.ss;
        ll road=e.ss;
        if(distp[x]+distq[y]+road==distp[t])
            if(distp[x]+road>distq[y])
                if(distq[y]+road>distp[x]){
                    ans=(ans-waysp[x]*waysq[y]%MOD*waysp[x]%MOD*waysq[y]%MOD)%MOD;
                    ans=(ans+MOD)%MOD;
                }
        swap(x,y);           
        if(distp[x]+distq[y]+road==distp[t])
            if(distp[x]+road>distq[y])
                if(distq[y]+road>distp[x]){
                    ans=(ans-waysp[x]*waysq[y]%MOD*waysp[x]%MOD*waysq[y]%MOD)%MOD;
                    ans=(ans+MOD)%MOD;
                }
    }
    cout<<(ans+waysp[t]*waysq[s]%MOD)%MOD;
}