#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = uint64_t;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-6;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    const int MAX = 64;

    int N; cin >> N;
    vi S(N), T(N);
    vvi U(MAX, vi(N)), V(MAX, vi(N));
    REP(i, N) cin >> S[i];
    REP(i, N) cin >> T[i];
    REP(i, N) {
        ll u; cin >> u;
        REP(k, MAX) {
            U[k][i] = u >> k & 1;
        }
    }
    REP(i, N) {
        ll v; cin >> v;
        REP(k, MAX) {
            V[k][i] = v >> k & 1;
        }
    }

    vvll ans(N, vll(N));

    bool valid = true;

    FOR(k, 0, MAX) {
        vvi A(N, vi(N, -1));
        // 行
        REP(i, N) {
            // 積が1
            if (S[i] == 0 and U[k][i] == 1) {
                REP(j, N) {
                    if (A[i][j] == 0) valid = false;
                    A[i][j] = 1;
                }
            }
            // 和が0
            if (S[i] == 1 and U[k][i] == 0) {
                REP(j, N) {
                    if (A[i][j] == 1) valid = false;
                    A[i][j] = 0;
                }
            }
        }
        // 列
        REP(j, N) {
            // 積が1
            if (T[j] == 0 and V[k][j] == 1) {
                REP(i, N) {
                    if (A[i][j] == 0) valid = false;
                    A[i][j] = 1;
                }
            }
            // 和が0
            if (T[j] == 1 and V[k][j] == 0) {
                REP(i, N) {
                    if (A[i][j] == 1) valid = false;
                    A[i][j] = 0;
                }
            }
        }

        REP(i, N) {
            REP(j, N) {
                if (A[i][j] != -1) continue;
                // 両方1(和)
                if (U[k][i] == 1 and V[k][j] == 1) {
                    A[i][j] = 1;
                    continue;
                }
                // 両方0(積)
                if (U[k][i] == 0 and V[k][j] == 0) {
                    A[i][j] = 0;
                    continue;
                }
            }
        }

        // 残ってるのは, 片方に積0が複数個, もう片方に和1が複数個.
        // 両方とも2本以上残っていれば, 市松模様でok

        map<int,int> rows, cols;
        REP(i, N) {
            REP(j, N) {
                if (A[i][j] != -1) continue;
                rows[i] = 1;
                cols[j] = 1;
            }
        }

        if (rows.size() > 1 and cols.size() > 1) {
            vi rs, cs;
            for (auto& tp : rows) rs.push_back(tp.first);
            for (auto& tp : cols) cs.push_back(tp.first);
            REP(i, rs.size()) {
                REP(j, cs.size()) {
                    A[rs[i]][cs[j]] = (i + j) & 1 ? 0 : 1;
                }
            }
        }
        else if (rows.size() == 1) {
            REP(j, N) {
                int cnt0 = 0, cnt1 = 0;
                REP(i, N) {
                    if (A[i][j] == 0) cnt0 = 1;
                    if (A[i][j] == 1) cnt1 = 1;
                }
                REP(i, N) if (A[i][j] == -1) {
                    if (V[k][j] == 0) {
                        if (cnt0 == 0) A[i][j] = 0;
                        else A[i][j] = 1;
                    } else {
                        if (cnt1 == 0) A[i][j] = 1;
                        else A[i][j] = 0;
                    }
                }
            }
        }
        else if (cols.size() == 1) {
            REP(i, N) {
                int cnt0 = 0, cnt1 = 0;
                REP(j, N) {
                    if (A[i][j] == 0) cnt0 = 1;
                    if (A[i][j] == 1) cnt1 = 1;
                }
                REP(j, N) if (A[i][j] == -1) {
                    if (U[k][i] == 0) {
                        if (cnt0 == 0) A[i][j] = 0;
                        else A[i][j] = 1;
                    } else {
                        if (cnt1 == 0) A[i][j] = 1;
                        else A[i][j] = 0;
                    }
                }
            }
        }

        vi rsum(N), rmul(N, 1), csum(N), cmul(N, 1);
        REP(i, N) {
            REP(j, N) {
                rsum[i] |= A[i][j];
                csum[j] |= A[i][j];
                rmul[i] &= A[i][j];
                cmul[j] &= A[i][j];
            }
        }
        REP(i, N) {
            if (S[i] == 0 and rmul[i] != U[k][i]) valid = false;
            if (S[i] == 1 and rsum[i] != U[k][i]) valid = false;
        }
        REP(j, N) {
            if (T[j] == 0 and cmul[j] != V[k][j]) valid = false;
            if (T[j] == 1 and csum[j] != V[k][j]) valid = false;
        }

        REP(i, N) {
            REP(j, N) {
                if (A[i][j]) ans[i][j] |= 1ULL << k;
            }
        }
    }

    if (!valid) {
        cout << -1 << endl;
        return 0;
    }

    REP(i, N) {
        REP(j, N) {
            if (j) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
