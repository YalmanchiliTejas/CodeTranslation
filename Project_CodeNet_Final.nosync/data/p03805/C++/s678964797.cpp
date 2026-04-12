#include <iostream>
#include <vector>

const int N = 10;

int n, m;
std::vector<int> g[N];
bool used[N];
int cnt;

void dfs(int k){
    bool flg = true;
    for(int i = 0; i < n; ++i)if(!used[i])flg = false;
    if(flg){
        ++cnt;
        return;
    }
    
    for(int i = 0; i < g[k].size(); ++i){
        int to = g[k][i];
        if(used[to])continue;
        used[to] = true;
        dfs(to);
        used[to] = false;
    }
}

int main(){
    std::cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    used[0] = true;
    dfs(0);
    std::cout << cnt << std::endl;
    
    return 0;
}