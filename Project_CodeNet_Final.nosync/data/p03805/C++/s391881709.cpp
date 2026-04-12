#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph.at(a).emplace_back(b);
        graph.at(b).emplace_back(a);
    }

    int num_paths = 0;
    vector<int> perm;
    for (int i = 0; i < N; i++) {
        perm.emplace_back(i);
    }

    do {
        bool can_traverse = true;
        for (int i = 0; i < N - 1; i++) {
            int start = perm.at(i), end = perm.at(i + 1);
            if (find(graph.at(start).begin(), graph.at(start).end(), end) 
                == graph.at(start).end()) {
                    can_traverse = false;
                    break;
                }
            }
        if (can_traverse) num_paths += 1;
        } while (next_permutation(perm.begin() + 1, perm.end()));
    cout << num_paths << "\n";
}