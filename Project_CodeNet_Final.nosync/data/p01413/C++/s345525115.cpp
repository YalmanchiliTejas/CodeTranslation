#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define all(x) begin(x),end(x)

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

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N, M, W, T;
    cin >> N >> M >> W >> T;
    map<string,int> S;
    vi V(M), P(M);
    REP(i, M) {
        string s; cin >> s >> V[i] >> P[i];
        S[s] = i;
    }
    vi X(N), Y(N);
    vvi R(N), Q(N);
    REP(i, N) {
        int L; cin >> L >> X[i] >> Y[i];
        R[i].resize(L);
        Q[i].resize(L);
        REP(j, L) {
            string s;
            cin >> s >> Q[i][j];
            R[i][j] = S[s];
        }
    }

    vvll dp(N+1, vll(1<<N+1, LINF));
    dp[0][0] = 0;
    REP(s, 1<<N+1) {
        REP(i, N+1) {
            if (dp[i][s] == INF) continue;
            REP(j, N+1) {
                if (s >> j & 1) continue;
                int dx = (i == 0 ? 0 : X[i-1]) - (j == 0 ? 0 : X[j-1]);
                int dy = (i == 0 ? 0 : Y[i-1]) - (j == 0 ? 0 : Y[j-1]);
                chmin(dp[j][s | 1<<j], dp[i][s] + abs(dx) + abs(dy));
            }
        }
    }

    vll value(1<<N);

    REP(s, 1<<N) {
        map<int,int> goods;
        REP(i, N) if (s >> i & 1) {
            REP(j, R[i].size()) {
                if (goods.count(R[i][j]) == 0) {
                    goods[R[i][j]] = Q[i][j];
                } else {
                    chmin(goods[R[i][j]], Q[i][j]);
                }
            }
        }

        vll dp(W+1);
        for (auto tp : goods) {
            int id, val;
            tie(id, val) = tp;
            REP(w, W) {
                if (w + V[id] <= W) {
                    chmax(dp[w + V[id]], dp[w] + max(P[id] - val, 0));
                }
            }
        }
        value[s] = dp[W];
    }

    vll dp2(T+1);
    REP(s, 1<<N) {
        ll dist = dp[0][s << 1 | 1], val = value[s];
        REP(t, T+1) {
            if (t + dist <= T) {
                chmax(dp2[t + dist], dp2[t] + val);
            }
        }
    }

    cout << dp2[T] << endl;

    return 0;
}

