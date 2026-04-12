#include<iostream>
#include<vector>

using namespace std;

int bfs(int now,int n,vector<int> *v,bool *visited){
    visited[now] = true;
    int path = 0;
    //cout << "Now=" << now <<endl;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            break;
        }
        if(i==n-1){
            return 1;
        }
    }

    for(int i=0;i<v[now].size();i++){
        if(visited[v[now][i]] == true){
            continue;
        }
        path += bfs(v[now][i],n,v,visited);
        visited[v[now][i]] = false;
    }
    return path;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector <int>  v[n];
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    } 
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " " ;
        }
        cout << endl;
    }*/
    int ans = bfs(0,n,v,visited);
    cout << ans <<endl;return 0;
}