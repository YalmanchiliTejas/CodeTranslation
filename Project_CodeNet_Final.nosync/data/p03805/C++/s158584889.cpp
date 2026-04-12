#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

const int nmax = 8;
bool mat[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    bool all_visited = true;
    for(int i = 0; i < N; i++){
        if(visited[i] == false){
            all_visited = false;
        }
    }
    if(all_visited){
        return 1;
    }
    int ret = 0;
    for(int i = 0; i < N; i++){
        if(mat[v][i] == false){
            continue;
        }else if(visited[i] == true){
            continue;
        }else{
            visited[i] = true;
            ret += dfs(i, N, visited);
            visited[i] = false;
        }
    }
    return ret;
}
int main(){
    int N, M;
    cin >> N >> M;
    int a[M], b[M];
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            mat[i][j] = false;
        }
    }
    for(int i = 0; i < M; i++){
        mat[a[i]-1][b[i]-1] = true;
        mat[b[i]-1][a[i]-1] = true;
    }

    // input done
    bool visited[N];
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }
    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    
    return 0;
}