#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    map<char, int> used;
    int M = S[0].size();
    rep(i, M) {
        char t = S[0][i];
        int cnt = used[t];
        cnt++;
        bool ok = true;
        rep2(j, 1, N) {
            string s = S[j];
            int c = 0;
            rep(k, s.size()) {
                if (s[k] == t) c ++;
            }
            if (cnt > c) {
                ok = false;
            }
        }
        if (ok) {
            used[t] = cnt;
        }
    }
    string ans = "";
    for (auto x : used) {
        rep(i, x.second) {
            ans += x.first;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
