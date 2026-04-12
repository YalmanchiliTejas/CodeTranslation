#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) FORR(i, (n) - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define REPS(c, s) for (char c : s)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REV(c) reverse(ALL(c))
#define sz(v) (int)v.size()
#define endl '\n'
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
 
void solve();
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);
    solve();
    return 0;
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> m(h + 2, vector<char>(w + 2, '.'));
    REP1(i, h) REP1(j, w) cin >> m[i][j];

    vector<int> x{-1, 0, 1, 0};
    vector<int> y{0, 1, 0, -1};

    deque<pair<int, int>> q;
    q.emplace_back(1, 1);
    m[1][1] = '.';
    int r, c;
    while (!q.empty()) {
        tie(r, c) = q.front(); q.pop_front();
        int d = 0;
        REP(k, 4) {
            if (k == 0 || k == 3) {
                if (m[r + x[k]][c + y[k]] == '#') {
                    cout << "Impossible" << endl;
                    return;
                }
            }
            if (m[r + x[k]][c + y[k]] == '#') {
                d++;
                q.emplace_back(r + x[k], c + y[k]);
                m[r + x[k]][c + y[k]] = '.';
            }
        }
        if (d > 1) {
            cout << "Impossible" << endl;
            return;
        }
    }
    cout << "Possible" << endl;
}

