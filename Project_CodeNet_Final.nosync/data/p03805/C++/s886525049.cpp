//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;
const int N = 10;
vi adj[N];
bool used[N];
int n;
int ans = 0;
void dfs(int v, int cnt) {
    if (cnt == n) ans++;
    for (auto to : adj[v]) {
        if (used[to]) continue;
        used[to] = true;
        dfs(to, cnt + 1);
        used[to] = false;
    }   
}
void solve(){
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    used[1] = true;
    dfs(1, 1);
    cout << ans;
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}