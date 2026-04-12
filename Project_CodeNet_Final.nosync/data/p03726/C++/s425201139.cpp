#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;

int n, deg[N], p[N];
vector <int> v[N];

void dfs(int node, int pnode){
    p[node] = pnode;
    for(auto &i : v[node]){
        if(i == pnode) continue;
        dfs(i, node);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++){
        int x, y;
        cin >> x >> y;
        deg[x]++; deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, -1);
    queue <int> leaves;
    for(int i = 2 ; i <= n ; i++){
        if(deg[i] == 1) leaves.push(i);
    }
    while(leaves.size()){
        int cur = leaves.front();
        leaves.pop();
        if(p[cur] == -1) finish("First");
        int k = p[cur];
        for(auto &i : v[k]){
            if(i == p[k]) continue;
            p[i] = -1;
        }
        if(p[k] != -1){
            deg[p[k]]--;
            if(deg[p[k]] <= 1) leaves.push(p[k]);
        }
    }
    cout << "Second" << endl;
}
