#include <iostream>
#include <vector>

int n, m, a, b;
std::vector<int> v[9];
bool used[9];

int dfs(int x, int cnt) {
    used[x] = true;
    int ret = 0;
    if (cnt == n) {
        used[x] = false;
        return 1;
    }

    for (int i = 0; i < v[x].size(); ++i) {
        if (!used[v[x][i]]) {
            ret += dfs(v[x][i], cnt+1);
        }
    }
    used[x] = false;
    return ret;
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    int ans;
    ans = dfs(0, 1);

    std::cout << ans << std::endl;

    return 0;
}
