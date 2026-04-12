#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

// inf
constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<int> order(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        order[i] = i + 1;
    }

    int ans = 0;
    do {
        int s = 0;
        bool valid = true;
        for (int to : order) {
            if (!graph[s].count(to)) {
                valid = false;
                break;
            }

            s = to;
        }

        ans += valid;
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << endl;
    return 0;
}