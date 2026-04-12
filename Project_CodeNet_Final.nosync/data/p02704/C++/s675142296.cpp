#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize(3)
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("sse3","sse2","sse")
//#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//#pragma GCC target("f16c")
//#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//#pragma GCC diagnostic error "-fwhole-program"
//#pragma GCC diagnostic error "-fcse-skip-blocks"
//#pragma GCC diagnostic error "-funsafe-loop-optimizations"
//#pragma GCC diagnostic error "-std=c++14"
#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define REP(x, l, u) for(ll x = l;x<u;x++)
#define RREP(x, l, u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(begin(a),end(a)),end(a))
#define mst(x, a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define rall(a) rbegin(a),rend(a)
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define lowbit(x) ((x)&(-(x)))
#define bitcnt(x) (__builtin_popcountll(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
#define EX0 exit(0);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace __gnu_pbds; //required
using namespace std;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef vector<ll> VLL;
typedef vector<int> VI;
const ll mod = 1e9 + 7;


string to_string (string s) { return '"' + s + '"'; }

string to_string (const char *s) { return to_string ((string) s); }

string to_string (bool b) { return (b ? "true" : "false"); }

template<typename A, typename B>
string to_string (pair<A, B> p) { return "(" + to_string (p.first) + ", " + to_string (p.second) + ")"; }

template<typename A>
string to_string (A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) { res += ", "; }
        first = false;
        res += to_string (x);
    }
    res += "}";
    return res;
}

void debug_out () { cerr<<endl; }

