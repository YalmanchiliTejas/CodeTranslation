#include <bits/stdc++.h>
#define rep(i, a) for(auto i=0; i<a; i++)
#define rep1(i, a, b) for(auto i=a; i<b; i++)
#define p_b push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<vi> vvi;

int cnt = 0;

void dfs(vvi &g, vi &v, int x, const int &n, int c){
    if(v[x])
        return;
    if(c==n-1)
        cnt++;
    v[x] = 1;
    for(auto i:g[x])
        dfs(g, v, i, n, c+1);
    v[x] = 0;
}

int main() {
    ll n, m;
    cin>>n>>m;
    vvi v(n);
    vi vis(n, 0);
    rep(i, m){
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        v[x].p_b(y);
        v[y].p_b(x);
    }
    dfs(v, vis, 0, n, 0);
    cout<<cnt;
    return 0;
}
