#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool G[8][8] = {};

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        G[a-1][b-1] = G[b-1][a-1] = true;
    }

    // 全順列を生成
    int linked_count = 0;
    int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    do {
        bool is_linked = true;
        // N = 1のとき i は [0, 0]
        // N = 2のとき i は [0, 0]
        // N = 3のとき i は [0, 1]
        // iは始点となるノード番号-1
        for(int i = 0; i < N-1 && is_linked; ++i) {
            is_linked = G[p[i]][p[i+1]];
        }

        if(is_linked) ++linked_count;
    } while(next_permutation(p + 1, p + N)); // N = 3のとき [p+1, p+2] = [p+1, p+3)

    cout << linked_count << endl;
}
