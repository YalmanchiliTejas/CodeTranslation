#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;
const ll mod = 1000000007;

int n, m;
string s;

ll dp[max_n];
ll pr[max_n];
ll dp2[max_n];

ll solve_allr() {
    ll ans = 1;
    dp[1] = 1;
    dp[2] = 0;
    ll sum = dp[1];
    for (int i = 3; i < max_n; ++i) {
        dp[i] = sum;
        sum += dp[i - 1];
        sum %= mod;
    }
    for (int len = 1; len < n; ++len) {
        ans += dp[n - len] * (len + 1);
        ans %= mod;
    }
    return ans;
}

ll solve(int L) {
    int L1 = L / 2;
    pr[1] = 1;
    dp2[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        dp2[i] = (pr[i - 1] - pr[max(1, i - L1 - 1) - 1] + 2 * mod) % mod;
        pr[i] = pr[i - 1] + dp2[i];
        pr[i] %= mod;
    }
    dp[1] = 1;
    for (int i = 3; i < max_n; i += 2) {
        dp[i] = dp2[i / 2 + 1];
    }
    ll ans = 0;
    for (int len = 1; len <= min(L, n - 1); len += 2) {
        ans += dp[n - len] * (len + 1);
        ans %= mod;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> s;
    if (s[0] == 'B') {
        for (int i = 0; i < s.size(); ++i) {
            s[i] = (s[i] == 'B' ? 'R' : 'B');
        }
    }
    bool allr = 1;
    for (char c : s) {
        if (c == 'B') {
            allr = 0;
            break;
        }
    }
    if (allr) {
        cout << solve_allr() << endl;
        return 0;
    }
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    while (s.back() == 'R') {
        s.pop_back();
    }
    int L = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'B') {
            break;
        } else {
            ++L;
        }
    }
    if (L % 2 == 0) {
        ++L;
    }
    int len = 0;
    for (int i = L; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            ++len;
        } else {
            if (s[i] == 'B' && len % 2 == 1) {
                L = min(L, len);
            }
            len = 1;
        }
    }
    cout << solve(L) << endl;
    return 0;
}

// think 2:06
