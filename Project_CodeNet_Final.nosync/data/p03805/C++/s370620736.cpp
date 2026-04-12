#include<bits/stdc++.h>
using namespace std;
 
int N,M;
bool G[8][8];
 
bool visited[10];
int dfs(int v,int cnt){
    int ret=0;
    if(cnt==N)return 1;

    
    for (int i=0;i<N;i++){
        if(!visited[i]&&G[v][i]){
            //cout <<i+1<<" "<<cnt+1<<" "<<ret<<endl;
            visited[v]=true;
            ret+=dfs(i,cnt+1);
        }
         visited[v]=false;
    }
    return ret;
}
 
signed main(){
    cin>>N>>M;
    for (int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b]=G[b][a]=true;
    }
 
    dfs(0,1);
    cout<<dfs(0,1)<<endl;
    return 0;
}