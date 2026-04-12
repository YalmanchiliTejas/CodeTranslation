#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g((size_t) n, vector<int>((size_t) n, 0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
    }

    vector<int> loop;
    for (int i = 0; i < n; ++i) {
        loop.emplace_back(i);
    }

    int ans = 0;
    do{
        if (loop[0] != 0) break;
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            if (g[loop[i]][loop[i+1]] == 0) flag = false;
        }
        if (flag) ++ans;
    }while(next_permutation(loop.begin(), loop.end()));

    cout << ans << endl;
}