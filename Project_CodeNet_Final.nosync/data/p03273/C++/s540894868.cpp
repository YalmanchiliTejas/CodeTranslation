#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    ll H, W;
    cin >> H >> W;
    vector<string> a(H);
    rep(i, H) cin >> a[i];

    vector<string> ans;
    rep(i, H) {
        bool is_h = true;
        rep(j, W) {
            if (a[i][j] != '.') {
                is_h = false;
                break;
            }
        }

        if (!is_h) {
            // cout << a[i] << endl;
            ans.push_back(a[i]);
        }
    }

    vector<ll> ex;
    rep(j, W) {
        bool is_w = true;
        rep(i, ans.size()) {
            if (ans[i][j] != '.') {
                is_w = false;
                break;
            }
        }

        if (is_w) {
            ex.push_back(j);
        }
    }

    rep(i, ans.size()) {
        rep(j, W) {
            bool is_show = true;
            rep(k, ex.size()) {
                if (ex[k] == j) {
                    is_show = false;
                    break;
                }
            }
            if (is_show) cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
