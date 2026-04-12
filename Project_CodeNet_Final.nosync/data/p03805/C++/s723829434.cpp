#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int n,m;
bool M[10][10];
bool visit[10];
int ans;

void dfs(int v){
    visit[v]=true;
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            flag=false;
            break;
        }
    }
    if(flag){
        ans++;
        return;
    }
    for(int i=2;i<=n;i++){
        if(M[v][i]&&!visit[i]){
            visit[i]=true;
            dfs(i);
            visit[i]=false;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        M[a][b]=true;
        M[b][a]=true;
    }
    dfs(1);
    cout<<ans<<endl;
}
