#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

int n, m, q;
int d[4010];

struct edge{
   int to, cost;
//    edge(int to, int cost):to(to), cost(cost){}
};
vector<edge> G[4010]; 

struct UF{
   vector<int> par;
   vector<int> sz;
   UF(){}
   UF(int n){
       par.resize(n);
       sz.resize(n, 1);
       rep(i, 0, n) par[i] = i;
   }
   int find(int x){
       if(x == par[x]) return x;
       return par[x] = find(par[x]);
   }
   void unite(int x, int y){
       x = find(x); y = find(y);
       if(x == y) return;
       if(sz[x] < sz[y]) swap(x, y);
       sz[x] += sz[y];
       par[y] = x;
   }
   bool same(int x, int y){
       return find(x) == find(y);
   }
};

vector<pair<int, P> > es; 
// vector<int> path;
int pMAX[4010][4010];
// int cost[4010][4010];

void dfs(int now, int pre, int MAX, int root){
    // cout << " " << now << " " << pre << endl;
    // path[now] = pre;
    pMAX[root][now] = MAX;
    // if(now == dest) return;
    rep(i, 0, G[now].size()){
        int next = G[now][i].to;
        if(next == pre) continue;
        // path[next] = now;       
        dfs(next, now, max(MAX, G[now][i].cost), root);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        // G[a].push_back(edge{b, c});
        // G[b].push_back(edge{a, c});
        es.push_back(pair<int, P>(c, P(a, b)));
        // cost[a][b] = c;
        // cost[b][a] = c;
    }
    sort(all(es));
    UF uf(n);
    int sum = 0, cnt = 0;
    rep(i, 0, es.size()){
        int from = es[i].second.first;
        int to = es[i].second.second;
        if(uf.same(from, to) == false){
            uf.unite(from, to);
            sum += es[i].first;
            G[from]. push_back(edge{to, es[i].first});
            G[to]. push_back(edge{from, es[i].first});
        }
    }
    // cout << sum << endl;
    rep(i, 0, n){
        // path.clear(); path.resize(n, -1);
        dfs(i, -1, 0, i);
    }
    cin >> q;
    rep(i, 0, q){
        int s, t;
        cin >> s >> t;
        s--; t--;
        // path.clear(); path.resize(n, -1);
        // dfs(s, -1, t);
        cout << sum - pMAX[s][t] << endl;
        // int MAX = 0;
        // int now = t;
        // while(now != s){
        //     int next = path[now];
        //     chmax(MAX, cost[now][next]);
        //     now = next;
        // }
        // cout << sum - MAX << endl;
        // rep(j, 0, path.size()){
        //     cout << path[j] << " ";
        // }
        // cout << endl;
        // dijkstra(s);
        // cout << d[t] << endl;
    }
}