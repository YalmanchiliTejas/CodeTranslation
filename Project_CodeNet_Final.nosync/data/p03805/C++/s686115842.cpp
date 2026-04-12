#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(b)-1;i>=(a);i--)

int n,m;
bool g[25][21];
bool used[830];

int dfs(int pos,int cnt){
    if(cnt==n)return 1;
    int ret = 0;
    REP(to,n)if(g[pos][to] && !used[to]){
        used[to] = true;
        ret += dfs(to,cnt+1);
        used[to] = false;
    }
    return ret;
}

int main(void){
    cin>>n>>m;
    REP(i,m){
        int a,b;
        cin>>a>>b;
        --a;--b;
        g[a][b] = g[b][a] = true;
    }
    used[0] = true;
    printf("%d\n",dfs(0,1));
    return 0;
}
