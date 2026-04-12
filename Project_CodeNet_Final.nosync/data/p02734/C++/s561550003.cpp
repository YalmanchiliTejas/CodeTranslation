#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vvll>;
using P = pair<ll, ll>;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll MOD = 998244353;
const ll inf = 1e18;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    ll n, s;
    cin >> n >> s;
    vll a(n);
    REP(i, n) {
        cin >> a[i];
    }
    ll res = 0;
    // dp[i][j][k] := i 文字目まで見て和が j になる場合の数
    // k == 0 -> L も R も決めていない
    // k == 1 -> L を決めたが R を決めていない
    // k == 2 -> L も R も決めた

    // L 確定時, 区間の先頭は (i + 1) 通りから選べる
    // R 確定時, 区間の終端は (n - i) 通りから選べる

    vvvll dp(n + 1, vvll(3030, vll(3)));
    dp[0][0][0] = 1;
    REP(i, n) {
        REP(j, s + 1) {
            // 前の文字までの和からスタート
            REP(k, 3) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j][k] %= MOD;
            }
            if (j + a[i] > s) continue;
            dp[i + 1][j + a[i]][1] += dp[i][j][0] * (i + 1); // L 確定
            dp[i + 1][j + a[i]][1] += dp[i][j][1]; // L 確定済, R 未定
            dp[i + 1][j + a[i]][2] += dp[i][j][0] * (i + 1) * (n - i) + dp[i][j][1] * (n - i); // R 確定
            REP(k, 3) dp[i + 1][j + a[i]][k] %= MOD;
        }
    }
    cout << dp[n][s][2] << endl;
    return 0;
}