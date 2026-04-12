#include <bits/stdc++.h>
using namespace std;


int N,M,a,b;
vector<bool> visited(8,false);
long long res=0;
vector<vector<int>> v(8,vector<int> (8,0));


void dfs(int i){
    
    bool f = true;
    visited[i] = true;
    for (int j=0;j<N;j++){
        if (visited[j]==false && v[i][j]==1) {
            dfs(j);
            visited[j]=false;
        }
    }
    for (int k=0;k<N;k++){
        if (visited[k] ==false) f = false; 
    }
    if(f) res += 1;
    
}

int main(){
    cin >> N >> M;
    
    for (int i=0;i<M;i++){
        cin >> a >> b;
        v[a-1][b-1] = v[b-1][a-1] = 1;
        }

    dfs(0);


    cout << res << endl;
    }