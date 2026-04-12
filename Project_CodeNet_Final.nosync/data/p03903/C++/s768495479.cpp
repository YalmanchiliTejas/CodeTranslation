#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct edge{
    int from, to, cost;
    bool operator<(const edge &another) const
    {
        return cost < another.cost;
    };
};

//vector<edge> G[4000];
vector<edge> MST[4000];
vector<edge> es;
bool used[4000];
int max_edge[4000][4000];

int N, M;

void clear_used(){
    for(int i = 0; i < N; i++) used[i] = false;
}

void dfs(int root, int cur, int max_e){
    used[cur] = true;
    max_edge[root][cur] = max_e;
    for(int i = 0; i < MST[cur].size(); i++){
        if(!used[MST[cur][i].to]){
            dfs(root, MST[cur][i].to, max(max_e, MST[cur][i].cost));
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        es.push_back(edge{a, b, c});
    }
    UnionFind uf(N);
    sort(es.begin(), es.end());
    long sum = 0;
    for(int i = 0; i < M; i++){
        int from = es[i].from;
        int to = es[i].to;
        int cost = es[i].cost;
        if(uf.root(from) != uf.root(to)){
            //cout << "MST" << endl;
            MST[from].push_back(es[i]);
            MST[to].push_back((edge){to, from, cost});
            uf.unionSet(from, to);
            sum += (long)cost;
        }
    }
    for(int i = 0; i < N; i++){
        clear_used();
        dfs(i, i, 0);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        //cout << max_edge[s][t] << endl;
        cout << sum-max_edge[s][t] << endl;
    }
}

