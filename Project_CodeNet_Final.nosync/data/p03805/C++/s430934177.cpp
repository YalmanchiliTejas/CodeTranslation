#include <iostream>
using namespace std;
int n,m,ans=0;
int d[8][8];
bool used[8];
int dfs(int i,int c){
    if(c==n-1){
        ans++;
        return 0;
    }
    for(int j=0;j<n;j++){
        if(d[i][j]&&!used[j]){
            used[j]=true;
            dfs(j,c+1);
            used[j]=false;
        }
    }
    return 0;
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        s--;
        t--;
        d[s][t]=1;
        d[t][s]=1;
    }
    for(int i=0;i<n;i++)used[i]=false;
    used[0]=true;
    dfs(0,0);
    cout<<ans<<endl;
}