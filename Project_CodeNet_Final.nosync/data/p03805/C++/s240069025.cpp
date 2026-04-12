#include<iostream>
using namespace std;
bool g[8][8];
int dfs(int now,int n,bool visited[]){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(visited[i]==false)   flag = false;
    }
    if(flag)    return 1;
    int ret = 0;
    for(int i=0;i<n;i++){
        if(g[now][i]&&!visited[i]){
            visited[i] = true;
            ret+=dfs(i,n,visited);
            visited[i] = false;
        }
    }
    return ret;
}

int main(){
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        g[a-1][b-1]=g[b-1][a-1]=true;
    }
    bool visited[8];
    visited[0]=true;
    for(int i=1;i<n;i++)    visited[i]=false;
    cout << dfs(0,n,visited) << endl;
    return 0;
}