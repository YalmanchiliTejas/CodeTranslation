#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
ll dp1[101][4];
ll dp2[101][4];
int main() {
    int K;
    string N;
    cin >> N >> K;
    // cout << "wo" << endl;
    int keta = N.length();
    // cout << keta << endl;
    // vector<vector<ll>> dp1(keta, vector<ll>(K + 1, 0LL));
    // vector<vector<ll>> dp2(keta, vector<ll>(K + 1, 0LL));
    // cout << "memory allocated" << endl;
    // dp1 inactive
    // dp2 active
    dp1[0][0] = 1LL;
    // cout << "e" << endl;
    dp1[0][1] = N[0] - '0' - 1;
    // cout << dp1[0][1] << endl;
    dp2[0][1] = 1;
    dp2[0][0] = 0;
    for(int i = 1; i < keta; i++) {
        for(int j = 0; j <= K; j++) {
            // jは0出ない数
            if(j == 0) {
                dp1[i][j] = dp1[i - 1][j];
            } else {
                dp1[i][j] = 9 * dp1[i - 1][j - 1] + dp1[i - 1][j];
                if(N[i] != '0') {
                    dp1[i][j] +=
                        (N[i] - '0' - 1) * dp2[i - 1][j - 1] + dp2[i - 1][j];
                }
                if(j != 0) {
                    if(N[i] == '0') {
                        dp2[i][j] = dp2[i - 1][j];
                    } else {
                        dp2[i][j] = dp2[i - 1][j - 1];
                    }
                }
            }
        }
    }
    // cout << dp2[keta - 1][K] << " : " << dp1[keta - 1][K] << endl;
    cout << dp2[keta - 1][K] + dp1[keta - 1][K] << endl;
    return 0;
}