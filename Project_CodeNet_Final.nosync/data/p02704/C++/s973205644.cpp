#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include <utility>
#include <tuple>
#include <array>
#include <bitset>
#include <cstdlib>

using int64 = long long;
using uint64 = unsigned long long;

using namespace std;

constexpr int MAX_N = 500;
int n, ss[2][MAX_N], ub[2][MAX_N], ab[MAX_N][MAX_N];
uint64               us[2][MAX_N],  a[MAX_N][MAX_N];

void transpose() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(ab[i][j], ab[j][i]);
        }
    }
}
bool solve(int b) {
    memset(ab, -1, sizeof(ab));
    for (int rc : {0, 1}) {
        // 下からb(0-indexed)ビット目を取り出す
        for (int i = 0; i < n; i++) {
            ub[rc][i] = (us[rc][i] >> b) & 1;
        }
        for (int i = 0; i < n; i++) {
            // ss[rc][i]: { 0 => i行(列)の論理積がus[rc][i], 1 => i行(列)の論理和がus[rc][i] }
            if (ss[rc][i] != ub[rc][i]) {
                // i行(列)に入れる値が確定する
                for (int j = 0; j < n; j++) {
                    if (ab[i][j] == ss[rc][i]) return false;
                    ab[i][j] = ub[rc][i];
                }
            }
        }
        transpose();
    }

    for (int _ = 0; _ < 2; _++) {
        for (int rc : {0, 1}) {
            for (int i = 0; i < n; i++) {
                // ss[rc][i]: { 0 => i行(列)の論理積がus[rc][i], 1 => i行(列)の論理和がus[rc][i] }
                if (ss[rc][i] != ub[rc][i]) continue;
                bool ok = false;
                vector<int> pos;
                for (int j = 0; j < n; j++) {
                    if (ab[i][j] == -1) pos.push_back(j);
                    else if (ab[i][j] == ub[rc][i]) ok = true;
                }
                if (ok) continue;
                if (pos.size() == 0) return false;
                if (pos.size() == 1) ab[i][pos[0]] = ub[rc][i];
            }
            transpose();
        }
    }

    vector<int> rows, cols;
    for (int r = 0; r < n; r++) {
        bool is_filled = true;
        for (int c = 0; c < n; c++) {
            if (ab[r][c] < 0) is_filled = false;
        }
        if (!is_filled) rows.push_back(r);
    }
    for (int c = 0; c < n; c++) {
        bool is_filled = true;
        for (int r = 0; r < n; r++) {
            if (ab[r][c] < 0) is_filled = false;
        }
        if (!is_filled) cols.push_back(c);
    }

    for (int i = 0; i < rows.size(); i++) {
        for (int j = 0; j < cols.size(); j++) {
            ab[rows[i]][cols[j]] = (i + j) % 2;
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            a[r][c] += (1ULL << b) * ab[r][c];
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int rc : {0, 1}) {
        for (int i = 0; i < n; i++) {
            cin >> ss[rc][i];
        }
    }
    for (int rc : {0, 1}) {
        for (int i = 0; i < n; i++) {
            cin >> us[rc][i];
        }
    }

    memset(a, 0, sizeof(a));
    for (int b = 0; b < 64; b++) {
        if (!solve(b)) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << a[r][c] << (c == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

