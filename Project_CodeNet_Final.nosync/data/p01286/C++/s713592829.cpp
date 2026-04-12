#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;

struct edge{
    int to, cap, rev;
    edge(int t, int c, int r):to(t),cap(c),rev(r){}
    edge(){}
};

void add_edge(int from, int to, int cap, vector<vector<edge>> &graph){
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, (int)graph[from].size()-1);
}

int dfs(int v, int g, int flow, vector<vector<edge>>& adj, vector<bool>& used){
    if(used[v]) return -1;
    used[v] = true;
    if(v == g) return flow;
    
    for(int i=0; i<(int)adj[v].size(); i++){
        edge& next = adj[v][i];
        if(next.cap > 0){
            int ret = dfs(next.to, g, min(flow, next.cap), adj, used);
            if(ret > 0){
                next.cap -= ret;
                adj[next.to][next.rev].cap += ret;
                return ret;
            }
        }
    }
    return -1;
}

int maxflow(int s, int g, vector<vector<edge>> &graph){
    int res = 0;
    while(1){
        vector<bool> used((graph.size()+1)*2, false);
        int ret = dfs(s, g, inf, graph, used);
        if(ret==-1) break;
        res += ret;
    }
    return res;
}

int main(){
    while(1){
        int h,w,c,m,nw,nc,nm;
        cin >> h >> w >> c >> m >> nw >> nc >> nm;
        if(h == -1) break;

        vector<vector<edge>> graph((h+w+c+m)*2 +8);
        // node使用制限
        for(int i=8; i<(int)graph.size()-1; i+=2){
            add_edge(i, i+1, 1, graph);
        }
        add_edge(2, 3, nw, graph);
        add_edge(4, 5, nc, graph);
        add_edge(6, 7, nm, graph);
        // job間相性
        for(int i=0; i<w; i++){
            int num;
            cin >> num;
            for(int j=0; j<num; j++){
                int a;
                cin >> a;
                a--;
                add_edge(8 +2*a+1, 8+2*h +2*i+0, 1, graph);
            }
        }
        for(int i=0; i<c; i++){
            int num;
            cin >> num;
            for(int j=0; j<num; j++){
                int a;
                cin >> a;
                a--;
                add_edge(8+2*h +2*a+1, 8+2*h+2*w +2*i+0, 1, graph);
            }
        }
        for(int i=0; i<m; i++){
            int num;
            cin >> num;
            for(int j=0; j<num; j++){
                int a;
                cin >> a;
                a--;
                add_edge(8+2*h+2*w +2*a+1, 8+2*h+2*w+2*c +2*i+0, 1, graph);
            }
        }
        // sg
        for(int i=0; i<h; i++){
            add_edge(0, 8 +2*i+0, 1, graph);
        }
        for(int i=0; i<m; i++){
            add_edge(8+2*h+2*w+2*c +2*i+1, 1, 1, graph);
        }
        // skip
        for(int i=0; i<h; i++){
            add_edge(8+ 2*i+1, 2, 1, graph);
        }
        for(int i=0; i<w; i++){
            add_edge(8+2*h +2*i+1, 4, 1, graph);
        }
        for(int i=0; i<c; i++){
            add_edge(3, 8+2*h+2*w +2*i+0, 1, graph);
            add_edge(8+2*h+2*w +2*i+1, 6, 1, graph);
        }
        for(int i=0; i<m; i++){
            add_edge(5, 8+2*h+2*w+2*c +2*i+0, 1, graph);
        }
        add_edge(7, 1, inf, graph);

        cout << maxflow(0, 1, graph) << endl;
    }
    return 0;
}
