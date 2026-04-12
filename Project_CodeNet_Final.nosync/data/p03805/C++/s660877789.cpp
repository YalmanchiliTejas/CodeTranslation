#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#define ll long long int
#define MOD 1000000007LL
using namespace std;
bool G[10][10];
const int NMAX=8;
int dfs(int s,int n,bool v[NMAX]){
    bool av=true;
    for(int i=0;i<n;i++){
        if(v[i]==false){
            av=false;
        }
    }
    if(av){
        return 1;
    }
    int r=0;
    for(int i=0;i<n;i++){
        if(G[s][i]){
            if(!v[i]){
                v[i]=true;
                r+=dfs(i,n,v);
                v[i]=false;
            }
        }
    }
    return r;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=false;
        }
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b]=true;
        G[b][a]=true;
    }
    bool visited[NMAX];
    for(int i=0;i<NMAX;i++){
        visited[i]=false;
    }
    visited[0]=true;
    cout<<dfs(0,n,visited)<<endl;
}
