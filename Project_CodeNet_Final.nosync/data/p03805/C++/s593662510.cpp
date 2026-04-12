#include <iostream>
#include <numeric>
#include <cstring>
using namespace std;

int adj[8][8];
int N, M;
int answer;

void search(int src, int visited[]) {
    // cout << "search(" << src << ", [";
    // for (int i = 1; i <= N; i++) {
    //     cout << visited[i] << ", ";
    // }
    // cout << "])" << endl;
    int newVisited[9];
    if (accumulate(visited, visited + 9, 0) == N) {
        // cout << "finish!" << endl;
        answer++;
    } else {
        for (int dst = 1; dst <= N; dst++) {
            if (adj[src][dst] && !visited[dst]) {
                memcpy(newVisited, visited, sizeof(int) * 9);
                newVisited[dst] = 1;
                search(dst, newVisited);
            }
        }
    }
}

int main() {
    memset(adj, 0, sizeof(adj));
    answer = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int visited[9] = {0, 1, 0, 0, 0, 0, 0, 0, 0};
    search(1, visited);

    cout << answer << endl;
}
