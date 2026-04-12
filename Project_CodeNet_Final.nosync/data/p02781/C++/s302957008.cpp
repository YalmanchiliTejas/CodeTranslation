#include<bits/stdc++.h>

using namespace std;

#define int long long

int st[105];
int C[105][105];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int k;
    st[0]= 1;
    for (int i = 1; i <= 4; ++i) st[i] = st[i - 1] * 9;
    for (int i = 0; i <= 100; ++i) C[i][0] = 1;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (j > i) continue;
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    cin >> k;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < s[i] - '0'; ++j) {
            if (j != 0) cnt++;
            if (i == (int)s.size() - 1) {
                if (cnt == k) ans++;
            }
            else {
                if (cnt <= k) {
                    ans += C[(int)s.size() - i - 1][k - cnt] * st[k - cnt];
                }
            }
            if (j != 0) cnt--;
        }
        if (s[i] != '0') cnt++;
    }
    if (cnt == k) ans++;
    cout << ans << '\n';
    return 0;
}

