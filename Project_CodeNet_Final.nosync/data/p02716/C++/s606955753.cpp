#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int n;
vector<ll> a;

ll dp[200005][2][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for(auto &it : a) {
        cin >> it;
    }
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i][j][k] = -LLINF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) {
                // えらぶ
                if(j == 0) {
                    chmax(dp[i + 1][1][k], dp[i][j][k] + a[i]);
                }
                // えらばない
                if(j == 0 && k < 2) {
                    chmax(dp[i + 1][0][k + 1], dp[i][j][k]);
                } else if(j == 1) {
                    chmax(dp[i + 1][0][k], dp[i][j][k]);
                }
            }
        }
    }
    if(n % 2) {
        cout << max(dp[n][1][2], dp[n][0][1]) << endl;
    } else {
        cout << max(dp[n][0][0], dp[n][1][1]) << endl;
    }
}