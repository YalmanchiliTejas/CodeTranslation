#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp fixed << setprecision
#define pb(x) push_back(x)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

const int MAX_N = 1e5;
vector<int> es[MAX_N];
bool used[MAX_N];
int par[MAX_N];
stack<int> s;

void dfs(int now){
    used[now] = true;
    s.push(now);
    for(auto &e: es[now]){
        if(used[e]) continue;
        par[e] = now;
        dfs(e);
    }
}

int main(){
    int N;
    cin >> N;
    rep(i, N-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    fill(used, used+N, false);
    par[0] = -1;
    dfs(0);
    fill(used, used+N, false);
    bool able = true;
    //rep(i, N) cout << par[i] << endl;
    while(!s.empty()){
        int i = s.top();
        s.pop();
        if(used[i]) continue;
        used[i] = true;
        int j = par[i];
        if(j == -1 || used[j]){
            able = false;
            break;
        }
        used[j] = true;
    }
    if(able) cout << "Second" << endl;
    else cout << "First" << endl;
}