#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

long long arr[3001];
long long res[3001][3001];

void findRes(int a, int b) {
    if (res[a][b] != 0) return;
    if (a == b) {
        res[a][b] = arr[a];
        return;
    }
    findRes(a, b - 1);
    findRes(a + 1, b);
    res[a][b] = max(arr[b] - res[a][b - 1], arr[a] - res[a + 1][b]);
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    findRes(1, n);
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) cout << res[i][j] << " ";
//        cout << endl;
//    }
    cout << res[1][n];
}

int main()
{
    //rwFile();
    solve();
}
