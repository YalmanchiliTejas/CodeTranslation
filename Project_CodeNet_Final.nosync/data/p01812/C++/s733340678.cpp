#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using P = pair<int, int>;
constexpr int INF = 1 << 30;

struct Graph {
    Graph(const int n)
    {
        edge.resize(n);
    }
    void addEdge(const int from, const int to)
    {
        edge[from].push_back(to);
    }
    vector<vector<int>> edge;
};

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> dark_ind(N, -1);
    vector<int> D(M);
    for (int i = 0; i < M; i++) {
        cin >> D[i];
        D[i]--;
        dark_ind[D[i]] = i;
    }
    const int maximum = 1 << M;
    Graph g(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int to;
            cin >> to;
            to--;
            g.addEdge(i, to);
        }
    }

    queue<P> q;
    q.push(make_pair(maximum - 1, 0));
    vector<int> distance(maximum, INF);
    vector<bool> used(maximum, false);
    used[maximum - 1] = true;
    distance[maximum - 1] = 0;
    while (not q.empty()) {
        const P& p = q.front();
        const int state = p.first;
        const int dist = p.second;
        q.pop();
        for (int i = 0; i < K; i++) {
            vector<bool> newdark(M, false);
            for (int j = 0; j < M; j++) {
                if (state & (1 << j)) {
                    const int to = g.edge[D[j]][i];
                    if (dark_ind[to] != -1) {
                        newdark[dark_ind[to]] = true;
                    }
                }
            }
            int newstate = 0;
            for (int j = 0; j < M; j++) {
                if (newdark[j]) {
                    newstate += (1 << j);
                }
            }
            if (not used[newstate]) {
                used[newstate] = true;
                distance[newstate] = dist + 1;
                q.push(make_pair(newstate, dist + 1));
            }
        }
    }
    cout << distance[0] << endl;

    return 0;
}