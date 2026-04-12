#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

char ch;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ch;
            cnt += ch == '#';
        }
    }
    cout << (cnt == (n + m - 1) ? "Possible" : "Impossible");
}
