#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool Solve() {
    int n;
    string s;

    cin >> n >> s;
    vector<char> sw(n, 3); // S: 0, W: 1
    for (int t1 = 0; t1 <= 1; ++t1) {
        for (int t2 = 0; t2 <= 1; ++t2) {
            sw[0] = t1; sw[1] = t2;

            if (t1 == 0) sw[n - 1] = (s[0] == 'o' ? sw[1] : 1 - sw[1]);
            else sw[n - 1] = (s[0] == 'x' ? sw[1] : 1 - sw[1]);

            for (int i = 1; i < n - 2; ++i) {
                if (sw[i] == 0) sw[i + 1] = (s[i] == 'o' ? sw[i - 1] : 1 - sw[i - 1]);
                else sw[i + 1] = (s[i] == 'x' ? sw[i - 1] : 1 - sw[i - 1]);
            }

            if (sw[n - 2] == 0) { // 羊
                if ((s[n - 2] == 'o' && sw[n - 1] != sw[n - 3]) ||
                    (s[n - 1] == 'x' && sw[n - 1] == sw[n - 3])) continue;
            }
            else { // 狼
                if ((s[n - 2] == 'x' && sw[n - 1] != sw[n - 3]) ||
                    (s[n - 2] == 'o' && sw[n - 1] == sw[n - 3])) continue;
            }

            if (sw[n - 1] == 0) { // 羊
                if ((s[n - 1] == 'o' && sw[0] != sw[n - 2]) ||
                    (s[n - 1] == 'x' && sw[0] == sw[n - 2])) continue;
            }
            else { // 狼
                if ((s[n - 1] == 'x' && sw[0] != sw[n - 2]) ||
                    (s[n - 1] == 'o' && sw[0] == sw[n - 2])) continue;
            }

            for (int i = 0; i < n; ++i) cout << (sw[i] == 0 ? 'S' : 'W');
            cout << endl;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    if (!Solve()) cout << -1 << endl;

    return 0;
}
