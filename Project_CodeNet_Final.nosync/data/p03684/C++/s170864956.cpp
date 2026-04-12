#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to;
    long long cost;
};

vector<vector<edge>> prim(vector<vector<edge>> graph) {
    vector<vector<edge>> minimum_spanning_tree(graph.size());
    vector<bool> used(graph.size(), false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minimum_edge_que;
    minimum_edge_que.push(make_pair(0, 0));
    int count_used = 0;
    int before_vertex = -1;

    while(true) {
        pair<long long, int> add_vertex;
        while(!minimum_edge_que.empty()) {
            add_vertex = minimum_edge_que.top();
            minimum_edge_que.pop();
            if (!used[add_vertex.second]) {
                //cout << before_vertex << " " << add_vertex.second << " " << add_vertex.first << endl;
                used[add_vertex.second] = true;
                count_used++;
                if (before_vertex != -1) {
                    edge e = {add_vertex.second, add_vertex.first};
                    minimum_spanning_tree[before_vertex].push_back(e);
                    e.to = before_vertex;
                    minimum_spanning_tree[add_vertex.second].push_back(e);
                }
                before_vertex = add_vertex.second;
                break;
            }
        }

        if (count_used == graph.size())
            break;

        for (int i = 0; i < graph[add_vertex.second].size(); i++) {
            edge e = graph[add_vertex.second][i];
            if (!used[e.to])
                minimum_edge_que.push(make_pair(e.cost, e.to));
        }
    }
    return minimum_spanning_tree;
}

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];
    
    vector<vector<edge>> graph(N);
    vector<int> idx(N);
    for (int i = 0; i < N; i++)
        idx[i] = i;
    sort(idx.begin(), idx.end(), [&x](size_t i1, size_t i2) {
        return x[i1] < x[i2];
    });
    for (int i = 0; i < N-1; i++) {
        edge e = {idx[i+1], abs(x[idx[i]]-x[idx[i+1]])};
        graph[idx[i]].push_back(e);
        e.to = idx[i];
        graph[idx[i+1]].push_back(e);
    }
    
    sort(idx.begin(), idx.end(), [&y](size_t i1, size_t i2) {
        return y[i1] < y[i2];
    });
    for (int i = 0; i < N-1; i++) {
        edge e = {idx[i+1], abs(y[idx[i]]-y[idx[i+1]])};
        graph[idx[i]].push_back(e);
        e.to = idx[i];
        graph[idx[i+1]].push_back(e);
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << "graph:" << i << " " << graph[i][j].to << " " << graph[i][j].cost << endl; 
        }
    }
    */
    
    vector<vector<edge>> minimum_spanning_tree = prim(graph);
    long long ans = 0;
    for (int i = 0; i < minimum_spanning_tree.size(); i++) {
        for (int j = 0; j < minimum_spanning_tree[i].size(); j++) {
            if (i < minimum_spanning_tree[i][j].to) {
                ans += minimum_spanning_tree[i][j].cost;
                //cout << minimum_spanning_tree[i][j].cost << endl;
            }
        }
    }
    cout << ans << endl;
}