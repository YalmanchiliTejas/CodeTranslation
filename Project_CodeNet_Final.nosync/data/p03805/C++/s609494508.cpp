#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), node(n);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < n; i++) node[i] = i+1;
    int ans = 0;
    do {
        bool all = true;
        if (node[0] != 1) break;
        for (int i = 0; i < n-1; i++) {
            bool connected = false;
            for (int j = 0; j < m; j++) {
                if (node[i] < node[i+1] && node[i] == a[j] && node[i+1] == b[j]) connected = true;
                else if (node[i] > node[i+1] && node[i] == b[j] && node[i+1] == a[j]) connected = true;
                if (connected) break;
            }
            if (!connected) {
                all = false;
                break;
            }
        }
        if (all) ans++;
    } while (next_permutation(node.begin(), node.end()));
    cout << ans << endl;
}
