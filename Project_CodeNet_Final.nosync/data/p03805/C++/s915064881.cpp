// One-stroke Path
#include <iostream>
using namespace std;

int n,m;
int a,b,d[100][100];
bool visited[100];

int dfs(int v){
    bool all_visited=true;
    for(int i=0;i<n;i++)if(visited[i]==false) all_visited=false;
    if(all_visited) return 1;
    int r=0;
    for(int i=0;i<n;i++){
        if(d[v][i]&&!visited[i]){
            visited[i]=true;
            r+=dfs(i);
            visited[i]=false;
        }
    }
    return r;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        d[a-1][b-1]=1;
        d[b-1][a-1]=1;
    }
    visited[0]=true;
    cout<<dfs(0)<<endl;
    return 0;
}