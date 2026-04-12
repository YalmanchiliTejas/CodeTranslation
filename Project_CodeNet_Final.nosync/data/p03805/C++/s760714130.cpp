#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int v_max = 8;
int A[v_max][v_max];

int dfs(int v, int N, int visited[]){
    bool all_visited = true;
    int ans = 0;

    for(int i=0;i<N;i++){
        if(visited[i] == 0){
            all_visited = false;
        }
    }
    if(all_visited){
        return 1;
    }
    for(int i=0;i<N;i++){
        if(A[v][i]==1 && visited[i]==0){
            visited[i] = 1;
            ans += dfs(i, N, visited);
            visited[i] = 0;
        }
    }
    return ans;
}

int main(void){
    int N,M;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j] = 0;
        }
    }

    for(int i=0;i<M;i++){
        int tmp,tmp2;
        cin >> tmp >> tmp2;
        A[tmp-1][tmp2-1] = 1;
        A[tmp2-1][tmp-1] = 1 ;
    }

    int visited[v_max];
    for(int i=0;i<v_max;i++){
        visited[i] = 0;
    }
    visited[0] = 1;

    cout << dfs(0, N, visited) << endl;
    return 0;
}