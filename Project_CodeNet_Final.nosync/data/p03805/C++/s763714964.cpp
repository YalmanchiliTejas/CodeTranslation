#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main()
{
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vvi path(10, vi(10, 0));
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        path[a][b] = path[b][a] = 1;
    }

    vi v(n-1);
    for(int i = 2; i <= n; ++i) {
        v[i-2] = i;
    }
    int ans = 0;
    do {
        bool comp = true;
        if(!path[1][v[0]]) continue;
        REP(i, n-2) {
            if(!path[v[i]][v[i+1]]) {
                comp = false;
                break;
            }
        }
        if(comp == true) {
            ++ans;
        }
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}