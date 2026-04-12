#include <bits/stdc++.h>
using namespace std;
#define BE(x) x.begin(), x.end()

int f(int n, int c, vector<vector<int>> a, vector<bool> b) {
    if (n == 0)
        return 1;
    int res = 0;
    int s = a[c].size();
    for (int i = 0; i < s; i++) {
        int tmp = a[c][i];
        if (b[tmp]) {
            vector<bool> d = b;
            d[tmp] = false;
            res += f(n-1, tmp, a, d);
        }
    }
    return res;
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<bool> b(n, true);
    b[0] = false;
    cout << f(n-1, 0, a, b) << endl;
}