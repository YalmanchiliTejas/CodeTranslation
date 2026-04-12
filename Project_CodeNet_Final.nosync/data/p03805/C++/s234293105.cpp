#include <bits/stdc++.h>
using namespace std;
// #define rep(i,n) for(int i=0;i<n;++i)
#define rep(i,i0,n) for(int i=i0;i<n;++i)
#define ALL(x) (x).begin(),(x).end()
#define pb(x)  push_back(x);
#define INF12 1000000000000 //10^12
#define INF9 1000000000 //10^9
#define MOD 1000000007 //10^9+7
using ll=long long;
using pii=pair<ll,ll>;
using vi=vector<int>;

int N,M;

int main() {
    cin >> N >> M;
    bool path[N+1][N+1];
    rep(i,0,N+1) rep(j,0,N+1) path[i][j] = false;
    rep(i,0,M) {
        int a, b;
        cin >> a >> b;
        path[a][b] = true;
        path[b][a] = true;
    } 

    vi nodes;
    rep(i,1,N+1) nodes.pb(i);
    int ans = 0;
    do {
        if(nodes.at(0) != 1) break;
        // for(auto v:nodes) cout << v;
        // cout << endl;
        bool visited[N+1];
        rep(i,0,N+1) visited[i] = false;
        bool ok = true;
        rep(i,0,N-1) {
            int src = nodes.at(i);
            int dst = nodes.at(i+1);
            if(!path[src][dst] || visited[dst]) {
                ok = false;
                break;
            }
            visited[src] = true;
        }
        if(ok) ans++;
    } while (next_permutation(ALL(nodes)));

    cout << ans << endl;
    return 0;
}
