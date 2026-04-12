#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



const int MOD = 1E9 + 7;
void _main() {
        string s; cin >> s;
        int d; cin >> d;
        int n = s.size();
        vector<vector<int>> dp(d, vector<int>(2));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
                vector<vector<int>> new_dp(d, vector<int>(2));
                for (int rem = 0; rem < d; rem++) {
                        for (int dig = 0; dig < 10; dig++) {
                                for (bool was: {0, 1}) {
                                        if (!was && dig > s[i] - '0') continue;
                                        (new_dp[(rem + dig) % d][!(!was && dig == s[i] - '0')] += dp[rem][was]) %= MOD;
                                }
                        }
                }
                dp = new_dp;
        }

        dp[0][0] += dp[0][1];
        dp[0][0] -= 1 - MOD;
        dp[0][0] %= MOD;
        cout << dp[0][0];
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}