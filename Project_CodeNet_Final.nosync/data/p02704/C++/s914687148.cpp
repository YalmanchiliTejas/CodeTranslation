#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
#define ll unsigned long long
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
//int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)の一様乱数
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)の一様乱数
  ll operator()(ll x, ll y) {
    uniform_int_distribution<ll> dist(x, y - 1);
    return dist(mt);
  }
  vl operator()(int n, ll x, ll y) {
    vl res(n);
    for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
    return res;
  }
} rnd;

int n;
const int N = 500;
vl s(N), t(N), u(N), v(N);

const int M = 64;

int ke;

vi calc(int s, ll u, vi now) {
    vi res(1);
    REP (i, ke, ke + 1) {
        bool flag = false;
        if (s == 0) {
            if ((u & (1ULL << i)) == 0) {
                if (now[0] == 1) {
                    res[0] = 0;
                    flag = true;
                }
            } 
        }
        if (s == 1) {
            if ((u & (1ULL << i))) {
                if (now[0] == 0) {
                    res[0] = 1;
                    flag = true;
                }
            }
        }
        if (not flag) res[0] = rnd(2);
    }
    return res;
}

vi calc2(int s, ll u, int t, ll v, vi now1, vi now2) {
    // DEBUG((int)(bool)(u & (1ULL << ke)));
    // DEBUG((int)(bool)(v & (1ULL << ke)));
    // DEBUG_VEC(now1);
    // DEBUG_VEC(now2);
    vi res(1, -1);
    REP (i, ke, ke + 1) {
        if (s == 0) {
            if ((u & (1ULL << i)) == 0) {
                if (now1[0] == 1) {
                    res[0] = 0;
                }
            } 
        }
        if (s == 1) {
            if ((u & (1ULL << i))) {
                if (now1[0] == 0) {
                    res[0] = 1;
                }
            }
        }
    }
    REP (i, ke, ke + 1) {
        if (t == 0) {
            if ((v & (1ULL << i)) == 0) {
                if (now2[0] == 1) {
                    res[0] = 0;
                }
            } 
        }
        if (t == 1) {
            if ((v & (1ULL << i))) {
                if (now2[0] == 0) {
                    res[0] = 1;
                }
            }
        }
    }
    if (res[0] == -1) {
        res[0] = rnd(2);
    }
    return res;
}

bool check(vii a) {
    rep (i, n) {
        vi now(1);
        if (s[i] == 0) fill(all(now), 1);
        else fill(all(now), 0);

        rep (j, n) {
            if (s[i] == 0 and a[i][j] == 0) now[0] = 0;
            if (s[i] == 1 and a[i][j] == 1) now[0] = 1;
        }
        
        REP (k, ke, ke + 1) {
            if (u[i] & (1ULL << k)) {
                if (now[0] == 0) return false;
            }
            else {
                if (now[0] == 1) return false;
            }
        }
    }

    rep (i, n) {
        vi now(1);
        if (t[i] == 0) fill(all(now), 1);
        else fill(all(now), 0);

        rep (j, n) {
            if (t[i] == 0 and a[j][i] == 0) now[0] = 0;
            if (t[i] == 1 and a[j][i] == 1) now[0] = 1;
        }

        REP (k, ke, ke + 1) {
            if (v[i] & (1ULL << k)) {
                if (now[0] == 0) return false;
            }
            else {
                if (now[0] == 1) return false;
            }
        }
    }
    return true;
}

