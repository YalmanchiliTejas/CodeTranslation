#include<iostream>
using namespace std;

bool ok[10];
bool g[10][10];
int n,m;

int dfs(int v){
    bool a=true;

    for(int i=0;i<n;i++){
        if(ok[i]==false) a=false;
    }

    if(a) return 1;

    int cnt=0;
    for(int i=0;i<n;i++){
        if(g[v][i]==false) continue;
        if(ok[i]) continue;
        ok[i]=true;
        cnt+=dfs(i);
        ok[i]=false;
    }
    return cnt;
}

int main(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int s,t; cin>>s>>t;
        g[s-1][t-1]=g[t-1][s-1]=true;
    }
    
    ok[0]=true;
    cout<<dfs(0)<<endl;
}