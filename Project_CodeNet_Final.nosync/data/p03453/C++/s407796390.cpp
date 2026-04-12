#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << (x) << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 100001




vector<pair<ll,ll>> adj[N];
ll ds[N];
ll ds2[N];
int s,t;
ll dist;
bool vis[N];
vector<ll> ord;
ll il[N];
ll il2[N];
ll mod = 1e9+7;

void d1(int v){
    vis[v] = 1;
    if(ds[v]*2 == dist){
        ord.pb(il[v]*il2[v]%mod);
    }
    FORR(i,adj[v]){
        if(ds2[i.e1]+i.e2+ds[v] == dist){
            if(ds[v]*2 < dist && ds[i.e1]*2 > dist){
                /* whatis(il[v]) */
                /* whatis(il2[i.e1]) */
                ord.pb(il[v]*il2[i.e1]%mod);
            }
            if(!vis[i.e1])
                d1(i.e1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    memset(ds,127,n<<3);
    memset(ds2,127,n<<3);
    sc(s,t);
    --s,--t;
/* vi p[N]; */
    while(m--){
        int f,s,w;
        sc(f,s,w);
        --f,--s;
        adj[f].pb({s,w});
        adj[s].pb({f,w});
    }
    ds[s] = 0;
    il[s] = 1;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int v = pq.top().e2;
        ll w = -pq.top().e1;
        pq.pop();
        if(w != ds[v]) continue;
        FORR(i,adj[v]){
            ll neww = w+i.e2;
            if(ds[i.e1] > neww){
                ds[i.e1] = neww;
                pq.push({-neww,i.e1});
                il[i.e1] = il[v];
                /* p[i.e1] = {v}; */
            }
            else if(ds[i.e1] == neww){
                il[i.e1] += il[v];
                il[i.e1] %= mod;
            }
            /* else if(ds[i.e1] == neww){ */
            /*     p[i.e1].pb(v); */
            /* } */
        }
    }
    {
        ds2[t] = 0;
        il2[t] = 1;
        priority_queue<pair<ll,int>> pq;
        pq.push({0,t});
        while(!pq.empty()){
            int v = pq.top().e2;
            ll w = -pq.top().e1;
            pq.pop();
            if(w != ds2[v]) continue;
            FORR(i,adj[v]){
                ll neww = w+i.e2;
                if(ds2[i.e1] > neww){
                    ds2[i.e1] = neww;
                    pq.push({-neww,i.e1});
                    il2[i.e1] = il2[v];
                    /* p[i.e1] = {v}; */
                }
                else if(ds2[i.e1] == neww){
                    il2[i.e1] += il2[v];
                    il2[i.e1] %= mod;
                }
                /* else if(ds[i.e1] == neww){ */
                /*     p[i.e1].pb(v); */
                /* } */
            }
        }
    }
    assert(ds[t] == ds2[s]);
    dist = ds[t];
    d1(s);
    ll ans = 0;
    ll in = 0;
    FORR(i,ord){
        ans += i*in;
        in += i;
        ans %= mod;
        in %= mod;
    }
    /* whatis(ord) */
    ans *= 2;
    ans %= mod;
    cout << ans << '\n';
    /* cout << inter*(inter-1)%1000000007 << '\n'; */
}

