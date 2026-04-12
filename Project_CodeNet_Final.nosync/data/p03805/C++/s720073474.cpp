#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define rea(i, a, b) for (int i = (a); i < (b); i++)
#define reab(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(),(a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
const int MOD = 1000000007;
/* END OF TEMPLATE */

int ans = 0;

void dfs(vvi& g, int N, int depth, int node, vi visited){
    vi v = visited;
    if(find(ALL(visited), node) != visited.end()){
        return;
    }
    if(depth == N){
        ans++;
        return;
    }
    rep(i, N){
        if(g[node][i]){
            v.emplace_back(node);
            dfs(g, N, depth + 1, i, v);
            v.pop_back();
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    if(!M){
        cout << 0 << endl;
        return 0;
    }
    vi a(M), b(M);
    vvi g(N, vi(N, 0));
    rep(i, M){
        cin >> a[i] >> b[i];
        g[a[i]-1][b[i]-1] = 1;
        g[b[i]-1][a[i]-1] = 1;
    }
    vi visited;
    dfs(g, N, 1, 0, visited);
    cout << ans << endl;
}
