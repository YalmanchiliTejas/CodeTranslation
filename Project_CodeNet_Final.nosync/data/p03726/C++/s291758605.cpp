#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;

int n;
vector<int> G[100010];
bool f = true;

bool dfs(int now, int pre){
    if(pre != -1 && G[now].size() == 1) return false;
    int cnt = 0;
    rep(i, 0, G[now].size()){
        int next = G[now][i];
        if(next == pre) continue;
        if(!dfs(next, now)) cnt++;
    }
    if(cnt > 1) f = false;
    return cnt;
}

signed main(){
    cin >> n;
    rep(i, 0, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a]. push_back(b);
        G[b]. push_back(a);
    }
    f &= dfs(0, -1);
    cout << (f ? "Second" : "First") << endl;
}