#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;


int dfs(int edge,int N,vector<bool>visited){
    // cerr <<"target="<< edge << endl;
    bool allVisited = true;
    for(int i =0;i<N;i++){
        if(!visited[i]){
            // cerr << i <<"is not visited" << endl;
        allVisited = false;
        }
    }
    if(allVisited){
        // cerr << "all_visited!" << endl;
        return 1;
    }
    int ret =0;
    if(edges[edge].size()==0){
        // cerr << "no destination"  << endl;
        return 0;
    }
    for(int to: edges[edge]){
        if(visited[to]){
            // cerr << "to="<< to << "is already visited" << endl;
            continue;
        }
        visited[to] = true;
        ret += dfs(to,N,visited);
        visited[to] = false;
    }
    return ret;
    
    

}

int main(){
    int N,M;
    cin >> N >>M;
    edges.resize(N);

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<bool> visited(N,false);
    visited[0] = true;
    cout << dfs(0,N,visited) << endl;
    

    return 0;
}