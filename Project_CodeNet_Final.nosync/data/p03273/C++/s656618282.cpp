#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
using ll=long long int;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> t(h, vector<char>(w));
    for (auto &v: t) for (auto &e: v) cin >> e;

    vector<int> cnth(h, 0), cntw(w, 0);
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
        if (t[i][j] == '#') {
            cnth[i]++;
            cntw[j]++;
        }
    }

    for (int i = 0; i < h; ++i) {
        if (cnth[i] == 0) continue;
        for (int j = 0; j < w; ++j) {
            if (cntw[j] == 0) continue;
            cout << t[i][j];
        }
        cout << endl;
    }

    return 0;
}
