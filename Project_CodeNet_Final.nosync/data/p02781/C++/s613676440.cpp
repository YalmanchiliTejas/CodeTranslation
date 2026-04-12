#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;
#pragma endregion

void solve() {
    string n;
    int k;
    cin >> n >> k;
    int len = (int)n.size();

    vector<vector<ll>> dp1(len+1, vector<ll>(4)), dp2(len+1, vector<ll>(4));
    dp1.at(0).at(0) = 1;
    for (int i=0; i<len; i++) {
        int cur = n.at(i) - '0';
        for (int j=0; j<4; j++) {
            dp2.at(i+1).at(j) += dp2.at(i).at(j);
            if (j != 0) dp2.at(i+1).at(j) += dp2.at(i).at(j-1) * 9;
        }
        if (cur == 0) {
            for (int j=0; j<4; j++) {
                dp1.at(i+1).at(j) += dp1.at(i).at(j);
            }
        } else {
            for (int j=1; j<4; j++) {
                dp1.at(i+1).at(j) += dp1.at(i).at(j-1);
            }
            for (int j=0; j<4; j++) {
                dp2.at(i+1).at(j) += dp1.at(i).at(j);
                if (j != 0) dp2.at(i+1).at(j) += dp1.at(i).at(j-1) * (cur - 1);
            }
        }
    }

    cout << dp1.at(len).at(k) + dp2.at(len).at(k) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
