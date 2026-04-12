#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> E;

bool try_path(vector<int> A) {
    bool can_go = true;
    for (int i = 0; i < A.size() - 1; i++) {
        int p_node = A.at(i);
        int n_node = A.at(i + 1);
        vector<int> adj = E.at(p_node);
        if (adj.end() == find(adj.begin(), adj.end(), n_node)) {
            can_go = false;
            break;
        }
    }
    return can_go;
}

int main() {
    cin >> N >> M;
    E.resize(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E.at(a).push_back(b);
        E.at(b).push_back(a);
    }
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A.at(i) = i;
    }

    int num_path = 0;
    do {
        if (try_path(A)) {
            num_path++;
        }
    } while(next_permutation(A.begin() + 1, A.end()));

    cout << num_path << endl;
}