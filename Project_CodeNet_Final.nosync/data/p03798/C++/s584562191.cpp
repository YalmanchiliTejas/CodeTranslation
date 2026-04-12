#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int mask = 0; mask < 4; ++mask) {
        vector < int > ans(n, -1);
        for (int i = 0; i < 2; ++i)
            ans[i] = int(bool(mask & (1 << i)));
        for (int i = 1; i < n - 1; ++i) {
            if (ans[i]) {
                if (s[i] == 'o')
                    ans[i + 1] = ans[i - 1];
                else 
                    ans[i + 1] = int(!bool(ans[i - 1]));
            }
            else {
                if (s[i] == 'o')
                    ans[i + 1] = int(!bool(ans[i - 1]));
                else 
                    ans[i + 1] = ans[i - 1];
            }
        }
        bool shit = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i]) {
                if (s[i] == 'o') 
                    shit = shit || (ans[(i - 1 + n) % n] != ans[(i + 1) % n]);
                else
                    shit = shit || (ans[(i - 1 + n) % n] == ans[(i + 1) % n]);
            }
            else {
                if (s[i] == 'o') 
                    shit = shit || (ans[(i - 1 + n) % n] == ans[(i + 1) % n]);
                else
                    shit = shit || (ans[(i - 1 + n) % n] != ans[(i + 1) % n]);
            }
        }
        if (!shit) {
            for (int i = 0; i < n; ++i) {
                if (ans[i])
                    cout << 'S';
                else
                    cout << 'W';
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}
