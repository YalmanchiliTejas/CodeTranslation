#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

vector<vector<int>>graph;
int p, q;

void dfs(int n, vector<bool> &seen,int &ans){
    bool flag = true;
    int m = seen.size();
    rep(i, 0, m)if(!seen[i]&&i!=n)flag = false;
    if(flag){
        ans++;
        return;
    }
    seen[n] = true;
    for(auto i:graph[n]){
        if(seen[i])continue;
        dfs(i, seen, ans);
    }
    seen[n]=false;
}
int main(){
    cin >> p >> q;
    graph.assign(p, vector<int>());
    rep(i, 0, q){
        int a, b;
        cin >> a >> b;
        a--,b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool>seen(p,false);
    int ans = 0;
    dfs(0, seen, ans);
    cout << ans << endl;
    return 0;
}