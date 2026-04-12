#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool search_edge(int a, int b, vector<pair<int, int>> edge) {
    bool ans = false;
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i] == make_pair(a, b) || edge[i] == make_pair(b, a)) {
            ans = true;
            break;
        }
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edge(M);
    for (int i = 0; i < M; i++) cin >> edge[i].first >> edge[i].second;

    vector<int> node(N);
    for (int i = 0; i < N; i++) {
        node[i] = i + 1;
    }

    int ans = 0;
    do {
        bool can = true;
        for (int i = 0; i < N - 1; i++) {
            if (!search_edge(node[i], node[i + 1], edge)) {
                can = false;
                break;
            }
        }
        if (can) ans++;
    } while (next_permutation(node.begin() + 1, node.end()));

    cout << ans << endl;
    return 0;
}