#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int now_p, int N, bool visited[nmax])
{
    bool all_visited = true;
    rep(i,N)
    {
        if (!visited[i]) all_visited = false;
    }
    if (all_visited) return 1;
    int ret = 0;
    rep(i,N) {
        if (!graph[now_p][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;

        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    cin >> n >> m;
    rep(i,n) rep(j,n) graph[i][j] = false;
    rep(i,m)
    {
        int x,y;
        cin >> x >> y;
        --x;--y;
        graph[x][y] = true;
        graph[y][x] = true; 
    }
    bool visited[n];
    rep(i,8) visited[i]=false;
    visited[0] = true;
    
    cout << dfs(0, n, visited) << endl;
}
