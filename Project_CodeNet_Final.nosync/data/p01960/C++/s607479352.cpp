#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 100005;

int n, K;
vector<int> G[MAX_N];
int dp[MAX_N], sub[MAX_N], ans;

void dfs(int u, int p)
{
    int cnt = 0;
    sub[u] = 1;
    vector<pair<int, int> > vec;
    for(int v : G[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
            vec.emplace_back(dp[v] - (sub[v] >= K), v);
            if(sub[v] >= K) ++cnt;
        }
    }
    sort(all(vec), greater<pair<int, int> >());
    dp[u] = cnt;
    // show(dp[u]);
    for(int v : G[u]){
        if(v != p){
            cmx(dp[u], dp[v] + cnt - (sub[v] >= K));
            cmx(ans, dp[v] + cnt - (sub[v] >= K) + (n - sub[u] >= K));
            if((int)vec.size() >= 2){
                int res = vec[0].fi;
                if(vec[0].se == v) res = vec[1].fi;
                cmx(ans, dp[v] + cnt + res - (sub[v] >= K) + (n - sub[u] >= K));
            }
        }
    }
    // ashow(u, dp[u], sub[u]);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> K;
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        G[a-1].pb(b-1), G[b-1].pb(a-1);
    }
    dfs(0, -1);
    cout << ans << "\n";
    return 0;
}
