#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    static vector<int> edges[100000];
    static int deg[100000], removed[100000];
    for(int i=1;i<n;++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        ++deg[a]; ++deg[b];
    }
    queue<int> leaves;
    for(int i=0;i<n;++i) if(deg[i] == 1) leaves.push(i);
    while(!leaves.empty()){
        int l = leaves.front();
        leaves.pop();
        if(removed[l]) continue;
        int p = -1;
        for(int pc: edges[l]) if(removed[pc] == 0){ p = pc; break; }
        if(p == -1){ cout << "First" << endl; return 0; }
        removed[p] = removed[l] = true;
        for(int v: edges[p]){
            if(removed[v]) continue;
            --deg[v];
            if(deg[v] <= 1) leaves.push(v);
        }
    }
    cout << "Second" << endl;
    
    return 0;
}