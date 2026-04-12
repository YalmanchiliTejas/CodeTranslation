#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;

const ll mod = 1000000007;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

const int AND = 0;
const int OR = 1;

int getb(ull &a, int bt) {
    return (a >> bt) & 1;
}

void setb(ull &a, int bt, int x) {
    a -= (a & (1ULL << bt));
    if (x) a |= (1ULL << bt);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> S(N), T(N);
    vector<ull> U(N), V(N);
    for (int i=0; i<N; ++i) cin >> S[i];
    for (int i=0; i<N; ++i) cin >> T[i];
    for (int i=0; i<N; ++i) cin >> U[i];
    for (int i=0; i<N; ++i) cin >> V[i];

    vector<vector<ull>> a(N, vector<ull>(N, 0));

    for (int bt=0; bt<64; ++bt) {

        // 未確定の行, 列をカウント
        int rowc, colc;
        rowc = colc = N;
        for (int i=0; i<N; ++i) {
            if ((S[i] == AND && getb(U[i], bt) == 1) || (S[i] == OR && getb(U[i], bt) == 0)) rowc --;
            if ((T[i] == AND && getb(V[i], bt) == 1) || (T[i] == OR && getb(V[i], bt) == 0)) colc --;
        }

        vector<vector<int>> b(N, vector<int>(N, -1));
        vector<pair<int,int>> undecided;

        // 確定できる部分を埋める
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                bool b0, b1;
                b0 = b1 = false;
                if (S[i] == AND && getb(U[i], bt) == 1) { b[i][j] = 1; b1 = true; } // AND 1 -> すべて1
                if (S[i] == OR && getb(U[i], bt) == 0) { b[i][j] = 0; b0 = true; } // OR 0 -> すべて0
                if (T[j] == AND && getb(V[j], bt) == 1) { b[i][j] = 1; b1 = true; } // AND 1 -> すべて1
                if (T[j] == OR && getb(V[j], bt) == 0) { b[i][j] = 0; b0 = true; } // OR 0 -> すべて0
                if (b0 && b1) {
                    // debug("bad 1");
                    cout << -1 << endl;
                    return 0;
                } else if (!b0 && !b1) {
                    undecided.emplace_back(i, j);
                }
            }
        }

        // 未確定の部分が 2 * 2 -> 市松, それ以外は貪欲
        if (2 <= rowc && 2 <= colc) {
            int t = 0, i, j;
            for (auto p: undecided) {
                tie(i, j) = p;
                if (colc % 2) b[i][j] = t % 2;
                else b[i][j] = (t + t / colc) % 2;
                t ++;
            }
        } else if (rowc && colc) {
            if (rowc < colc) {
                swap(S, T); swap(U, V);
                for (int i=0; i<N; ++i) for (int j=i+1; j<N; ++j) swap(b[i][j], b[j][i]);
                for (auto &p: undecided) swap(p.first, p.second);
            }

            vector<vector<bool>> has(N, vector<bool>(2, false)); // has[i][j] := i行目にjがあるか
            for (int i=0; i<N; ++i) {
                for (int j=0; j<2; ++j) {
                    has[i][j] = find(b[i].begin(), b[i].end(), j) != b[i].end();
                }
            }
            for (auto p: undecided) {
                int i, j;
                tie(i, j) = p;
                if (S[i] == AND && getb(U[i], bt) == 0) { // AND 0 -> 1つ以上0
                    if ( ! has[i][0] || getb(V[j], bt) == 0) {
                        b[i][j] = 0;
                        has[i][0] = true;
                    } else {
                        b[i][j] = 1;
                        has[i][1] = true;
                    }
                } else { // OR 1 -> 1つ以上1
                    if ( ! has[i][1] || getb(V[j], bt) == 1) {
                        b[i][j] = 1;
                        has[i][1] = true;
                    } else {
                        b[i][j] = 0;
                        has[i][0] = true;
                    }
                }
            }

            if (rowc < colc) {
                swap(S, T); swap(U, V);
                for (int i=0; i<N; ++i) for (int j=i+1; j<N; ++j) swap(b[i][j], b[j][i]);
                for (auto &p: undecided) swap(p.first, p.second);
            }
        }

        // check
        vector<int> row_and(N, 1), row_or(N, 0), col_and(N, 1), col_or(N, 0);
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                row_and[i] &= b[i][j];
                row_or[i] |= b[i][j];
                col_and[j] &= b[i][j];
                col_or[j] |= b[i][j];
            }
        }
        for (int i=0; i<N; ++i) {
            if ((S[i] == AND && getb(U[i], bt) != row_and[i])
            || (S[i] == OR && getb(U[i], bt) != row_or[i])
            || (T[i] == AND && getb(V[i], bt) != col_and[i])
            || (T[i] == OR && getb(V[i], bt) != col_or[i])) {
                // debug("bad 2");
                cout << -1 << endl;
                return 0;
            }
        }

        // apply
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                setb(a[i][j], bt, b[i][j]);
            }
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cout << (j == 0 ? "" : " ") << a[i][j];
        }
        cout << endl;
    }

    return 0;
}