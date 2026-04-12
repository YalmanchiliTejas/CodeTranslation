#include <bits/stdc++.h>
using namespace std;
 
bool G[11][11];
bool vis[11];
vector<int> node;
int n,cnt;
 
 
void solve(int a){
    if(node.size()==n) cnt++;
    for(int i=1;i<=n;i++){
        if(G[a][i] && (!vis[i])){
            vis[i] = true;
            node.push_back(i);
            solve(i);
            vis[i] = false;
            node.pop_back();
        }
    }
}
 
int main(){
    int m,a,b;
    scanf("%d %d",&n,&m);
    memset(vis,false,sizeof(vis));
    memset(G,false,sizeof(G));
    while(m--){
        scanf("%d %d",&a,&b);
        G[a][b] = true;
        G[b][a] = true;
    }
    
    node.clear();

    vis[1] = true;
    node.push_back(1);
    solve(1);

    
    printf("%d\n", cnt);
    return 0;
}