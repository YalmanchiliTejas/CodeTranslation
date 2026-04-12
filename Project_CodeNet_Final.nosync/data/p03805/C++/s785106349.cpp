#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
typedef long long ll;
static const ll maxLL = (ll)1 << 62;

int n,m,ans=0;
const int nmax=8;
int a[nmax],b[nmax];
bool graph[nmax][nmax];
bool all_visited=true;

int dfs(int v,int n,bool visited[nmax]){
    bool all_visited=true;
    
    rep(i,0,n){
        if(visited[i]==false)all_visited=false;
    }
    if(all_visited)return 1;
    
    int ret=0;
    
    rep(i,0,n){
        if(graph[v][i]==false)continue;
        if(visited[i])continue;
        
        visited[i]=true;
        ret+=dfs(i,n,visited);
        visited[i]=false;
    }
    return ret;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=graph[b-1][a-1]=true;
    }
    
    bool visited[nmax];
    rep(i,0,n)visited[i]=false;
    
    visited[0]=true;
    cout<<dfs(0,n,visited)<<endl;
    return 0;
}