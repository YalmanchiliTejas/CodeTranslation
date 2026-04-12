#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;


const int MAX_V = 10000;

class Edge{
    public:
        int dst, weight;
        Edge(){}
        Edge(int dst, int weight): dst(dst), weight(weight)  {}
};

typedef vector<vector<Edge>> Graph;

Graph g(MAX_V);

int visit(Graph &t, int i, int j) {
    if(t[i][j].weight >= 0) return t[i][j].weight;
    t[i][j].weight = g[i][j].weight;
    int u = t[i][j].dst;
    rep(k,t[u].size()) {
        if(t[u][k].dst == i) continue;
        t[i][j].weight = max(t[i][j].weight, visit(t,u,k) + g[i][j].weight);
    }
    return t[i][j].weight;
}
vector<int> height(int n) {
    Graph t = g;
    rep(i,n) rep(j,t[i].size()) t[i][j].weight = -1;
    rep(i,n) rep(j,t[i].size()) if(t[i][j].weight < 0) t[i][j].weight = visit(t, i, j);

    vector<int> ht(n); // gather results
    rep(i,n) rep(j,t[i].size()) ht[i] = max(ht[i], t[i][j].weight);
    return ht;
}

int main(){
    int n;
    cin >> n;
    rep(i,n - 1){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    vector<int> h = height(n);
    for(auto it:h) cout << it << endl;
}