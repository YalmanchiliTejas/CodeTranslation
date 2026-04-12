#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);


int dfs(int x, int depth, vvi &path, vi &checked){
    int n = checked.size() - 1;
    if (checked[x]) return 0;
    if (depth == n) return 1;
    checked[x] = 1;
    int ans = 0;
    rep2(i, 1, n + 1){
        if (path[x][i]) ans += dfs(i, depth + 1, path, checked);
    }
    checked[x] = 0;
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    vvi path(n + 1, vi(n + 1));
    rep(i, m){
        int a, b;
        cin >> a >> b;
        path[a][b] = 1;
        path[b][a] = 1;
    }
    vi checked(n + 1, false);
    cout << dfs(1, 1, path, checked) << endl;
}
