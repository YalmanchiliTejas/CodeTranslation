#include <stdio.h>
#include <iostream>
using namespace std;

int a,b,n,m;
int arc[9][9]={};
int flag[9]={};
    
int dfs(int u){
    int ans;
    for(int i=1;i<=n;i++){
        if(flag[i]!=1){
            break;
        }else if(i==n){
            return 1;
        }
    }

    ans=0;

    for(int i=0;i<=n;i++){
        if(arc[u][i]!=1)continue;
        if(flag[i]==1)continue;
        flag[i]=1;
        ans+=dfs(i);
        flag[i]=0;
    }
    return ans;
}

int main()
{
    int ans;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        arc[a][b]=1;
        arc[b][a]=1;
    }
    flag[1]=1;
    ans=dfs(1);
    cout<<ans<<endl;
    return 0;
}