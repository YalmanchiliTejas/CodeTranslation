// One-stroke Path

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int n, m;
int cnt;

typedef struct NODE {
    vector<int> adj;
} Node;

Node *nodes;
char *visited;

int calc() {
    int sum = 0;
    for (int j = 1; j < n + 1; j++) {
        sum += visited[j];
    }
    return sum;
}

void walk(int id) {
    if (calc() == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < nodes[id].adj.size(); i++) {
        int next = nodes[id].adj[i];

        // 既に訪れていた場合
        if (visited[next] == 1) {
            continue;
        } else {
            visited[next] = 1;
            walk(next);
            visited[next] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    cnt = 0;

    nodes = (Node *)malloc(sizeof(Node) * (n+1));
    visited = (char *)malloc(sizeof(char) * (n+1));

    for (int i = 0; i <= n; i++) {
        visited[i] = 0;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        nodes[a].adj.push_back(b);
        nodes[b].adj.push_back(a);
    }

    visited[1] = 1;
    walk(1);

    cout << cnt << endl;

    return 0;
}
