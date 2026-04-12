#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "Second" <<"\n"; return;}
#define SP << " " <<
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------
vector<ll> ike(101010);
bool ok=false;
struct edge{ll to;};
struct graph{
    ll N;
    vector<vector<edge> > G;
    vector<bool> used;

    graph(ll n): N(n), G(N), used(N,false) {}

    void ade(ll s, ll t){
        G[s].emplace_back((edge){t});
        G[t].emplace_back((edge){s}); //無向ならON
    }

    void dfs(ll v=0){
        used[v]=true;
        ll ct=0;
        for(auto E : G[v]){
            if(!used[E.to]){
                dfs(E.to);
                ct+=ike[E.to];
            }
        }
        if(ct>=2) ok=true;
        if(ct==0) ike[v]=1;
        else ike[v]=0;
    }
};

//--MAIN-----------------------------------
void Main() {
    ll N; cin>>N;
    // 下にtrueが2つ以上あればかち, trueが1つならfalseに, 0ならtrueに。
    // 2つ以上生えてる点をrootに。
    graph g(N);
    vector<ll> ct(N,0);
    ll root=-1;
    rep(i,N-1){
        ll a,b; cin>>a>>b;--a,--b;
        g.ade(a,b);
        if(++ct[a]>1) root=a;
        if(++ct[b]>1) root=b;
    }
    if(N==2) dame;
    g.dfs(root);
    cout<< ( ok ? "First" : "Second" )<<"\n";

}

//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
