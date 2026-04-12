#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
const int MX_N = 8, MX_M = 28;
int p[MX_N];
bool connect[MX_N][MX_N] = {};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connect[a - 1][b - 1] = connect[b - 1][a - 1] = true;
    }

    int count = 0;

    do {
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (!connect[p[i]][p[i + 1]]) {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    } while (next_permutation(p + 1, p + n));

    cout << count << endl;

    return 0;
}