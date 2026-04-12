#include <iostream>
#include <vector>
using namespace std;

const int MAX = 9;
bool connect[MAX][MAX];
bool visit[MAX];
int n, m;

int dfs(int node) {
        bool all_visit = true;
        for (int i=1; i<=n; ++i) {
                if (visit[i]==false) {
                        all_visit = false;
                        break;
                }
        }
        if (all_visit) return 1;

        int ret = 0;
        for (int i=1; i<=n; ++i) {
                if (connect[node][i] && !visit[i]) {
                        visit[i] = true;
                        ret += dfs(i);
                        visit[i] = false;
                }
        }
        return ret;
}

int main() {
        cin >> n >> m;
        for (int i=0; i<m; ++i) {
                int a, b;
                cin >> a >> b;
                connect[a][b] = connect[b][a] = true;
        }
        visit[1] = true;
        cout << dfs(1) << endl;
        return 0;
}
