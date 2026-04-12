#include<iostream>
using namespace std;

int N,M;
bool G[10][10];
int res=0;
bool used[10];

void dfs(int v,int cnt){
    if(cnt==N){
        res++;
        return;
    }
    used[v]=true;
    for(int i=0;i<N;i++){
        if(!used[i]&&G[v][i])dfs(i,cnt+1);
    }
    used[v]=false;
}
 
signed main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b]=G[b][a]=true;
    }
    dfs(0,1);
    cout<<res<<endl;
}