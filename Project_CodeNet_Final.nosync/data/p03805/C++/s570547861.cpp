#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>


long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;
const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v,int N,bool visited[nmax]){

    bool all_visited=true;

    for(int i=0;i<N;++i){
        if(visited[i]==false)
            all_visited=false;
    }
    
    if(all_visited){
        return 1;
    }

    int ret=0;

    for(int i=0;i<N;++i){
        //頂点vに隣接しているかつ未訪問ならdo
        if(graph[v][i]==false)continue;
        if(visited[i])continue;

        visited[i]=true;
        ret+=dfs(i,N,visited);//頂点iスタートで再帰
        visited[i]=false;
    }

    return ret;

}

int main(){

int N,M;
cin>>N>>M;
int a,b;
for(int i=0;i<M;i++){
cin>>a>>b;
a--;
b--;
graph[a][b]=true;
graph[b][a]=true;
}

bool visited[nmax];

for(int i=0;i<N;++i){
    visited[i]=false;
}

visited[0]=true;
cout<<dfs(0,N,visited)<<endl;

 return 0;
}