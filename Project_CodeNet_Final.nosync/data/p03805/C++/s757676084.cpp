#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

void DFS(int start, const vector<vector<int>>& g, int& count, vector<bool>& visited){
    visited[start] = true;
    if (accumulate(visited.begin(), visited.end(), 1, multiplies<int>())){
        count += 1;
    }
    else{
        for (int i = 0; i < g.size(); ++i){
            if (g[start][i] == 1 && !visited[i]){
                visited[i] = true;
                DFS(i, g, count, visited);
                visited[i] = false;
            }   
        }
    }

    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, a, b;
    cin >> N >> M;
    
    vector<vector<int>> g(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i){
        cin >> a >> b;
        g[a-1][b-1] = 1;
        g[b-1][a-1] = 1;
    }

    int count = 0;
    vector<bool> visited(N, false);

    DFS(0, g, count, visited);

    cout << count << "\n";

    return 0;
}