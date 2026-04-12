#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


#define int ll

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void solve() {
    while (true) {
        int grid[300][300] = {};
        int n;
        cin >> n;
        if (n == 0) return;
        vector<pair<pair<int, int>, pair<int, int>>> inputs;
        map<int, int> zip[2];
        REP(i, n) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a *= 2;
            b *= 2;
            c *= 2;
            d *= 2;

            b++;
            c++;

            inputs.push_back(mp(mp(a, d), mp(c-1, b-1)));
            zip[0][a]++;
            zip[0][c]++;
            zip[0][c - 1]++;

            zip[1][d]++;
            zip[1][b]++;
            zip[1][b - 1]++;
        }
        
        REP(t, 2) {
            int cnt = 1;
            for (auto i = zip[t].begin(); i != zip[t].end(); ++i) {
                i->second = cnt;
                cnt++;
            }
        }

        REP(i, inputs.size()) {
            inputs[i].first = mp(zip[0][inputs[i].first.first], zip[1][inputs[i].first.second]);

            inputs[i].second = mp(zip[0][inputs[i].second.first], zip[1][inputs[i].second.second]);
            for (int q = inputs[i].first.first; q < inputs[i].second.first; ++q) {
                for (int j = inputs[i].first.second; j < inputs[i].second.second; ++j) {
                    grid[q][j] += (1LL << i);
                }
            }
        }
        int ans = 0;
        const int dx[4] = { 1,-1,0,0 };
        queue<pair<int, int>> next;
        REP(i, 200) {
            REP(q, 200) {
                if (grid[i][q] == -1) continue;
                int target = grid[i][q];
                grid[i][q] = -1;
                next.push(mp(i, q));
                ans++;
                while (next.empty() == false) {
                    pair<int, int> now = next.front();
                    next.pop();
                    REP(q, 4) {
                        int x = now.first + dx[q];
                        int y = now.second + dx[3 - q];
                        if (!(x >= 0 && x < 200 && y >= 0 && y < 200)) continue;
                        if (grid[x][y] == target) {
                            grid[x][y] = -1;
                            next.push(mp(x, y));
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}

