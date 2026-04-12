
#include <iostream>
#include <vector>

using namespace std;


int dfs(int v, vector< vector<bool> > &G, vector<bool> &visited){
    bool F = true;
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == false){
            F = false;
            break;
        }
    }

    if(F == true){
        return 1;
    }else{
        int res = 0;
        
        for(int i = 0; i < visited.size(); i++){
            if(G[v][i] == true && visited[i] == false){
                visited[i] = true;
                res += dfs(i, G, visited);
                visited[i] = false;
            }else{
                continue;
            }
        }
        return res;
    }
}


int main(){
    int N, M;
    cin >> N >> M;
    vector< vector<bool> > G(N, vector<bool>(N, false));
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--; b--;
        G[a][b] = true; G[b][a] = true;
    }

    vector<bool> visited(N, false);
    visited[0] = true;

    int ans = dfs(0, G, visited);
    cout << ans << endl;

    return 0;
}