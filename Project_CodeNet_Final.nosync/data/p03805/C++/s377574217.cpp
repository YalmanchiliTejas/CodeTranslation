#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }

    struct Recursive {
        int n;
        ll count = 0;
        void recursive(int index, unsigned int through_flag, const vector<vector<int>> &adj_mat) {
            if (through_flag == (unsigned int)(pow(2, n) - 1)) {
                count += 1;
                return;
            }
            for (int i = 0; i < n; i++) {
                if (adj_mat[index][i] == 1 && (through_flag >> i) % 2 == 0) {
                    recursive(i, through_flag + (1 << i), adj_mat);
                }
            }
        }
    };

    Recursive rec = {.n = N, .count = 0};
    rec.recursive(0, 1, adj);
    cout << rec.count << endl;

    return 0;
}