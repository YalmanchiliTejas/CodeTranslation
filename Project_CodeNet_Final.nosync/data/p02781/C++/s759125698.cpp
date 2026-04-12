#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

#define int long long
#define ll long long
#define double long double
#define pii pair<int, int>
#define vec vector
#define u_map unordered_map
#define u_set unordered_set
#define str string
#define all(el) el.begin(), el.end()
#define allr(el) el.rbegin(), el.rend()
#define sz(el) (int)el.size()
#define f first
#define s second
#define pb push_back
#define in insert
#define mp make_pair
#define endl "\n"
#define forn(i, n) for (int i = 0; i < n; ++i)

inline int maxi(int &a, int b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(int &a, int b) { if (b < a) { a = b; return 1; } return 0; }

inline int maxi(double &a, double b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(double &a, double b) { if (b < a) { a = b; return 1; } return 0; }


const int maxN = 100 + 1, maxK = 3 + 1;

int dp[2][maxN][maxK];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    str s;
    int k;
    cin >> s >> k;
    int n = sz(s);
    dp[1][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int val = 0; val < 10; val++) {
            for (int j = 0; j <= k; j++) {
                int ok = (val > 0);
                if (j - ok < 0) {
                    continue;
                }
                if (val > s[i - 1] - '0') {
                    dp[0][i][j] += dp[0][i - 1][j - ok];
                }
                if (val == s[i - 1] - '0') {
                    dp[0][i][j] += dp[0][i - 1][j - ok];
                    dp[1][i][j] += dp[1][i - 1][j - ok];
                }
                if (val < s[i - 1] - '0') {
                    dp[0][i][j] += dp[0][i - 1][j - ok] + dp[1][i - 1][j - ok];
                }
            }
        }
    }
//    for (int x = 0; x < 2; x++) {
//        for (int i = 0; i <= n; i++) {
//            for (int j = 0; j <= k; j++) {
//                cout << dp[x][i][j] << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

    cout << dp[0][n][k] + dp[1][n][k];

    return 0;
}