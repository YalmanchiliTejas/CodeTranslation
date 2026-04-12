#include <bits/stdc++.h>
using namespace std;
//static const int INF = (1 << 21);

vector<bool> visited(8);
vector<vector<bool>> perm(8, vector<bool>(8));
int N;
int dfs(int x, int N){
    bool all_visited = true;
    for(int i = 0; i < N; i++){
        if(visited.at(i) == false){
            all_visited = false;
        }
    }
    if(all_visited){
        return 1;
    }
    
    int ret = 0;
    
    for(int i = 0; i < N; i++){
        if(perm.at(x).at(i) == false) continue;
        if(visited.at(i)) continue;
        
        visited.at(i) = true;
        ret += dfs(i, N);
        visited.at(i) = false;
    }
    
    return ret;
}

int main(void){
    // Your code here!
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int x,y;
        cin >> x >> y;
        perm.at(x-1).at(y-1) = 1;
        perm.at(y-1).at(x-1) = 1;
    }
    
    visited.at(0) = true;
    cout << dfs(0, N) << endl;
}
