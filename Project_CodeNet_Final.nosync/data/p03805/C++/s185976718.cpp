#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n,m;
int ans = 0;
vector<vector<int>>g;
void dfs(int v,vector<bool>& check) {
    check[v] = true;
    for(auto nv : g[v]) {
        if(!check[nv]) {
            dfs(nv,check);
            int tmp = 0;
            rep(i,check.size()) {
                if(!check[i]) break;
                tmp++;
            }
            if(tmp == n) ans++;
            check[nv] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    g.resize(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool>check(n,false);
    dfs(0,check);
    cout << ans << endl;
}
    