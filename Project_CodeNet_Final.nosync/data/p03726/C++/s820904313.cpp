/// In the name of God
#include <bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define y1 def1
#define X first
#define Y second
#define endl '\n'
#define all(o) o.begin(), o.end()
#define IOS ios::sync_with_stdio(0), cin.tie(0)
const int maxn = 1e5 + 10;
bool dead[maxn];
set<int> adj[maxn], q;
void doo(int v){
    dead[v] = 1;
    for(auto u : adj[v]){
        adj[u].erase(v);
        if(!dead[u] && adj[u].size() == 1) q.insert(u);
    }
}
int main(){
    IOS;
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=0; i<n; i++)
        if(adj[i].size() == 1)
            q.insert(i);
    while(q.size()){
        int v = *q.begin();
        q.erase(v);
        if(dead[v]) continue;
        if(adj[v].size() != 1) continue;
        int u = *adj[v].begin();
        doo(u);
        doo(v);
    }
    for(int i=0; i<n; i++){
        if(!dead[i]){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
}
