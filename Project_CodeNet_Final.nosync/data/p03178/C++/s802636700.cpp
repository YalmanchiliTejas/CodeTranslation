#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



const int MOD = 1E9 + 7;
ll dp[200][2][10009];
ll solve(int sum, bool border, int pos, const string& s, const int& d) {
        auto& DP = dp[sum][border][pos];
        if (DP >= 0) return DP;
        if (pos == s.size()) return !sum;
        ll cnt = 0;
        int lim = 9;
        if (border) lim = s[pos] - '0';
        for (int dig = 0; dig <= lim; dig++) {
                cnt += solve((sum  + dig) % d, border && dig == lim, pos + 1, s, d);
                cnt %= MOD;
        }

        return DP = cnt;
}



void _main() {
        string s; cin >> s;
        int d; cin >> d;
        memset(dp, -1, sizeof dp);
        cout << (solve(0, 1, 0, s, d) - 1 + MOD) % MOD  << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}