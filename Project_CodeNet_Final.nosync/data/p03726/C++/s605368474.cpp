#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define N 100005

vector<vector<int> > a(N);
int n;

int dfs(int u, int p){
    int ret = u;
    for(auto v:a[u]){
        if (v==p) continue;
        int rec = dfs(v,u);
        if (rec!=0){
            if (ret!=0){
                ret = 0;
            }
            else{
                cout << "First" << endl;
                exit(0);
            }
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for(int i=1; i<=n-1; i++){
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if (dfs(1,1)==0) cout << "Second" << endl;
    else cout << "First" << endl;
}