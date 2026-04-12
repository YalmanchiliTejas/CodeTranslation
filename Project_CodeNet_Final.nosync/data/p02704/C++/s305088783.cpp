#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define Return(ans) { cout << (ans) << endl; return 0; }
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

using ull = unsigned long long;

signed main(){

    int N; cin >> N;
    vec S(N), T(N); cin >> S >> T;
    vector<ull> U(N), V(N); cin >> U >> V;

    vector<vector<ull>> A(N, vector<ull>(N));
    REP(k, 64){
        vec u(N), v(N);
        REP(i, N){
            u[i] = (U[i] >> k) & 1;
            v[i] = (V[i] >> k) & 1;
        }
        mat a(N, vec(N, -1));
        
        vec r1, r2;
        REP(i, N){
            if(S[i] == 0 && u[i] == 1){
                REP(j, N){
                    if(a[i][j] == 0){
                        Return(-1);
                    }else{
                        a[i][j] = 1;
                    }
                }
            }else if(S[i] == 1 && u[i] == 0){
                REP(j, N){
                    if(a[i][j] == 1){
                        Return(-1);
                    }else{
                        a[i][j] = 0;
                    }
                }
            }else r1.pb(i);
        }

        REP(j, N){
            if(T[j] == 0 && v[j] == 1){
                REP(i, N){
                    if(a[i][j] == 0){
                        Return(-1);
                    }else{
                        a[i][j] = 1;
                    }
                }
            }else if(T[j] == 1 && v[j] == 0){
                REP(i, N){
                    if(a[i][j] == 1){
                        Return(-1);
                    }else{
                        a[i][j] = 0;
                    }
                }
            }else r2.pb(j);
        }

        if(SZ(r1) == 1){
            int i0 = r1[0];
            for(int j: r2){
                a[i0][j] = u[i0];
                int x = a[0][j];
                if(T[j] == 0){
                    REP(i, N) x &= a[i][j];
                }else{
                    REP(i, N) x |= a[i][j];
                }
                if(x != v[j]) a[i0][j] ^= 1;
            }
        }else if(SZ(r2) == 1){
            int j0 = r2[0];
            for(int i: r1){
                a[i][j0] = v[j0];
                int x = a[i][0];
                if(S[i] == 0){
                    REP(j, N) x &= a[i][j];
                }else{
                    REP(j, N) x |= a[i][j];
                }
                if(x != u[i]) a[i][j0] ^= 1;
            }
        }else{
            REP(i, SZ(r1)) REP(j, SZ(r2)) a[r1[i]][r2[j]] = (i + j) % 2;
        }

        REP(i, N){
            int x = a[i][0];
            if(S[i] == 0){
                REP(j, N) x &= a[i][j];
            }else{
                REP(j, N) x |= a[i][j];
            }
            if(x != u[i]){
                Return(-1);
            }
        }

        REP(j, N){
            int x = a[0][j];
            if(T[j] == 0){
                REP(i, N) x &= a[i][j];
            }else{
                REP(i, N) x |= a[i][j];
            }
            if(x != v[j]){
                Return(-1);
            }
        }

        REP(i, N) REP(j, N) A[i][j] ^= (ull)a[i][j] << k;
    }

    REP(i, N){
        REP(j, N) cout << A[i][j] << " ";
        cout << endl;
    }

    return 0;
}
