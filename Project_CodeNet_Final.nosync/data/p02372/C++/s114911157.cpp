#include<bits/stdc++.h>
#define N 10010
using namespace std;
struct no{
    int to, cost;
};
vector<no> G[N];
int n;
int X[N], Y[N];
int d[N], used[N];
void init(){
    memset(d, 0, sizeof(d));
    fill(used, used+N, false);
}
void dfs(int u){
    used[u] = true;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i].to;
        if(!used[v]){
            d[v] = d[u] + G[u][i].cost;
            dfs(v);
        }
    }
}
int findMax(int a[]){
    int maxi = 0, maxv = 0;
    for(int i = 0; i < n; i++) if(a[i] > maxv) {maxv = a[i]; maxi = i;}
    return maxi;
}
void solve(){
    init();
    dfs(0);
    int x = findMax(d);

    init();
    dfs(x);
    for(int i = 0; i < n; i++) X[i] = d[i];
    int y = findMax(d);

    init();
    dfs(y);
    for(int i = 0; i < n; i++) Y[i] = d[i];
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    solve();
    for(int i = 0; i < n; i++){
        printf("%d\n", max(X[i], Y[i]));
    }
    return 0;
}
