#include <bits/stdc++.h>

std::vector<std::vector<int>> vec;

int n, m, x, y;

void dfs(int edge, std::vector<bool> bool_vec, int& c) {
    if (bool_vec[edge]) {
        return;
    }
    bool_vec[edge] = true;
    bool all_true = true;
    for (int i = 1; i <= n; i++) {
        if (bool_vec[i] == false) {
            all_true = false;
            break;
        }
    }
    if (all_true) {
        c++;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (vec[edge][i] == 1) {
            dfs(i, bool_vec, c);
        }
    }
}




int main() {
    std::cin >> n >> m;
    vec.assign(n+1, std::vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        std::cin >> y >> x;
        vec[y][x] = 1;
        vec[x][y] = 1;
    }
    int c = 0;
    std::vector<bool> bv(n+1, false);
    dfs(1, bv, c);
    std::cout << c << std::endl;
}