template<typename Head, typename... Tail>
void debug_out (Head H, Tail... T) {
    cerr<<" "<<to_string (H);
    debug_out (T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) {}
#endif

template<typename T, typename S>
inline bool upmin (T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax (T &a, const S &b) { return a < b ? a = b, 1 : 0; }


ull twop (ll x) { return 1ULL<<x; }

ll MOD (ll a, ll m) {
    a %= m;
    if (a < 0)a += m;
    return a;
}

ll inverse (ll a, ll m) {
    a = MOD (a, m);
    if (a <= 1)return a;
    return MOD ((1 - inverse (m, a) * m) / a, m);
}

template<typename T>
T sqr (T x) { return x * x; }

ll gcd (ll a, ll b) {
    a = abs (a), b = abs (b);
    while (b != 0) {
        a %= b;
        swap (a, b);
    }
    return a;
}

ll fast (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

ll fast (ll a, ll b, ll mod) {
    if (b < 0)a = inverse (a, mod), b = -b;
    ll ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans % mod;
}

int ans[510][510][64];
namespace SOLVE {
    ll n;
    ull s[510], t[510], u[510], v[510], fin[510][510];
    
    void main () {
        mst(ans, -1);
        cin>>n;
        REP(i, 0, n)cin>>s[i];
        REP(i, 0, n)cin>>t[i];
        REP(i, 0, n)cin>>u[i];
        REP(i, 0, n)cin>>v[i];
        REP(b, 0, 64) {
            ull base = 1ull<<b;
            dbg(b);
            REP(i, 0, n) {
                if (s[i] == 0) {
                    dbg("ROW", i, "AND", (base & u[i]) > 0);
                } else {
                    dbg("ROW", i, "OR", (base & u[i]) > 0);
                }
            }
            REP(i, 0, n) {
                if (t[i] == 0) {
                    dbg("COL", i, "AND", (base & v[i]) > 0);
                } else {
                    dbg("COL", i, "OR", (base & v[i]) > 0);
                }
            }
            REP(i, 0, n) {
                if (s[i] == 0 and (base & u[i]) > 0) {
                    REP(j, 0, n)ans[i][j][b] = 1;
                }
                if (s[i] == 1 and (base & u[i]) == 0) {
                    REP(j, 0, n)ans[i][j][b] = 0;
                }
                if (t[i] == 0 and (base & v[i]) > 0) {
                    REP(j, 0, n)ans[j][i][b] = 1;
                }
                if (t[i] == 1 and (base & v[i]) == 0) {
                    REP(j, 0, n)ans[j][i][b] = 0;
                }
            }
//            REP(i, 0, n)REP(j, 0, n)cout<<ans[i][j][0]<<" \n"[j == n - 1];
            
            VLL row, col;
            REP(i, 0, n)
                REP(j, 0, n)
                    if (ans[i][j][b] == -1) {
                        row.PB (i);
                        col.PB (j);
                    }
            sort (all(row));
            sort (all(col));
            complete_unique(row);
            complete_unique(col);
            dbg(row, col);
            if (sz(row) == 0) {
                
            }
            if (sz(row) == 1) {
                for (auto j:col) {
                    if (t[j] == 0) {
                        // and = 0;
                        bool ok = 0;
                        REP(i, 0, n) {
                            if (ans[i][j][b] == 0) {
                                ok = 1;
                                break;
                            }
                        }
                        if (!ok)ans[row[0]][j][b] = 0;
                    } else {
                        // or = 1;
                        bool ok = 0;
                        REP(i, 0, n) {
                            if (ans[i][j][b] == 1) {
                                ok = 1;
                                break;
                            }
                        }
                        if (!ok)ans[row[0]][j][b] = 1;
                    }
                }
                for (auto j:col) {
                    if (ans[row[0]][j][b] == -1)ans[row[0]][j][b] = s[row[0]];
                }
                
            } else if (sz(col) == 1) {
                for (auto i:row) {
                    if (s[i] == 0) {
                        // and = 0;
                        bool ok = 0;
                        REP(j, 0, n) {
                            if (ans[i][j][b] == 0) {
                                ok = 1;
                                break;
                            }
                        }
                        if (!ok)ans[i][col[0]][b] = 0;
                    } else {
                        // or = 1;
                        bool ok = 0;
                        REP(j, 0, n) {
                            if (ans[i][j][b] == 1) {
                                ok = 1;
                                break;
                            }
                        }
                        if (!ok)ans[i][col[0]][b] = 1;
                    }
                }
                for (auto i:row) {
                    if (ans[i][col[0]][b] == -1)ans[i][col[0]][b] = t[col[0]];
                }
            } else {
                REP(i, 0, sz (row)) {
                    REP(j, 0, sz (col)) {
                        ans[row[i]][col[j]][b] = (i + j) % 2;
                    }
                }
            }
//            REP(i,0,n){
//                REP(j,0,n){
//                    cerr<<ans[i][j][b];
//                }
//                cerr<<endl;
//            }
            REP(i, 0, n) {
                REP(j, 0, n) {
                    if (ans[i][j][b])fin[i][j] += 1ull<<b;
                }
            }
            
            
        }
        REP(i, 0, n) {
            ull AND, OR;
            AND = OR = fin[i][0];
            REP(j, 0, n) {
                AND &= fin[i][j];
                OR |= fin[i][j];
            }
            if (s[i] == 0 and AND != u[i]) {
                cout<<-1;
                return;
            }
            if (s[i] == 1 and OR != u[i]) {
                cout<<-1;
                return;
            }
        }
        
        REP(j, 0, n) {
            ull AND, OR;
            AND = OR = fin[0][j];
            REP(i, 0, n) {
                AND &= fin[i][j];
                OR |= fin[i][j];
            }
            if (t[j] == 0 and AND != v[j]) {
                cout<<-1;
                return;
            }
            if (t[j] == 1 and OR != v[j]) {
                cout<<-1;
                return;
            }
        }
        REP(i, 0, n)REP(j, 0, n)cout<<fin[i][j]<<" \n"[j == n - 1];
        
    }
}


signed main () {
#ifdef LOCAL
    fr("/Users/zhangqingchuan/Desktop/cp/cp/input.txt");
    fw("/Users/zhangqingchuan/Desktop/cp/cp/output.txt");
#endif
    
    
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout<<"Case #"<<i<<": ";
        SOLVE::main ();
        
    }








//    clock_t st = clock();
//    while(clock() - st < 3.0 * CLOCKS_PER_SEC){
//
//    }
    
    
    
    
    
    
    return 0;
}
