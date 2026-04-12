#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e6 + 7;
vector <int> g[N];
bool dfs(int u, int p) {
    int cnt = 0;
    for (int v : g[u])
        if (v != p)
            cnt += dfs(v, u);
    if (cnt > 1) {
        cout << "First" << endl;
        exit(0);
    }   
    return !cnt;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif  
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }
    if (!dfs(1, 1))
        cout << "Second";
    else
        cout << "First";
    cout << endl;            
}   