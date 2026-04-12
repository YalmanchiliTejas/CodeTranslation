#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl
#define DOUBLE(d) cout << fixed << setprecision(15) << (d) << endl
#define FAIL(x) { cout << (-1) << endl; return; }

const int MAX = 505;
const int DIGIT = 64;

int N;
bool S[MAX], T[MAX];
uint64_t U[MAX], V[MAX];

void solve() {
    vector<vector<uint64_t>> ans(N, vector<uint64_t>(N));
    REP (k, DIGIT) {
        vector<vector<int>> tmp(N, vector<int>(N, -1));
        // 0/1の行/列があるか
        bool row_all_white = false, row_all_black = false, column_all_white = false, column_all_black = false;
        int row_exists_white = 0, row_exists_black = 0, column_exists_white = 0, column_exists_black = 0;

        REP (i, N) {
            // 1でないといけない
            if (S[i] == 0 && (U[i]&1) == 1) {
                REP (j, N) {
                    if (tmp[i][j] == 0) FAIL(1)
                    tmp[i][j] = 1;
                    row_all_black = true;
                }
            }

            // 0出ないといけない
            if (S[i] == 1 && (U[i]&1) == 0) {
                REP (j, N) {
                    if (tmp[i][j] == 1) FAIL(2)
                    tmp[i][j] = 0;
                    row_all_white = true;
                }
            }

            // 1でないといけない
            if (T[i] == 0 && (V[i]&1) == 1) {
                REP (j, N) {
                    if (tmp[j][i] == 0) FAIL(3)
                    tmp[j][i] = 1;
                    column_all_black = true;
                }
            }

            // 0出ないといけない
            if (T[i] == 1 && (V[i]&1) == 0) {
                REP (j, N) {
                    if (tmp[j][i] == 1) FAIL(4)
                    tmp[j][i] = 0;
                    column_all_white = true;
                }
            }
        }

        REP (i, N) {
            if (S[i] == 0 && (U[i]&1) == 0) row_exists_white++;
            if (S[i] == 1 && (U[i]&1) == 1) row_exists_black++;
            if (T[i] == 0 && (V[i]&1) == 0) column_exists_white++;
            if (T[i] == 1 && (V[i]&1) == 1) column_exists_black++;
        }

        // 全黒/全白でいいならそうする
        if (row_exists_white == 0 && column_exists_white == 0 && !column_all_white && !row_all_white) {
            REP (i, N) REP (j, N) tmp[i][j] = 1;
        }
        else if (row_exists_black == 0 && column_exists_black == 0 && !column_all_black && !row_all_black) {
            REP (i, N) REP (j, N) tmp[i][j] = 0;
        }

        // 行列に黒/白を受けれるやつがいるなら、それ以外を反対の色にする
        else if ((row_exists_white > 0 || row_all_white) && (column_exists_white > 0 || column_all_white)) {
            REP (i, N) REP (j, N) if (tmp[i][j] == -1) {
                tmp[i][j] = ((U[i]&1) == 0 && (V[j]&1) == 0) ? 0 : 1;
            }
        }
        else if ((row_exists_black > 0 || row_all_black) && (column_exists_black > 0 || column_all_black)) {
            REP (i, N) REP (j, N) if (tmp[i][j] == -1) {
                tmp[i][j] = ((U[i]&1) == 1 && (V[j]&1) == 1) ? 1 : 0;
            }
        }

        // この時点で、行列で扱っている色は[黒,白]か[白,黒]だけになっている
        else if (row_all_black || row_exists_black > 0) {
            if (row_exists_black == 0 && column_exists_white == 0) {}
            else if (row_exists_black == 0 && column_exists_white > 0) { FAIL(5) }
            else if (row_exists_black == 1 || column_exists_white == 1) { FAIL(6) }
            else {
                vi rs, cs;
                REP (i, N) if (S[i] == 1) rs.push_back(i);
                REP (i, N) if (T[i] == 0) cs.push_back(i);
                REP (i_r, rs.size()) REP (i_c, cs.size()) {
                    int r = rs[i_r], c = cs[i_c];
                    tmp[r][c] = ((i_r + i_c) & 1) ? 1 : 0;
                }
            }
        }   
        else if (row_all_white || row_exists_white > 0) {
            if (row_exists_white == 0 && column_exists_black == 0) {}
            else if (row_exists_white == 0 && column_exists_black > 0) { FAIL(7) }
            else if (row_exists_white == 1 || column_exists_black == 1) { FAIL(8) }
            else {
                vi rs, cs;
                REP (i, N) if (S[i] == 0) rs.push_back(i);
                REP (i, N) if (T[i] == 1) cs.push_back(i);
                REP (i_r, rs.size()) REP (i_c, cs.size()) {
                    int r = rs[i_r], c = cs[i_c];
                    tmp[r][c] = ((i_r + i_c) & 1) ? 1 : 0;
                }
            }
        }

        // ここまでで網羅されているのでたどり着かない
        else assert(false);


        // あまりがあったら0で塗る
        REP (i, N) REP (j, N) if (tmp[i][j] == -1) tmp[i][j] = 0;

        // チェック
        REP (i, N) {
            int s = 0;
            REP (j, N) s += tmp[i][j];
            if (S[i] == 0 && (U[i]&1) == 1 && s != N) { FAIL(9) }
            if (S[i] == 0 && (U[i]&1) == 0 && s == N) { FAIL(10) }
            if (S[i] == 1 && (U[i]&1) == 1 && s == 0) { FAIL(11) }
            if (S[i] == 1 && (U[i]&1) == 0 && s != 0) { FAIL(12) }

            s = 0;
            REP (j, N) s += tmp[j][i];
            if (T[i] == 0 && (V[i]&1) == 1 && s != N) { FAIL(13) }
            if (T[i] == 0 && (V[i]&1) == 0 && s == N) { FAIL(14) }
            if (T[i] == 1 && (V[i]&1) == 1 && s == 0) { FAIL(15) }
            if (T[i] == 1 && (V[i]&1) == 0 && s != 0) { FAIL(16) }
        }

        REP (i, N) REP (j, N) ans[i][j] |= (1ull * tmp[i][j]) << k;
        REP (i, N) {
            U[i] >>= 1;
            V[i] >>= 1;
        }
    }

    REP (i, N) {
        REP (j, N) cout << ans[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> N;
    REP (i, N) cin >> S[i];
    REP (i, N) cin >> T[i];
    REP (i, N) cin >> U[i];
    REP (i, N) cin >> V[i];
    solve();
}