vii solve(vii a) {
    rep (i, n - 1) {
        rep (j, n - 1) {
            if (a[i][j] == -1) {
                a[i][j] = rnd(2);
            }
        }
    }
    // DEBUG("st");
    // DEBUG_MAT(a);

    rep (i, n - 1) {
        vi now(1);
        if (s[i] == 0) fill(all(now), 1);
        else fill(all(now), 0);

        rep (j, n - 1) {
            if (s[i] == 0 and a[i][j] == 0) now[0] = 0;
            if (s[i] == 1 and a[i][j] == 1) now[0] = 1;
        }

        vi nex = calc(s[i], u[i], now);
        if (a[i][n - 1] == -1) a[i][n - 1] = nex[0];
    }
    // DEBUG_MAT(a);

    rep (i, n - 1) {
        vi now(1);
        if (t[i] == 0) fill(all(now), 1);
        else fill(all(now), 0);

        rep (j, n - 1) {
            if (t[i] == 0 and a[j][i] == 0) now[0] = 0;
            if (t[i] == 1 and a[j][i] == 1) now[0] = 1;
        }

        vi nex = calc(s[i], u[i], now);
        if (a[n - 1][i] == -1) a[n - 1][i] = nex[0];
    }
    // DEBUG_MAT(a);

    vi now1(M), now2(M);
    if (s[n - 1] == 0) fill(all(now1), 1);
    else fill(all(now1), 0);
    if (t[n - 1] == 0) fill(all(now2), 1);
    else fill(all(now2), 0);

    rep (j, n - 1) {
        if (s[n - 1] == 0 and a[n - 1][j] == 0) now1[0] = 0;
        if (s[n - 1] == 1 and a[n - 1][j] == 1) now1[0] = 1;
    }
    rep (j, n - 1) {
        if (t[n - 1] == 0 and a[j][n - 1]== 0) now2[0] = 0;
        if (t[n - 1] == 1 and a[j][n - 1] == 1) now2[0] = 1;
    }
    vi nex = calc2(s[n - 1], u[n - 1], t[n - 1], v[n - 1], now1, now2);
    if (a[n - 1][n - 1] == -1) {
        a[n - 1][n - 1] = nex[0];
    }
    // DEBUG_MAT(a);

    if (not check(a)) {
        a[0][0] = -1;
    }
    return a;

}

void solve1() {
    if (u[0] == v[0]) {
        cout << u[0] << endl;
    }
    else {
        cout << -1 << endl;
    }
    return;
}

signed main() {
    fio();
    clock_t start = clock();
    
    cin >> n;

    rep (i, n) cin >> s[i];
    rep (i, n) cin >> t[i];
    rep (i, n) cin >> u[i];
    rep (i, n) cin >> v[i];

    if (n == 1) {
        solve1();
        return 0;
    }

    vector<vii> a(n, vii(n, vi(M, -1)));

    rep (i, n) {
        if (s[i] == 0) {
            rep (j, n) {
                rep (k, M) {
                    if (u[i] & (1ULL << k)) {
                        a[i][j][k] = 1;
                    }
                }
            }
        }
        else {
            rep (j, n) {
                rep (k, M) {
                    if (not (u[i] & (1ULL << k))) {
                        a[i][j][k] = 0;
                    }
                }
            }
        }
    }

    rep (i, n) {
        if (t[i] == 0) {
            rep (j, n) {
                rep (k, M) {
                    if (v[i] & (1ULL << k)) {
                        if (a[j][i][k] == 0) {
                            cout << -1 << endl;
                            return 0;
                        }
                        a[j][i][k] = 1;
                    }
                }
            }
        }
        else {
            rep (j, n) {
                rep (k, M) {
                    if (not (v[i] & (1ULL << k))) {
                        if (a[j][i][k] == 1) {
                            cout << -1 << endl;
                            return 0;
                        }
                        a[j][i][k] = 0;
                    }
                }
            }
        }
    }

    // rep (i, n) {
    //     rep (j, n) {
    //         rep (k, M) {
    //             cout << a[i][j][M - 1 - k];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;

    for (ke = 0; ke < M; ke++) {
        vii b(n, vi(n));
        rep (i, n) rep (j, n) {
            b[i][j] = a[i][j][ke];
        }
        
        // rep (i, n) {
        //     DEBUG(u[i]);
        //     DEBUG((int)(bool)(u[i] & (1ULL << ke)));
        // }
        // rep (i, n) {
        //     DEBUG(v[i]);
        //     DEBUG((int)(bool)(v[i] & (1ULL << ke)));
        // }
        // DEBUG(u.back());
        // DEBUG((int)(bool)(u.back() & (1ULL << ke)));
        // DEBUG((int)(bool)(v.back() & (1ULL << ke)));


        // DEBUG_MAT(b);
        while (true) {
            vii res = solve(b);
            if (res[0][0] != -1) {
                rep (i, n) rep (j, n) {
                    a[i][j][ke] = res[i][j];
                }
                break;
            }
            else continue;
        }

    }
    rep (i, n) {
        rep (j, n) {
            ll res = 0;
            rep (k, M) {
                if (a[i][j][k]) {
                    res += 1ULL << k;
                }
            }
            cout << res << " ";
        }
        cout << endl;
    }
    return 0;
}
