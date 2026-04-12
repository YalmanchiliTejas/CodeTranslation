#include <iostream>

using namespace std;

int matrix[9][9] = {};
bool visited[9] = {};
int n,m;

int dfs(int current){
    bool all_visited = true;
    for(int i = 1; i <= n; i++){
        if(!visited[i])all_visited=false;
    }
    if(all_visited)return 1;
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(matrix[current][i]==0)continue;
        if(visited[i])continue;
        visited[i] = true;
        res += dfs(i);
        visited[i] = false;
    }
    return res;
}
int main(){
    
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        matrix[a][b] = matrix[b][a] = 1;
    }
    visited[1]=true;
    cout << dfs(1) << endl;
    return 0;
}