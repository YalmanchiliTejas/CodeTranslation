#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<int(int, int)> solve = [&](int v, int fa) {
        int s = 0;
        for (int u : G[v]) if (u ^ fa) {
            s += solve(u, v);
        }
        return s >= 2 ? s : s ^ 1;
    };
    printf("%s\n", solve(1, 0) ? "First" : "Second");
    return 0;
}