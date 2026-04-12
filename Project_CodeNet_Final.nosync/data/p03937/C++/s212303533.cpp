// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 100, mod = (int) 0;
string mat[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
        for (int j = 0; j < m; ++j)
            if (mat[i][j] == '#')
                res++;
    }
    if (res != n + m - 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int a = 0, b = 0;
    for (int rep = 0; rep < n + m - 1; ++rep) {
        if (a < n && mat[a + 1][b] == '#') a++;
        if (b < m && mat[a][b + 1] == '#') b++;
    }
    if (a == n - 1 && b == m - 1) {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}
