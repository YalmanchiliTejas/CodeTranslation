#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
const int maxn = 1e5 + 100;
queue<int> Q;
vector<int> G[maxn];
int f[maxn], col[maxn], in[maxn];
void dfs(int x, int fa){
    f[x] = fa;
    for(auto to : G[x]){
        if(to == fa) continue;
        dfs(to, x);
    }
}
int n, x, y;
int main()
{
    cin>>n;
    for(int i = 0; i < n-1; i++){
        cin>>x>>y;
        in[x]++; in[y]++;
        G[x].pb(y); G[y].pb(x);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++){
        if(in[i] == 1) Q.push(i);
    }
    int label = 0;
    f[1] = 0;
    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        if(col[x]) continue;
        if(col[f[x]]) label = 1;
        else{
            col[f[x]] = 1;
            in[f[f[x]]]--;
            if(in[f[f[x]]] == 0) label = 1;
            if(in[f[f[x]]] == 1 && f[f[x]] != 1) Q.push(f[f[x]]);
        }
    }
    cout<<(label ? "First" : "Second")<<endl;
    return 0;
}
