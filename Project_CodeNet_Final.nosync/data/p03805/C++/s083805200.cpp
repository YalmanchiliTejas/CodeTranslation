#include <bits/stdc++.h>
using namespace std;

int walk(int current,
         int N,
         int M,
         int visited[10],
         vector<pair<int, int> > edge) {
    int num = 0;
    int all_visited = 1;

    if (visited[current]) return 0;

    visited[current] = 1;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) all_visited = 0;
    }
    if (all_visited) {
        visited[current] = 0;
        return 1;
    }

    for (int i = 0; i < M; ++i) {
        int ai = edge[i].first;
        int bi = edge[i].second;
        if ( ai == current ) {
            num += walk(bi, N, M, visited, edge);
        }
        if ( bi == current ) {
            num += walk(ai, N, M, visited, edge);
        }
    }

    visited[current] = 0;
    return num;
}

int main() {
    int N, M;
    vector<pair<int, int> > edge;
    int visited[10] = {0};

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        edge.push_back(make_pair(a-1, b-1));
    }

    cout << walk(0, N, M, visited, edge) << endl;
}
