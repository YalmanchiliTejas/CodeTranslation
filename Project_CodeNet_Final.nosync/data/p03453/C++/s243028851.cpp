#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(ll i=(j); i<(k); i++)
#define DFOR(i, j, k) for(ll i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "E"
ll n, m, s, t;
vector <pair <ll, ll> > g[100001];
ll f[2][100001];
bool good[100001];
ll half;
struct cmp{
    bool operator () (pair <ll, ll> a, pair <ll, ll> b){
        return a.second>b.second;
    }
};
priority_queue <pair <ll, ll>, vector <pair <ll, ll> >, cmp> q;
void dij(ll s, ll a){
    while(!q.empty()) q.pop();
    FOR(i, 1, n) f[a][i]=mask(60);
    q.push(mp(s, 0));
    f[a][s]=0;
    pair <ll, ll> p;
    while(!q.empty()){
        p=q.top();
        q.pop();
        if(p.second>f[a][p.first]) continue;
        for(pair <ll, ll> v: g[p.first]){
            if(f[a][v.first]>f[a][p.first]+v.second){
                f[a][v.first]=f[a][p.first]+v.second;
                q.push(mp(v.first, f[a][v.first]));
            }
        }
    }
}
const ll base=1000000007;
class graph{
    vector <ll> g[1000001];
    vector <ll> h[1000001];
    public: void add_edge(ll u, ll v){
        g[u].pb(v);
        h[v].pb(u);
    }
    ll a[1000001];
    ll b[1000001];
    bool doneA[1000001];
    bool doneB[1000001];
    public: ll A(ll u){
        if(doneA[u]) return a[u];
        doneA[u]=1;
        if(g[u].empty()) return a[u]=1;
        a[u]=0;
        for(ll v: g[u]) a[u]=(a[u]+A(v))%base;
        return a[u];
    }
    public: ll B(ll u){
        if(doneB[u]) return b[u];
        doneB[u]=1;
        if(h[u].empty()) return b[u]=1;
        b[u]=0;
        for(ll v: h[u]) b[u]=(b[u]+B(v))%base;
        return b[u];
    }
} G;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(m);
    read(s);
    read(t);
    {
        ll u, v;
        ll d;
        FOR(i, 1, m){
            read(u);
            read(v);
            read(d);
            d*=2;
            g[u].pb(mp(v, d));
            g[v].pb(mp(u, d));
        }
    }
    dij(s, 0);
    dij(t, 1);
    FOR(i, 1, n) if(f[0][i]+f[1][i]==f[0][t]) good[i]=1;
    half=f[0][t]/2;
    ll sz=n;
    FOR(u, 1, n) if(good[u]) for(pair <ll, ll> p: g[u]) if(f[0][u]+f[1][p.first]+p.second==f[0][t]){
        if(f[0][u]<half&&f[0][p.first]>half){
            sz++;
            G.add_edge(u, sz);
            G.add_edge(sz, p.first);
        }
        else G.add_edge(u, p.first);
    }
    ll ans=0;
    ll sum=0;
    FOR(i, 1, n) if(f[0][i]==half){
        ll c=(G.A(i)*G.B(i))%base;
        ans=(ans+(base-(c*c)%base))%base;
        sum=(sum+c)%base;
    }
    FOR(i, n+1, sz){
        ll c=(G.A(i)*G.B(i))%base;
        ans=(ans+(base-(c*c)%base))%base;
        sum=(sum+c)%base;
    }
    ans=(ans+(sum*sum)%base);
    ans%=base;
    if(ans<0) ans+=base;
    write(ans);
}