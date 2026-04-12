#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) begin(x), end(x)
#define uniq(x) (x).erase(unique(all(x)), end(x))
#define bit(n) (1LL << (n))
#define cdiv(a, b) (((a) - 1) / (b) + 1)
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr long double PI = 3.1415926535897932384626433832795028L;
constexpr int DY[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int DX[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

using ull = unsigned long long;
int N;
int S[550], T[550];
ull U[550], V[550];
int u[550], v[550];
ull ans[550][550];
int tmp[550][550];
signed main() {
    cin >> N;
    rep(i, N) { cin >> S[i]; }
    rep(i, N) { cin >> T[i]; }
    rep(i, N) { cin >> U[i]; }
    rep(i, N) { cin >> V[i]; }
    rep(p, 64) {
        //準備
        rep(j, N) {
            rep(k, N) {
                tmp[j][k] = -1;
            }
        }
        rep(j, N) { u[j] = (U[j] >> p) & 1; }
        rep(j, N) { v[j] = (V[j] >> p) & 1; }

        //本番
        int H = N;
        rep(i, N) {
            if (S[i] == u[i]) { continue; }
            H--;
            rep(j, N) { tmp[i][j] = u[i]; }
        }

        int W = N;
        rep(i, N) {
            if (T[i] == v[i]) { continue; }
            W--;
            rep(j, N) {
                if (tmp[j][i] != -1 && tmp[j][i] != v[i]) { fin(-1); }
                tmp[j][i] = v[i];
            }
        }

        if (H > 1 && W > 1) {
            int cur = 0;
            rep(i, N) {
                if (S[i] != u[i]) { continue; }
                int ccur = cur;
                rep(j, N) {
                    if (T[j] != v[j]) { continue; }
                    tmp[i][j] = ccur;
                    ccur ^= 1;
                }
                cur ^= 1;
            }
        } else if (H == 0) {
            rep(i, N) {
                bool flag = false;
                rep(j, N) {
                    flag |= tmp[j][i] == v[i];
                }
                if (!flag) { fin(-1); }
            }
        } else if (W == 0) {
            rep(i, N) {
                bool flag = false;
                rep(j, N) {
                    flag |= tmp[i][j] == u[i];
                }
                if (!flag) { fin(-1); }
            }
        } else if (H == 1) {
            rep(i, N) {
                if (S[i] != u[i]) { continue; }
                rep(j, N) {
                    bool flag = false;
                    rep(k, N) {
                        flag |= tmp[k][j] == v[j];
                    }
                    if (!flag) { tmp[i][j] = v[j]; }
                }
                vint blank;
                bool flag = false;
                rep(j, N) {
                    flag |= tmp[i][j] == u[i];
                    if (tmp[i][j] == -1) { blank.push_back(j); }
                }
                if (!flag && blank.empty()) { fin(-1); }
                if (!flag) { tmp[i][blank[0]] = u[i]; }
            }
        } else if (W == 1) {
            rep(i, N) {
                if (T[i] != v[i]) { continue; }
                rep(j, N) {
                    bool flag = false;
                    rep(k, N) {
                        flag |= tmp[j][k] == u[j];
                    }
                    if (!flag) { tmp[j][i] = u[j]; }
                }
                vint blank;
                bool flag = false;
                rep(j, N) {
                    flag |= tmp[j][i] == v[i];
                    if (tmp[j][i] == -1) { blank.push_back(j); }
                }
                if (!flag && blank.empty()) { fin(-1); }
                if (!flag) { tmp[blank[0]][i] = v[i]; }
            }
        }
        rep(i, N) {
            rep(j, N) {
                if (tmp[i][j] == -1) { tmp[i][j] = 0; }
            }
        }

        //仕上げ
        rep(j, N) {
            rep(k, N) {
                ans[j][k] |= bit(p) * tmp[j][k];
            }
        }
    }
    rep(i, N) {
        rep(j, N) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}