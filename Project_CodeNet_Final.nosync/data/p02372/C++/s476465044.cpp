#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {
    }
    
    int other(int u) {
        return u == from ? to : from;
    }
};

struct TreeDepth {
    int n;
    vector<vector<int>> g;
    vector<Edge> edges;
    int bestDist;
    int bestNode;
  
    TreeDepth(int n) : n(n) {
        g.assign(n, vector<int>());
    }
    
    void addEdge(int from, int to, int w) {
        edges.push_back(Edge(from, to, w));
        g[from].push_back(edges.size() - 1);
        g[to].push_back(edges.size() - 1);
    }
    
    int solve(vector<int>& ans) {
        
        bestDist = 0;
        bestNode = -1;
        vector<int> dists(n);
        dfs(0, -1, 0, dists);
        
        bestDist = 0;
        //cout << "X" << bestNode << endl;
        vector<int> distsX(n);
        dfs(bestNode, -1, 0, distsX);
        
        bestDist = 0;
        //cout << "Y" << bestNode << endl;
        vector<int> distsY(n);
        dfs(bestNode, -1, 0, distsY);
        
        for (int i = 0; i < n; i++) {
           ans[i] = max(distsX[i], distsY[i]); 
        }
        return bestDist;
    }
     
    void dfs(int u, int p, int d, vector<int>& dists) {
        if (d > bestDist) {
            bestDist = d;
            bestNode = u;
        }
        dists[u] = d;
        for (int e : g[u]) {
            Edge edge = edges[e];
            int v = edges[e].other(u);
            if (v != p) {
                dfs(v, u, d +  edge.weight, dists);
            }
        }
    }   
};

int main() {
    int n;
    cin >> n;
    
    TreeDepth d(n);
    for (int i = 0; i < n - 1; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        d.addEdge(from, to, w);
    }
    vector<int> ans(n);
    d.solve(ans);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}