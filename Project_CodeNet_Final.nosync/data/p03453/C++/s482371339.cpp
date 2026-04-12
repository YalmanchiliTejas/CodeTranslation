#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
constexpr double eps=1e-8;
const double pi=acos(-1);
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int Random(int mi,int ma){
    random_device rnd;
    mt19937 mt(rnd());//32bit
    //[mi,ma]
    uniform_int_distribution<int>engine(mi,ma);
    return engine(mt);
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
vector<int>kaijo,invkaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    invkaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
    rep(i,n+1)invkaijo[i]=modpow(kaijo[i],mod-2);
}
int comb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
struct edge{int to,cost;};
int n,m,s,t,d[100010],dp1[100010],dp2[100010];
vector<edge>v[100010];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>q;
    q.push({0,s});
    fill(d,d+n,INF);
    d[s]=0;
    while(!q.empty()){
        P p=q.top();
        q.pop();
        if(d[p.se]!=p.fi)continue;
        for(edge e:v[p.se]){
            if(d[e.to]>p.fi+e.cost){
                d[e.to]=p.fi+e.cost;
                q.push({d[e.to],e.to});
            }
        }
    }
}
void calc1(int s){
    priority_queue<P,vector<P>,greater<P>>q;
    rep(i,n)q.push({d[i],i});
    dp1[s]=1;
    while(!q.empty()){
        P p=q.top();
        q.pop();
        for(edge e:v[p.se]){
            if(d[e.to]==d[p.se]+e.cost){
                dp1[e.to]+=dp1[p.se];
                dp1[e.to]%=mod;
            }
        }
    }
}
void calc2(int t){
    priority_queue<P>q;
    rep(i,n)q.push({d[i],i});
    dp2[t]=1;
    while(!q.empty()){
        P p=q.top();
        q.pop();
        for(edge e:v[p.se]){
            if(d[e.to]==d[p.se]-e.cost){
                dp2[e.to]+=dp2[p.se];
                dp2[e.to]%=mod;
            }
        }
    }
}
void solve(){
    cin>>n>>m>>s>>t;
    s--,t--;
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    dijkstra(s);
    calc1(s);
    calc2(t);
    int ans=dp1[t]*dp1[t]%mod;
    rep(i,n){
        if(d[i]*2==d[t]){
            ans-=dp1[i]*dp1[i]%mod*dp2[i]%mod*dp2[i]%mod;
            ans+=mod;
            ans%=mod;
        }
    }
    rep(i,n){
        for(edge e:v[i]){
            int from=i,to=e.to;
            if(2*d[from]<d[t]&&2*d[to]>d[t]&&d[from]+e.cost==d[to]){
                ans-=dp1[from]*dp1[from]%mod*dp2[to]%mod*dp2[to]%mod;
                ans+=mod;
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    cin.tie(0);ios::sync_with_stdio(false);
    //int t;cin>>t;while(t--)
    solve();
    return 0;
}
