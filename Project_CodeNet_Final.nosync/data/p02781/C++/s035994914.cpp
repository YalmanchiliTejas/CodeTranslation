#include <bits/stdc++.h>
using namespace std;
#define int long long
void run();
signed main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13); run(); }
mt19937 rng(random_device{}());

void run() {
    string n;
    int k;
    cin >> n >> k;
    int m = (int) n.size();
    int ans = 0;
    for (int len = 1; len < m; ++len) {
        if (k == 1)
            ans += 9;
        else if (k == 2) {
            ans += 9 * 9 * (len - 1);
        } else
            ans += 9 * 81 * (len - 1) * (len - 2) / 2;
    }

    for (int a = '1'; a < n[0]; ++a) {
        if (k == 1)
            ++ans;
        else if (k == 2)
            ans += 9 * (m - 1);
        else
            ans += 81 * (m - 1) * (m - 2) / 2;
    }

    cerr << ans << endl;
    if (k != 1) {
        for (int i = 1; i < m; ++i) if (n[i] != '0') {
            for (int a = '1'; a < n[i]; ++a)
                if (k == 2)
                    ++ans;
                else
                    ans += 9 * (m - i - 1);
            
            if (k != 2) {
                for (int j = i + 1; j < m; ++j) if (n[j] != '0') {
                    ans += (n[j] - '0') + (m - j - 1) * 9;
                    break;
                }
                ans += (m - i - 1) * (m - i - 2) / 2 * 81;
                break;
            } else {
                ans += 1 + (m - i - 1) * 9;
                break;
            }
        }
    } else if (n[0] != '0') {
        ++ans;
    }

    cout << ans << endl;
}
