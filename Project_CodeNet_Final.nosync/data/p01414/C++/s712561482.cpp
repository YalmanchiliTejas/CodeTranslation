#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}


#define int long long
int dp[(1 << 16)];
int color[4][4];
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> inputs;
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        inputs.push_back(mp(a, b));
    }
    REP(i, 4) {
        string s;
        cin >> s;
        REP(q, 4) {
            if (s[q] == 'R') {
                color[i][q] = 0;
            }
            else if (s[q] == 'B') {
                color[i][q] = 1;
            }
            else if (s[q] == 'G') {
                color[i][q] = 2;
            }
        }
    }
    REP(i, (1 << 16)) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    queue<int> next;
    next.push(0);
    vector<pair<int, int>> itring;
    REP(q, inputs.size()) {
        for (int j = -3; j < 4; ++j) {
            for (int p = -3; p < 4; ++p) {
                REP(t, 3) {
                    int die = (1 << 16) - 1;
                    int adding = 0;
                    for (int x = j; x < j + inputs[q].first; ++x) {
                        for (int y = p; y < p + inputs[q].second; ++y) {
                            if (x >= 0 && x <= 3 && y >= 0 && y <= 3) {
                                die -= (1 << (x * 4 + y));
                                if (color[x][y] == t) {
                                    adding += (1 << (x * 4 + y));
                                }
                            }
                        }
                    }
                    itring.push_back(mp(die, adding));
                }
            }
        }
    }
    while (next.empty() == false) {
        int now = next.front();
        next.pop();
        for (auto x : itring) {
            int hoge = (now & x.first) + x.second;
            if (dp[hoge] == 1e9) {
                dp[hoge] = dp[now] + 1;
                next.push(hoge);
            }
        }
    }
    cout << dp[(1 << 16) - 1] << endl;
}

#undef int
int main() {
    init();
    solve();
}
