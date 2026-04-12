#include <bits/stdc++.h>
#define pii pair<int, int>;
#define ss second
#define ff first
#define all(x) ((x).begin(), (x).end())

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const ll oo = 1 << 31;

vector<int> adj[10];
int n, m;

int dfs(int v, string path){
    path += to_string(v);
    if (path.size() == n) return 1;
    int ans = 0;

    for (auto x: adj[v]){
        if (path.find(to_string(x)) == string::npos){
            ans += dfs(x, path);
        }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << dfs(1, "") << endl;
    return 0;
}