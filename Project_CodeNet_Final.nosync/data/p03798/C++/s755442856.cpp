#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string top2[4] = {"SS", "SW", "WS", "WW"};
    for (int k = 0; k < 4; k++) {
        string ans = "";
        ans += top2[k];
        for (int i = 1; i < n; i++) {
            if (s[i] == 'o') {
                if (ans[i] == 'S') {
                    ans += ans[i - 1];
                } else {
                    ans += ans[i - 1] == 'S' ? 'W' : 'S';
                }
            } else {
                if (ans[i] == 'W') {
                    ans += ans[i - 1];
                } else {
                    ans += ans[i - 1] == 'S' ? 'W' : 'S';
                }
            }
        }
        if (ans[0] == ans[n]) {
            if (s[0] == 'o') {
                if (ans[0] == 'S') {
                    if (ans[1] == ans[n - 1]) {
                        cout << ans.substr(0, n);
                        return 0;
                    }
                } else {
                    if (ans[1] != ans[n - 1]) {
                        cout << ans.substr(0, n);
                        return 0;
                    }
                }
            } else {
                if (ans[0] == 'W') {
                    if (ans[1] == ans[n - 1]) {
                        cout << ans.substr(0, n);
                        return 0;
                    }
                } else {
                    if (ans[1] != ans[n - 1]) {
                        cout << ans.substr(0, n);
                        return 0;
                    }
                }
            }
        }

    }

    cout << -1 << endl;
    return 0;
}
