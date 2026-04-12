#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
    ll to, rev;
    long double cap;
    Edge(ll _to, long double _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &G, ll from, ll to, long double cap, bool revFlag,
              long double revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

void solve() {
    ll n;
    cin >> n;
    vec<ull> s(n), t(n), u(n), v(n);
    REP(i, n) {
        cin >> s[i];
    }
    REP(i, n) {
        cin >> t[i];
    }
    REP(i, n) {
        cin >> u[i];
    }
    REP(i, n) {
        cin >> v[i];
    }
    vvec<ull> a(n, vec<ull>(n, 0));
    ull c = 1;

    REP(x, 64) {
        vvec<ll> b(n, vec<ll>(n, -1));
        REP(i, n) {
            if(s[i]) {
                if(!((u[i] >> x) & 1)) {
                    //論理和が0のとき
                    REP(j, n) {
                        b[i][j] = 0;
                    }
                }
            } else {
                if((u[i] >> x) & 1) {
                    //論理積が1のとき
                    REP(j, n) {
                        b[i][j] = 1;
                    }
                }
            }
        }

        REP(j, n) {
            if(t[j]) {
                if(!((v[j] >> x) & 1)) {
                    //論理和が0のとき
                    REP(i, n) {
                        if(b[i][j] == 1) {
                            cout << -1 << en;
                            return;
                        } else {
                            b[i][j] = 0;
                        }
                    }
                }
            } else {
                if((v[j] >> x) & 1) {
                    //論理積が1のとき
                    REP(i, n) {
                        if(b[i][j] == 0) {
                            cout << -1 << en;
                            return;
                        } else {
                            b[i][j] = 1;
                        }
                    }
                }
            }
        }

        vec<ll> coni(n, 0), conj(n, 0); //0の数
        REP(i, n) {
            REP(j, n) {
                if(b[i][j] == -1)
                    b[i][j] = 0;
                if(!b[i][j]) {
                    coni[i]++;
                    conj[j]++;
                }
            }
        }

        REP(i, n) {

            if(!s[i] and !((u[i] >> x) & 1)) {
                //論理積が0
                if(coni[i] == 0) {
                    cout << -1 << en;
                    return;
                }
            }
            if(s[i] and ((u[i] >> x) & 1)) {
                //論理和が1
                bool flag = false;
                REP(j, n) {
                    if(t[j] and (v[j] >> x) & 1) {
                        //論理和が1
                        b[i][j] = 1;
                        conj[j]--;
                        coni[i]--;
                        flag = true;
                    }
                }
                if(coni[i] < n)
                    flag = true;
                if(flag)
                    continue;
                REP(j, n) {
                    if(!t[j] and !((v[j] >> x) & 1)) {
                        //論理積が0
                        if(conj[j] > 1) {
                            conj[j]--;
                            coni[i]--;
                            b[i][j] = 1;
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag) {
                    cout << -1 << en;
                    return;
                }
            }
        }

        REP(j, n) {

            if(!t[j] and !((v[j] >> x) & 1)) {
                //論理積が0
                if(conj[j] == 0) {
                    cout << -1 << en;
                    return;
                }
            }

            if(t[j] and ((v[j] >> x) & 1)) {
                //論理和が1
                if(conj[j] < n)
                    continue;
                bool flag = false;
                REP(i, n) {
                    if(!s[i] and !((u[i] >> x) & 1)) {
                        //論理積が0
                        if(coni[i] > 1) {
                            conj[j]--;
                            coni[i]--;
                            b[i][j] = 1;
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag) {
                    cout << -1 << en;
                    return;
                }
            }
        }

        REP(i, n) {
            REP(j, n) {
                if(b[i][j]) {
                    a[i][j] += c;
                }
            }
        }
        c <<= 1;
    }

    REP(i, n) {
        REP(j, n) {
            cout << a[i][j] << " ";
        }
        cout << en;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    // ll t;cin>>t;REP(i,t) solve();

    return 0;
}
