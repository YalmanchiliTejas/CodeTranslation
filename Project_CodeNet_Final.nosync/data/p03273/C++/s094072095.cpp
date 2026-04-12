#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    REP(i, h) REP(j, w) cin >> a[i][j];

    set<int> hr;
    set<int> wr;
    REP(i, h) {
        bool b = true;
        REP(j, w) {
            if (a[i][j] == '#') {
                b = false;
                break;
            }
        }
        if (b) hr.insert(i);
    }
    REP(j, w) {
        bool b = true;
        REP(i, h) {
            if (a[i][j] == '#') {
                b = false;
                break;
            }
        }
        if (b) wr.insert(j);
    }

    REP(i, h) {
        if (hr.count(i)) continue;
        REP(j, w) {
            if (wr.count(j)) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}