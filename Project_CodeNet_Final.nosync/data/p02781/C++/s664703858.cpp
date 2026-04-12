#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL dp[105][5][2];
LL comb (int n, int m) {
        if (n < m) return 0;
        if (n == m || m == 0) return 1;
        LL ans = 1;
        for (int i = 0; i < m; ++i) ans *= (n-i);
        for (int i = 1; i <= m; ++i) ans /= i;
        return ans;
}
int main () {
        string s; cin >> s;
        int k; cin >> k;
        int n = s.size();
        assert (s[0] != '0');
        LL ans = 0;
        for (int i = k; i < n; ++i) ans += comb (i-1, k-1); 
        for (int i = 0; i < k; ++i) ans *= 9;
        cerr << "ans = " << ans << endl;
        dp[1][1][1] = 1;
        dp[1][1][0] = s[0]-'0'-1;
        for (int i = 2; i <= n; ++i) {
                for (int j = 1; j <= min(i,k); ++j) {
                        if (s[i-1]=='0') {
                                dp[i][j][1] += dp[i-1][j][1];
                                dp[i][j][0] += 9 * dp[i-1][j-1][0];
                                dp[i][j][0] += dp[i-1][j][0];
                                dp[i][j][0] += dp[i-1][j][1];
                        } else {
                                dp[i][j][1] += dp[i-1][j-1][1];
                                dp[i][j][0] += 9 * dp[i-1][j-1][0];
                                dp[i][j][0] += dp[i-1][j][0];
                                dp[i][j][0] += (s[i-1]-'0'-1) * dp[i-1][j-1][1];
                                dp[i][j][0] += dp[i-1][j][1];
                        }
                }
                /*
                for (int j = 1; j <= k; ++j) printf ("%lld%c",dp[i][j][0]," \n"[j==k]);
                for (int j = 1; j <= k; ++j) printf ("%lld%c",dp[i][j][1]," \n"[j==k]);
                cout << endl;
                */
        }
        int cnt = 0;
        LL res = 0;
        for (int i = 1; i <= n; ++i) {
                LL add = 0;
                if (s[i-1] == '0') {
                        continue;
                } else {
                        add += (s[i-1]-'0'-1) * comb (n-i,k-cnt-1) * (LL) (pow(9,k-cnt-1));
                        if (i != 1) add += comb (n-i,k-cnt) * (LL) (pow(9,k-cnt));
                        //cout << s[i-1] << " " << n-i << " | " << k-cnt-1 << endl;
                        //cout << (s[i-1]-'0'-1) << " , " << comb (n-i,k-cnt-1) << " , " << pow(9,k-cnt-1) << endl;
                        ++cnt;
                }
                res += add;
                //cout << i << " " << res << " " << add << endl;
                if (cnt == k) break;
        }
        int one = 0, nzero = 0;
        for (auto &x : s) one += x=='1', nzero += x!='0';
        res++;
        if ((one == nzero && k > one) || k > nzero) res--;
        cout << ans + res << endl;
        return 0;
}