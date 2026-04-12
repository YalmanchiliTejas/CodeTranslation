#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, x) for (int i = x; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 200000;

int stress(string s, int d) {
    int c = 0;

    int x = stoi(s);

    for (int i = 1; i <= x; ++i) {
        int j = i;
        int sum = 0;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        if (sum % d == 0) ++c;
    }

    return c;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 0; test < 1; ++test) {
        /*printf("TEST №%d\n", test);
        string s = to_string((rand() % 100000) + 1);
        int d = rand() % 30 + 1;

        int answ2 = stress(s, d);

        */string s;
        int d;
        cin >> s >> d;

        int n = s.size();

        viii dp(n + 1, vii(d, vi(10, 0)));
        vii p(n + 1, vi(d, 0));

        for (int i = 0; i < 10; ++i) {
            dp[1][i % d][i] = 1;
            p[1][i % d]++;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < d; ++j) {
                for (int k = 0; k < 10; ++k) {
                    dp[i][j][k] = p[i - 1][(j - k + (10 * d)) % d];
                    dp[i][j][k] %= MOD;

                    p[i][j] += dp[i][j][k];
                    p[i][j] %= MOD;
                }
            }
        }

        int answ = 0;

        for (int l = 1; l < n; ++l) {
            for (int k = 1; k < 10; ++k) {
                answ += dp[l][0][k];
                answ %= MOD;
            }
        }

        reverse(all(s));

        for (int i = n - 1, sum = 0; i >= 0; --i) {
            int x = s[i] - '0';

            for (int k = (i == (n - 1)); k < x; ++k) {
                answ += dp[i + 1][((10 * d) - sum) % d][k];
                answ %= MOD;
            }

            sum += x;
            sum %= d;

            if (i == 0 && sum == 0) {
                answ = (answ + 1) % MOD;
            }
        }

        /*if (answ != answ2) {
            printf("TEST FOUND:\n%s %d\nExpected value: %d\nFound:%d", &s, d, answ2, answ);
            break;
        }*/
        cout << answ;
    }
}