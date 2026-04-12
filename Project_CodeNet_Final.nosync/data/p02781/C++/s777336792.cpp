#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    int K;
    cin >> K;
    int N = S.size();
    vector<v2ll> dp(N + 1, v2ll(10, vll(3 + 1)));
    vector<v2ll> dp2(N + 1, v2ll(10, vll(3 + 1)));
    dp[0][0][0] = 1;
    dp2[0][0][0] = 1;
    reverse(S.begin(), S.end());
    REP(i, 1, N + 1) {
        REP(j, 0, 10) {
            REP(k, 0, 4) {
                if (j != 0) {
                    if (k == 0) continue;
                    REP(l, 0, 10) {
                        dp[i][j][k] += dp[i - 1][l][k - 1];
                    }
                }
                else {
                    REP(l, 0, 10) {
                        dp[i][j][k] += dp[i - 1][l][k];
                    }
                }
            }
        }

        REP(j, 0, 10) {
            REP(k, 0, 4) {
                if (j < S[i - 1] - 0x30) {
                    if (j != 0) {
                        if (k == 0) continue;
                        REP(l, 0, 10) {
                            dp2[i][j][k] += dp[i - 1][l][k - 1];
                        }
                    }
                    else {
                        REP(l, 0, 10) {
                            dp2[i][j][k] += dp[i - 1][l][k];
                        }
                    }
                }
                else if (j == S[i - 1] - 0x30) {
                    if (j != 0) {
                        if (k == 0) continue;
                        REP(l, 0, 10) {
                            dp2[i][j][k] += dp2[i - 1][l][k - 1];
                        }
                    }
                    else {
                        REP(l, 0, 10) {
                            dp2[i][j][k] += dp2[i - 1][l][k];
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i, 0, 10) 
        ans += dp2[N][i][K];
    //if (S[N - 1] < S[N - 2]) ans++;
    cout << ans << endl;
    return 0;
}