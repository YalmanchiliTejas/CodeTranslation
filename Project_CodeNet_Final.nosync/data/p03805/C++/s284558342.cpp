//C - One-stroke Path: 
//Assunto: 
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define loop(i, a, b) for(int i = a; i < b; i++)
#define loopBack(i, a, b) for(int i = a; i >= b; i--)
#define INF INT_MAX
#define LINF LLONG_MAX
#define DINF DBL_MAX
#define MAX 100050
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

int n, m, x, y;
int ans = 0;

void dfs(int no, vector<bool> vis, int total, vector<int> adj[]) {
    if(vis[no]) return;
    total++;
    if(total == n) ans++;
    vis[no] = true;
    for(auto x: adj[no]) {
        dfs(x, vis, total, adj);
    }
} 

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    vector<int> adj[n+1];
    loop(i, 0, m) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<bool> vis(n+1, false);
    dfs(1, vis, 0, adj);
    cout << ans << '\n';
}