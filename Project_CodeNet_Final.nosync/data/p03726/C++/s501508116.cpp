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

vector<vector<int>> G;
vector<int> check;

void dfs(int cur = 0, int par = -1){
    for(auto v: G[cur]){
        if(v != par){
            dfs(v, cur);
        }
    }
    if(par != -1 && !check[cur] && !check[par]){
        check[cur] = 1;
        check[par] = 1;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    G.resize(N);
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    check.assign(N, 0);
    dfs();
    
    bool ok = false;
    rep(i, N) if(!check[i]) ok = true;
    
    if(ok){
        output("First");
    }
    else{
        output("Second");
    }
    
    
    return 0;
}