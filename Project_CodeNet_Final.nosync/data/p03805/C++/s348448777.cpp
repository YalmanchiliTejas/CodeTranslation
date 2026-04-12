#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

bool v[10];
int ans;
int n,m;
vector<vector<int>> g;

void dfs(int from){
    bool ok = 1;
    rep(i,n){
        if(v[i]);
        else ok = 0;
    }
    if(ok){
        ans++;
        return;
    }
    for(auto x:g[from]){
        if(v[x])continue;
        v[x] = 1;
        dfs(x);
        v[x] = 0;
    }
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> n >> m;
    g.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    v[0] = 1;
    dfs(0);
    v[0] = 0;
    cout << ans << endl;
}