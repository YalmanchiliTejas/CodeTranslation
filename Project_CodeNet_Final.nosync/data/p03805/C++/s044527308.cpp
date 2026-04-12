#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<int>> edges;

int dfs(int j, int used) {
    if(used == (1 << n) - 1) {
        return 1;
    }
    
    int cnt = 0;
    for(auto& e : edges[j]) {
        if(used & (1 << e)) {
            continue;
        }
        
        cnt += dfs(e, used | (1 << e));
    }
    
    return cnt;
}

int main() {
    std::cin >> n >> m;
    
    int a, b;
    edges.resize(n);
    for(int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        
        --a, --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    std::cout << dfs(0, 1) << std::endl;
}