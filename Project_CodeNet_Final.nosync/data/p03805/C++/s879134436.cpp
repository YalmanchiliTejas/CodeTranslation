#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int N, M;
int ans = 0;
void dfs(const Graph &G, int v,int cnt, set<int> seen) {
    seen.insert(v); // v を訪問済にする
    if(cnt == N) ans++;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen.count(next_v)) continue; // next_v が探索済だったらスルー
        int next_cnt = cnt + 1;
        set<int> next_seen = seen;
        dfs(G,next_v,next_cnt,next_seen); // 再帰的に探索
    }
}

int main(){

    // 頂点数と辺数
    cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    set<int> seen; // 全頂点を「未訪問」に初期化
    dfs(G,0,1,seen);
    cout << ans << endl;
    return 0;
}
