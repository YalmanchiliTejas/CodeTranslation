#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int n;
bool e[8][8];
bool used[8];
int ans=0;

void dfs(int s){
    bool able=0;
    rep(g,8){
        if(e[s][g]&&!used[g]){
            able=1;
            used[g]=1;
            dfs(g);
            used[g]=0;
        }
    }
    if(!able){
        bool flg=1;
        rep(i,n){
            if(!used[i]) flg=0;
        }
        if(flg) ans++;
    }
}

int main(){
    int m; cin>>n>>m;
    rep(i,m){
        int a,b; cin>>a>>b;
        a--; b--;
        e[a][b]=e[b][a]=1;
    }
    used[0]=1;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
