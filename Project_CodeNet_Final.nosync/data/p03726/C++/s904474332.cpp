#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int f[100000];
vector <int> v[100000];

int dfs(int x, int y) {
    int c = 0, i;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        c += dfs(v[x][i], x);
    }
    
    if (c > 1) {
        puts("First");
        
        exit(0);
    }
    
    return f[x] = 1 - c;
}

void dfs2(int x, int y, int z) {
    int i;
    
    if (f[x] == 0 && z == 1) {
        puts("First");
        
        exit(0);
    }
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        if (f[x] == 1 || f[v[x][i]] == 1) {
            dfs2(v[x][i], x, 1 - z);
        } else {
            dfs2(v[x][i], x, 0);
        }
    }
}

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(0, -1);
    dfs2(0, -1, 0);
    
    puts("Second");
    
    return 0;
}
