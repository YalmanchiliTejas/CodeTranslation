#include<bits/stdc++.h>
#define MAX 10001

class Edge {
public:
    int target, cost;
    Edge(int target = 0, int cost = 0) : target(target), cost(cost) {}
};

std::vector<Edge> G[MAX];
int V, maxv, idx;
int C[MAX], SEC[MAX];
bool visited[MAX];

void dfs(int current){
    visited[current] = true;
    for(unsigned long i = 0; i < G[current].size(); i++){
        int next = G[current][i].target;
        if(!visited[next]){
            C[next] = C[current] + G[current][i].cost;
            if (C[next] > maxv) {
                maxv = C[next];
                idx = next;
            }
            dfs(next);
        }
    }
}

void solve(){

    int x;
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        C[i] = 0;
    }
    maxv = idx = 0;
    dfs(0);
    x = idx;
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        C[i] = 0;
    }
    x = idx;
    maxv = idx = 0;
    dfs(x);
    for(int i = 0; i < V; i++) SEC[i] = C[i];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        C[i] = 0;
    }
    x = idx;
    maxv = idx = 0;
    dfs(x);
}
int main() {
    int source, target, cost;
    std::scanf("%d", &V);
    for(int i = 0; i < V-1; i++){
        std::scanf("%d %d %d", &source, &target, &cost);
        G[source].push_back(Edge(target, cost));
        G[target].push_back(Edge(source, cost));
    }
    solve();
    for(int i = 0; i < V; i++){
        std::printf("%d\n", std::max(SEC[i], C[i]));
    }
    return 0;
}

