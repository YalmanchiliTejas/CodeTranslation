#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int con[10][10] = {0};
    int ans = 0;
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        con[a-1][b-1] = 1;
        con[b-1][a-1] = 1;
    }

    int node[N];
    for (int i=0; i<N; ++i) node[i] = i;

    bool can = true;
    for (int i=1; i<N; ++i) {
        if (con[node[i]][node[i-1]] == 0) {
            can = false;
            break;
        }
    }
    if (can) ++ans;
    
    while (next_permutation(node+1, node+N)) {
        bool can = true;
        for (int i=1; i<N; ++i) {
            if (con[node[i]][node[i-1]] == 0) {
                can = false;
                break;
            }
        }
        if (can) ++ans;
    }

    cout << ans << endl;

    return 0;
}