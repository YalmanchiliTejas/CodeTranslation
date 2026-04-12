#include <bits/stdc++.h>
using namespace std;
int N,M,ans=0;
vector<int> V[9];
int a,b;

void dfs(int i,int v,int n,vector<bool> visited){
    //cout <<i<<" "<<v<<endl;
    if(i==n)ans++;
    for(int x:V[v]){
        if(visited[x])continue;
        visited[x]=true;
        dfs(i+1,x,n,visited);
        visited[x]=false;
    }
}

int main(){
    cin >>N >>M;
    for(int i=0;i<M;i++){
        cin >>a >>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }  

    //cout <<endl;
    vector<bool> visited(N+1,false);
    visited[1]=true;
   dfs(1,1,N,visited);
cout <<ans<<endl;

}
