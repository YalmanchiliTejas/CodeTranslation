#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int n, m, ans = 0;
bool a[N][N], b[N]={};

void dfs(int u, int cnt){
    if(cnt == n) ans++;
    for(int v=1; v<=n; v++)
        if(!b[v] && a[u][v]){
            b[v] = true;
            dfs(v,cnt+1);
            b[v] = false;
        }
}

int main(){
    memset(a, false, sizeof a);
    memset(b, false, sizeof b);
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int u, v; cin>> u>> v;
        a[u][v] = a[v][u] = true;
    }

    b[1] = true;
    dfs(1,1);

    cout<< ans<< endl;
    return 0;
}
