#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using Pii = pair<int, int>;

constexpr int INF = 1000;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(n, m);
    {
        int dd;
        for(int i=0;i<m;++i){
            cin >> dd;
            --dd;
            d[dd] = i;
        }
    }

    int pre_graph[m][k];
    int room;
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j) {
            cin >> room;
            if(d[i] == m) continue;
            --room;
            pre_graph[d[i]][j] = d[room];
        }
    }

    vector<int> graph[1<<m];
    for(int i=1;i<(1<<m);++i) {
        for(int path_i=0;path_i<k;++path_i) {
            int next_state = 0;
            for(int j=0;j<m;++j) {
                if(!(i & (1<<j))) continue;
                if(pre_graph[j][path_i] != m) next_state |= (1 << pre_graph[j][path_i]);
            }
            graph[i].push_back(next_state);
        }
    }

    vector<int> dists(1<<m, INF);
    dists[(1<<m)-1] = 0;
    priority_queue<Pii, vector<Pii>, greater<Pii>> que;
    que.emplace(0, (1<<m)-1);
    int current_state, current_dist;
    while(!que.empty()) {
        tie(current_dist, current_state)= que.top(); que.pop();
        if(dists[current_state] < current_dist) continue;
        for(int next_state: graph[current_state]) {
            if(dists[next_state] > current_dist + 1) {
                dists[next_state] = current_dist + 1;
                que.emplace(current_dist + 1, next_state);
            }
        }
    }
    

    cout << dists[0] << endl;
}
