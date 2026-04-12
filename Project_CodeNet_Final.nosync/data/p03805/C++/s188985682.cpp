#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

bool solve(int n, const vector<vector<bool>>& g, const vector<int>& p) {
    int me = 0;
    for (int i = 0; i < n - 1; i++) {
        if (!g[me][p[i]]) {
            return false;
        }
        me = p[i];
    }
    return true;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1][b - 1] = true;
        g[b - 1][a - 1] = true;
    }

    int cnt = 0;
    vector<int> p(n - 1);
    std::iota(p.begin(), p.end(), 1);
    do {
        if (solve(n, g, p)) {
            cnt++;
        }
    } while (std::next_permutation(p.begin(), p.end()));

    cout << cnt << endl;

    return 0;
}
