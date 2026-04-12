#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll
#define INF 1e16
#define mod 1000000007
using Graph = vector<vector<ll>>;
ll n,m;
ll a,b;
ll ans = 0;
// vector<ll> a,b;
// vector< vector<ll> > edge(vector<ll>(),0);
vector<bool> vis(false);

void dfs(const Graph &G, ll v, ll cnt) {
     // v を訪問済にする
    // v から行ける各頂点 next_v について
    if(cnt==n) ans++;
    for (auto next_v : G[v]) { 
        if (vis[next_v]) continue; // next_v が探索済だったらスルー
        vis[next_v] = true;
        dfs(G, next_v,cnt+1); // 再帰的に探索
        vis[next_v] = false;
    }
}
int main(){
    cin>>n>>m;
    // a.resize(n);
    // b.resize(n);
    vis.resize(n);
    Graph G(n);
    rep(i,m) {
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vis[0] = true;
    dfs(G, 0, 1);
    cout<<ans<<endl;
    return 0;
}


	// #include <iostream>
    // #include <vector>
    // using namespace std;
    // using Graph = vector<vector<int>>;
    // // 深さ優先探索
    // vector<bool> seen;
    // void dfs(const Graph &G, int v) {
    // seen[v] = true; // v を訪問済にする
    // // v から行ける各頂点 next_v について
    // for (auto next_v : G[v]) { 
    // if (seen[next_v]) continue; // next_v が探索済だったらスルー
    // dfs(G, next_v); // 再帰的に探索
    // }
    // }
    // int main() {
    // // 頂点数と辺数
    // int N, M; cin >> N >> M;
    // // グラフ入力受取 (ここでは無向グラフを想定)
    // Graph G(N);
    // for (int i = 0; i < M; ++i) {
    // int a, b;
    // cin >> a >> b;
    // G[a].push_back(b);
    // G[b].push_back(a);
    // }
    // // 頂点 0 をスタートとした探索
    // seen.assign(N, false); // 全頂点を「未訪問」に初期化
    // dfs(G, 0);
    // }