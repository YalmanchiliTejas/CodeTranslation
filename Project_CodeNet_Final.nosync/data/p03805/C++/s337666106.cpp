#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

using Graph = vector<vector<int>>;

int re[100];
int ans = 0;
void dfs(Graph& G,int a,int n){
    if(re[a] == 1 ) return;
    re[a] = 1;
    int sum = 0;
    rep(i,n){
        if(re[i] == 1){
            sum++;
        }
    }
    if(sum == n) ans++;
    for(auto x : G[a]){
        if(re[x] == 1) continue;
        dfs(G,x,n);
        re[x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    Graph G(n);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(G,0,n);

    cout << ans << endl;
    return 0;
}
