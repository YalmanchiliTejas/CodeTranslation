#include <stdio.h>
#include <vector>
#include <queue>

int main() {
    int n; scanf("%d", &n);
    std::vector<std::vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d%d", &a, &b);
    
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    std::vector<bool> used(n, false);
    std::queue<int> qu;
    while(true) {
        for(int i = 0; i < n; i++) {
            if(used[i]) continue;

            int count = 0;
            for(auto e: g[i]) {
                if(used[e]) continue;
                count++;
            }
            if(count == 1) qu.push(i);
        }

        if(!qu.size()) break;
        while(!qu.empty()) {
            auto p = qu.front(); qu.pop();

            int B = -1;
            for(auto e: g[p]) {
                if(used[e]) continue;
                B = e;
            }
            if(B == -1) continue;
            used[p] = used[B] = true;
        }
    }

    bool ans = true;
    for(auto v: used) ans &= v;

    if(!ans) printf("First\n");
    else printf("Second\n");
    return 0;
}
