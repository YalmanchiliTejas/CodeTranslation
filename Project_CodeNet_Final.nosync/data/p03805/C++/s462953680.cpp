#include<iostream>
#include<vector>
#include<queue>

using namespace std;

long long dfs(int idx, vector<bool> visited, const vector<vector<int>> &p){
    bool f = true;
    long long ans = 0;
    // cout << idx;
    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            f = false;
            break;
        }
    }
    if(f) return 1;
    for(int i = 0; i < p[idx].size(); i++){
        if(!visited[p[idx][i]]){
            visited[p[idx][i]] = true;
            ans += dfs(p[idx][i], visited, p);
            visited[p[idx][i]] = false;
        }
    }
    return ans;
}

int main(void){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> p(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        p[--a].push_back(--b);
        p[b].push_back(a);
    }
    vector<bool> visited(N, false);
    visited[0] = true;
    cout << dfs(0, visited, p) << endl;
    return 0;
}