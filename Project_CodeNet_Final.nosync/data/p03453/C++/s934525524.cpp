#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}
vi dijkstra(int from,vvp g){
    vi dis(g.size(),inf);
    dis[from]=0;
    SPQ(P) pq;
    pq.push(P(0,from));
    while(!pq.empty()){
        auto t=pq.top();pq.pop();
        if(t.fi!=dis[t.se])continue;
        for(auto x:g[t.se]){
            if(chmin(dis[x.fi],t.fi+x.se))pq.push(P(dis[x.fi],x.fi));
        }
    }
    return dis;
}
vvp g;
vi dp,dp2,dis,dis2;
ll dfs(int i){
    if(dp[i]!=-1)return dp[i];
    dp[i]=0;
    for(auto x:g[i])if(dis[x.fi]==dis[i]-x.se)dp[i]+=dfs(x.fi);
    dp[i]%=mod;
    return dp[i];
}
ll dfs2(int i){
    if(dp2[i]!=-1)return dp2[i];
    dp2[i]=0;
    for(auto x:g[i])if(dis2[x.fi]==dis2[i]-x.se)dp2[i]+=dfs2(x.fi);
    dp2[i]%=mod;
    return dp2[i];
}
int main(){
    ll n,m;cin>>n>>m;
    ll s,t;cin>>s>>t;
    s--;t--;
    g=vvp(n);
    rep(i,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }
    dis=dijkstra(s,g);
    dis2=dijkstra(t,g);
    dp=vi(n,-1);dp2=vi(n,-1);
    dp[s]=1;dp2[t]=1;
    dfs(t);dfs2(s);
    ll ans=dp[t]*dp[t]%mod;
    rep(i,n){
        for(auto x:g[i])if(dis[x.fi]+x.se+dis2[i]==dis[t]){
            if(dis[x.fi]<dis2[x.fi]&&dis[i]>dis2[i]){
                ans=(ans+mod-(dp[x.fi]*dp[x.fi]%mod)*(dp2[i]*dp2[i]%mod)%mod)%mod;
                assert(dp[x.fi]!=-1);
                if(dp2[i]==-1)cout<<i<<' '<<x.fi<<endl;
                assert(dp2[i]!=-1);
            }
        }
    }
    rep(i,n)if(dis[i]==dis2[i]&&dis[i]+dis2[i]==dis[t]){
        ans=(ans+mod-(dp[i]*dp[i]%mod)*(dp2[i]*dp2[i]%mod)%mod)%mod;
    }
    while(ans<0)ans+=mod;
    out(ans);
}