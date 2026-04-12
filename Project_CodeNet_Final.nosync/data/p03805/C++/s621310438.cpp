#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
 
using namespace std;
 
const ll MOD = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);


int ans,N,M;
int v[10];
vector<vector<int>> g;
void dfs(int x,int d){
    if(d==N){
        ans++;
        return ;
    }
    for(int i=0;i<g[x].size();i++){
        int next = g[x][i];
        if(v[next])continue;
        v[next] = 1;
        dfs(next,d+1);
        v[next] = 0;
    }
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> M;
    g.resize(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    v[0] = 1;
    dfs(0,1);
    v[0] = 0;
    cout << ans << endl;
}