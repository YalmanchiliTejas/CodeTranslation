#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        vec[i] = i;
    }

    int count = 0;

    do {
        if (vec[0] != 0) continue;
        bool can = true;
        for (int i = 1; i < N; i++) {
            bool ok = false;
            for (int j = 0; j < G[vec[i-1]].size(); j++) {
                if (G[vec[i-1]][j] == vec[i]) ok = true;
            }
            if (!(ok)) can = false;
        }
        if (can) count ++;
    } while(next_permutation(vec.begin(), vec.end()));

    cout << count << endl;
    return 0;
}