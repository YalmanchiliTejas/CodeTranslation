#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

vector<int> g[8];
bool visited[8];
int ans = 0;
int n;

void dfs(int now){
    visited[now] = true;
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]) ok = false;
    }
    if(ok) ans++;
    for(auto next : g[now]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            visited[next] = false;
        }
    }
}


int main()
{
    int m;
    cin >> n >> m;
    
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,8) visited[i] = false;
    dfs(0);
    cout << ans;
}
