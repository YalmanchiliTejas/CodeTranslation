#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
typedef unsigned int uint;
typedef unsigned long long ull;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;
void yesno(bool ok, string yes = "Yes", string no = "No") {
    if (ok) {
        cout << yes << endl;
    } else {
        cout << no << endl;
    }
}

ll sum[2][200010];
ll dp[2][200010];
ll dpsuf[2][200010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[N];
    REP(i, 0, N) {
        cin >> A[i];
    }
    sum[0][0] = A[0];
    REP(i, 0, 2) {
        REP(j, 1, N) {
            if (j % 2 == i) {
                sum[i][j] = sum[i][j - 1] + A[j];
            } else {
                sum[i][j] = sum[i][j - 1];
            }
        }
    }
    ll ans = 0;
    if (N % 2 == 0) {
        ll len = N / 2;
        dp[0][0] = A[0];
        dp[1][0] = A[1];
        REP(i, 1, len) {
            dp[0][i] = dp[0][i - 1] + A[i * 2];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + A[i * 2 + 1];
        }
        ans = max(dp[0][len - 1], dp[1][len - 1]);
    } else {
        REP(i, 0, N) {
            if (i % 2 == 1) {
                ans += A[i];
            }
        }
        ll len = N / 2;
        dp[0][0] = A[0];
        dp[1][0] = A[1];
        REP(i, 1, len) {
            dp[0][i] = dp[0][i - 1] + A[i * 2];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + A[i * 2 + 1];
        }
        reverse(A, A + N);
        dpsuf[0][0] = A[0];
        dpsuf[1][0] = A[1];
        REP(i, 1, len) {
            dpsuf[0][i] = dpsuf[0][i - 1] + A[i * 2];
            dpsuf[1][i] = max(dpsuf[0][i - 1], dpsuf[1][i - 1]) + A[i * 2 + 1];
        }
        reverse(A, A + N);
        // REP(i, 0, len) {
        //     cout << dp[0][i] << " " << dp[1][i] << endl;
        // }
        // REP(i, 0, len) {
        //     cout << dpsuf[0][i] << " " << dpsuf[1][i] << endl;
        // }
        REP(i, 0, N - 1) {
            ll tmp = 0;
            if (i == 0) {
                tmp = sum[0][N - 1] - A[0];
            } else if (i == N - 2) {
                tmp = sum[0][N - 1] - A[N - 1];
            } else {
                if (i % 2 == 0) {
                    ll prelen = i / 2;
                    tmp += max(dp[0][prelen - 1], dp[1][prelen - 1]);
                    tmp += sum[0][N - 1] - sum[0][i + 1];
                } else {
                    ll suflen = (N - 1 - (i + 1)) / 2;
                    tmp += max(dpsuf[0][suflen - 1], dpsuf[1][suflen - 1]);
                    tmp += sum[0][i - 1];
                }
            }
            // cout << i << " " << tmp << endl;
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
