#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

int n;
const int maxn = 1e5 + 5;
vector<int> g[maxn];

int col[maxn];

bool dfs(int u, int f){
    bool flag = true;
    for(auto v : g[u]){
        if(v == f)
            continue;
        flag &= dfs(v, u);
    }
    if(col[u] == 0){
        col[u] = 1; //black
    }
    if(col[u] == 1){
        if(col[f] != 0)
            return false;
        else{
            col[f] = 2;
        }
    }
    return flag;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    if(n == 2){
        cout << "Second" << endl;
    }else{
        int rt = 0;
        for(int i = 1;i <= n;i++){
            if(g[i].size() > 1)
                rt = i;
        }
        if(dfs(rt, 0)){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }
    return 0;
}
