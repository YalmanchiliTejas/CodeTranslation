#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;
ll const mod = 998244353;
const ll MAX = 300000;
vector<vector<int>>e;
vector<int>used;
int n, m;

int dfs(int a) {
    int res = 0;
    used[a] = 1;
    bool ok = true;
    for (int x : e[a]) {
        if (used[x] == 1)continue;
        ok = false;
        res += dfs(x);
    }
    
    if (ok) {
        rep(i, n) {
            if (used[i] == 0) {
                used[a] = 0;
                return 0;
            }
        }
        used[a] = 0;
        return 1;
    }
    used[a] = 0;
    return res;

}

int main() {
    cin >> n >> m;
    e.resize(n);
    used.resize(n, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int ans = 0;
    used[0] = 1;
    for (int x : e[0]) {
        ans += dfs(x);
    }
    cout << ans << endl;
    return 0;
}