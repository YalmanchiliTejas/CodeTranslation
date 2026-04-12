#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int n, m;
int a[28], b[28];
int t[8] = {};
int k[8] = {};
int e[8][8] = {};

int f(int v, int d) {
    if (t[v]) return 0; else t[v] = 1;
    if (d == 0) {
        t[v] = 0;
        return 1;
    }
    int s = 0;
    for (int i = 0; i < k[v]; i++) {
        s += f(e[v][i], d - 1);
    }
    t[v] = 0;
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        int v0 = a[i] - 1, v1 = b[i] - 1;
        e[v0][k[v0]++] = v1;
        e[v1][k[v1]++] = v0;
    }
    cout << f(0, n - 1) << endl;
    return 0;
}
