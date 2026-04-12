// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <bits/stdc++.h>
using namespace std;
using P = pair<double, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> v(H);
    set<int> sh, sw;
    REP(i, H) {
        cin >> v[i];
        bool flag = false;
        REP(j, W) {
            if (v[i][j] == '#') {
                flag = true;
                break;
            }
        }
        if (!flag) {
            sh.insert(i);
        }
    }
    REP(i, W) {
        bool flag = false;
        REP(j, H) {
            if (v[j][i] == '#') {
                flag = true;
                break;
            }
        }
        if (!flag) {
            sw.insert(i);
        }
    }
    REP(i, H) {
        if (sh.count(i) == 0) {
            REP(j, W) {
                if (sw.count(j) == 0) {
                    cout << v[i][j];
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
