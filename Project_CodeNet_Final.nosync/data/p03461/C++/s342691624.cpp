#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template
bool P[101][101][101]; // X, Y, 1;
struct e {
    int from, to, cost;
};

struct edge {int to; ll cost;};
struct node {int pos; ll cost;};
bool operator < (const node &a, const node &b){
    return a.cost > b.cost;
}

vector<ll> dijkstra(vector<vector<edge>> &G, int root){
    vector<ll> ret(G.size(), inf);
    priority_queue<node> pq;
    pq.push({root, 0});
    while (!pq.empty()) {
        node t = pq.top();
        pq.pop();
        
        if (ret[t.pos] == inf) ret[t.pos] = t.cost;
        else continue;
        
        for (edge e : G[t.pos]) {
            pq.push({e.to, t.cost + e.cost});
        }
    }
    return ret;
}


const int N = 100;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int A, B;
    cin >> A >> B;
    vector<vector<int>> D(A, vector<int> (B));
    rep(i, A) rep(j, B) cin >> D[i][j];
    rep(i, N) rep(j, N) rep(k, 101) P[i][j][k] = 1;
    rep(i, N) rep(j, N) rep(k, 101){
        rep(a, A) rep(b, B){
            if(D[a][b] > (a + 1) * i + (b + 1) * j + k) P[i][j][k] = 0;
        }
    }
    
    vector<e> ret;
    rep(i, N) rep(j, N){
        rep(k, 101) {
            if(P[i][j][k]){
                ret.pb({i, N * 2 + 1 - j, k});
                break;
            }
        }
    }
    
    rep(a, A) rep(b, B){
        vector<vector<edge>> G(N * 2 + 2);
        rep(i, N) G[i].pb({i + 1, a + 1});
        rep(i, N) G[i + N + 1].pb({i + N + 2, b + 1});
        for(auto e: ret) {
            G[e.from].pb({e.to, e.cost});
        }
        
        auto dist = dijkstra(G, 0);
        if(dist[N * 2 + 1] != D[a][b]){
            output("Impossible");
            return 0;
        }
    }
    cout << "Possible" << endl;
    cout << N * 2 + 2 << " " << N * 2 + (int)ret.size() << endl;
    
    rep(i, N){
        cout << i + 1 << " " << i + 2 << " " << "X" << endl;
    }
    rep(i, N){
        cout << i + N + 2 << " " << i + N + 3 << " " << "Y" << endl;
    }
    
    for(auto e: ret) {
        cout << e.from + 1 << " " << e.to + 1 << " " << e.cost << endl;
    }
    cout << 1 << " " << N * 2 + 2 << endl;
    
    return 0;
}
