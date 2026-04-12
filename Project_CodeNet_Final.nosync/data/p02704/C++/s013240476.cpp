#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>
using namespace std;
using ull = unsigned long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
using pii = pair<int,int>;
using piii = pair<pii,int>;
using pll = pair<long long, long long>;
using plll = pair<pll, long long>;
// #pragma GCC optimize("Ofast")
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define isSquare(x) (sqrt(x)*sqrt(x) == x)
template<class T>inline bool chmax(T &a, const T &b) {if(a<b){a = b; return 1;} return 0; };
template<class T>inline bool chmin(T &a, const T &b) {if(a>b){a = b; return 1;} return 0; };
inline void in(void){return;}
template <typename First, typename... Rest> void in(First& first, Rest&... rest){cin >> first;in(rest...);return;}
inline void out(void){cout << "\n";return;}
template <typename First, typename... Rest> void out(First first, Rest... rest){cout << first << " ";out(rest...);return;}
const double EPS = 1e-9;
const int mod = 1e9 + 7;
// const int mod = 998244353;
const int INF = 1e9;
const long long INFLL = 1e18;
void iosetup() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
}
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}
template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}
template<class T> vector<T> make_vec(size_t a) {return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S, T>& t){return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S, T>& t){return pair<S,T>(s.first-t.first, s.second-t.second);}
template<class S, class T> pair<S,T> operator*(const pair<S,T> &s, const S& t){return pair<S,T>(s.first*t, s.second*t);}
template <typename T> void Exit(T first){cout << first << endl;exit(0); };
template< int mod > struct ModInt {
    unsigned x; ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {if((x += p.x) >= mod) x -= mod;return *this;}
    ModInt &operator-=(const ModInt &p) {if((x += mod - p.x) >= mod) x -= mod;return *this;}
    ModInt &operator*=(const ModInt &p) {x = (int) (1LL * x * p.x % mod);return *this;}
    ModInt &operator/=(const ModInt &p) {*this *= p.inverse();return *this;}
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); }return ModInt(u);}
    ModInt pow(int64_t n) const {ModInt ret(1), mul(x); while(n > 0) {if(n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x;}
    friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
    static int get_mod() { return mod; }
}; using modint = ModInt< mod >;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const pii dxy[4] = {pii(1,0), pii(0, 1), pii(-1, 0), pii(0, -1)};
bool range(int a, int b, int x){if(a <= x and x < b)return true;else return false;}
bool range(int a, int b, int c, int d, pii p){if(a <= p.first and p.first < b and c <= p.second and p.second < d) return true;else return false;}


pair<bool, vector<vector<int> > > solve(vector<ull>& S, vector<ull>& T, vector<bool>& u, vector<bool>& v){
    int n = S.size();
    auto res = make_vec<int>(n, n);
    rep(i, 0, n) rep(j, 0, n) res[i][j] = -1;
    bool flag = true;
    rep(i, 0, n){
        if(S[i] == 1 and !u[i]){
            rep(j, 0, n) res[i][j] = 0;
        }else if(S[i] == 0 and u[i]){
            rep(j, 0, n) res[i][j] = 1;
        }
    }
    rep(i, 0, n){
        if(T[i] == 1 and !v[i]){
            rep(j, 0, n){
                if(res[j][i] != -1 and res[j][i] != 0) flag = false;
                res[j][i] = 0;
            }
        }else if(T[i] == 0 and v[i]){
            rep(j, 0, n){
                if(res[j][i] != -1 and res[j][i] != 1) flag = false;
                res[j][i] = 1;
            }
        }
    }
    if(!flag) return {flag, res};
    rep(i, 0, n){
        rep(j, 0, n){
            if(u[i] == v[j]){
                res[i][j] = u[i];
            }else{
                if(res[i][j] == -1) res[i][j] = 0;
            }
        }
    }
    // cout << res << endl;

    rep(i, 0, n){
        if(S[i] and u[i]){
            bool F = false;
            rep(j, 0, n){
                if(res[i][j]) F = true;
            }
            if(F) continue;
            rep(j, 0, n){
                if(T[j] == 0){
                    int cnt = 0;
                    rep(k, 0, n){
                        if(res[k][j] == 0) cnt++;
                    }
                    if(cnt >= 2){
                        res[i][j] = 1;
                        F = true;
                    }
                }
                if(F) break;
            }
            if(!F){
                flag = false;
                break;
            }
        }
    }
    if(!flag) return {flag, res};
    rep(j, 0, n){
        if(T[j] and v[j]){
            bool F = false;
            rep(i, 0, n){
                if(res[i][j]) F = true;
            }
            if(F) continue;
            rep(i, 0, n){
                if(S[i] == 0){
                    int cnt = 0;
                    rep(k, 0, n){
                        if(res[i][k] == 0) cnt++;
                    }
                    if(cnt >= 2){
                        res[i][j] = 1;
                        F = true;
                    }
                }
                if(F) break;
            }
            if(!F){
                flag = false;
                break;
            }
        }
    }
    // cerr << res << endl;
    rep(i, 0, n){
        // cerr << i << endl;
        bool F = res[i][0];
        if(S[i] == 0){
            rep(j, 1, n) F = F and res[i][j];
            // cerr << i << " " << F << endl;
            if(u[i] != F) flag = false;
        }else{
            rep(j, 1, n) F = F or res[i][j];
            // cerr << i << " " << F << endl;
            if(u[i] != F) flag = false;
        }
    }
    // cerr << res << endl;
    rep(j, 0, n){
        // cerr << j << endl;
        bool F = res[0][j];
        if(T[j] == 0){
            rep(i, 1, n) F = F and res[i][j];
            if(v[j] != F) flag = false;
        }else{
            rep(i, 1, n) F = F or res[i][j];
            if(v[j] != F) flag = false;
        }
        // cerr << j << " " << F << endl;
    }
    return {flag, res};
}

int main(){
    iosetup();
    int n; cin >> n;
    vector<ull> S(n), T(n), U(n), V(n);
    cin >> S >> T >> U >> V;
    vector<vector<ull>> ans(n, vector<ull>(n, 0));
    rep(i, 0, 64){
        vector<bool> u(n, false), v(n, false);
        rep(j, 0, n) u[j] = (U[j] >> i & 1);
        rep(j, 0, n) v[j] = (V[j] >> i & 1);
        auto X = solve(S, T, u, v);
        if(!X.first) Exit(-1);
        rep(j, 0, n){
            rep(k, 0, n){
                ans[j][k] += ((ull)X.second[j][k] << i);
            }
        }
    }
    rep(i, 0, n) cout << ans[i] << endl;
    return 0;
}