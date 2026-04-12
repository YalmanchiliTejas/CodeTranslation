#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ll long long
const int INF = 1e9 + 7;

using namespace std;

#define MAX_V 8+1
int n,m,ans=0;
bool G[MAX_V][MAX_V];
bool used[MAX_V];

bool check(){
    FOR(i,1,n+1) if(!used[i]) return false;
    return true;
}

void dfs(int s){
    if(check()) ++ans;
    FOR(i,1,n+1){
        if(G[s][i] && !used[i]){
            //G[s][i] = false;
            used[i] = true;
            dfs(i);
            used[i] = false;
        }
    }
}

int main(){
    cin.tie(0), ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        G[a][b] = G[b][a] = true;
    }
    REP(i,n+1) used[i] = false;
    used[1] = true;
    dfs(1);
    cout << ans << endl;
    return 0;
}
