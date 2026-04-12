#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void search(vector<vector<int>>& graph, vector<int> visit, int p)
{
    visit[p] = 1;
    int visit_all = true;
    for (int i = 0; i < visit.size(); ++i) {
        if (visit[i] == 0) {
            visit_all = false;
            break;
        }
    }
    if (visit_all) {
        ++ans;
        return;
    }

    for (int i = 0; i < graph[p].size(); ++i) {
        if (graph[p][i] && visit[i] == 0) {
            search(graph, visit, i);
        }
    }
    visit[p] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int p, q;
        cin >> p >> q;
        graph[p-1][q-1] = 1;
        graph[q-1][p-1] = 1;
    }

    vector<int> visit(n);
    search(graph, visit, 0);
    cout << ans << endl;
    return 0;
}