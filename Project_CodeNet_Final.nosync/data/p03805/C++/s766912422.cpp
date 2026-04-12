//
// C - One-stroke Path
//

#include <iostream>
#include <vector>

using namespace std;

int N;
int V;
int count_ = 0;
vector<int> G[8];

void dfs(int s, int v) {
    if (v == V) {
        count_++;
        return;
    }
    //
    for (int t : G[s]) {
        if (!(v >> t & 1)) {
            dfs(t, v | 1 << t);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    V = (1 << N) - 1;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, 1);
    cout << count_ << endl;
}