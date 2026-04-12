#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> g(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1][y - 1] = true;
        g[y - 1][x - 1] = true;
    }

    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        order[i] = i;
    }
    int count = 0;
    do {
        bool ok = true;
        for (int i = 1; i < N; i++) {
          if (!g[order[i - 1]][order[i]]) {
              ok = false;
              break;
          }
        }
        if (ok) {
            count++;
        }
    } while (next_permutation(order.begin() + 1, order.end()));
    cout << count << endl;
    return 0;
}

