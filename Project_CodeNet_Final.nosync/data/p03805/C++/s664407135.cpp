#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> G[8];

int dfs(int s, bool visited[8]) {
    visited[s] = true;
    bool done = true;
    for(int i=0; i<N; i++) {
        if(!visited[i]) {
            done = false;
            break;
        }
    }
    if(done){
        visited[s] = false;
        return 1;
    }
    int sum = 0;
    for(int i=0; i<G[s].size(); i++) {
        if(!visited[G[s][i]]){
            sum += dfs(G[s][i], visited);
        }
    }
    visited[s] = false;
    return sum;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bool visited[8];
    for(int i=0; i<N; i++) visited[i] = false;
    cout << dfs(0, visited) << endl;
    return 0;
}
