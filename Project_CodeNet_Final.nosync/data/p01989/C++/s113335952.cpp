#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REPF(i, a, n) for (int i = a; i < (n); i++)
#define REP(i, n) REPF(i, 0, n)
#define ALL(x) begin(x),end(x)

signed main() {
    string S;
    cin >> S;
    int n = S.size();

    auto validate = [](string s) {
        if (s.size() == 0) return false;
        if (s[0] == '0' && s.size() == 1) return true;
        if (s[0] == '0') return false;
        int num = stoll(s);
        return (0 <= num && num <= 255);
    };

    int ans = 0;
    REPF(i, 1, n) {
        REPF(j, 1, n) {
            REPF(k, 1, n) {
                int l = n - i - j - k;
                if (l <= 0) continue;
                string a = S.substr(0, i);
                string b = S.substr(i, j);
                string c = S.substr(i + j, k);
                string d = S.substr(i + j + k, l);
                if (!validate(a) || !validate(b) || !validate(c) || !validate(d)) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
