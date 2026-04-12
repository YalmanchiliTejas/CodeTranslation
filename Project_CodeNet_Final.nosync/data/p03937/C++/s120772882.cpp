#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(a) a.begin(), a.end()
#define pii pair<int,int>
#pragma GCC optimize("Ofast")
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define isSquare(x) (sqrt(x)*sqrt(x) == x)
template<class T>bool chmax(T &a, const T &b) {if(a<b){a = b; return 1;} return 0; };
template<class T>bool chmin(T &a, const T &b) {if(a>b){a = b; return 1;} return 0; };
inline void IN(void){return;}
template <typename First, typename... Rest> void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
inline void OUT(void){cout << "\n";return;}
template <typename First, typename... Rest> void OUT(First first, Rest... rest){cout << first << " ";OUT(rest...);return;}
const double EPS = 1e-9;
const int mod = 1e9 + 7;
const int INF = 1e9;
const long long LLINF = 1e18;
long long lcm(ll a, ll b){return a * b / __gcd(a,b);}
struct IoSetup { IoSetup() {
    cin.tie(nullptr);ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
} } iosetup;
template< int mod > struct ModInt {
    int x; ModInt() : x(0) {}
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

int main(){
    iosetup;
    int H, W; cin >> H >> W;
    vector<string> A(H);
    rep(i, 0, H) cin >> A[i];

    int h = 0, w = 0;
    while(!(h == H - 1 && w == W - 1)){
        // cerr << h << " " << w << endl;
        int cnt = 0;
        rep(i, 0, 2){
            if(h + dx[i] < H && w + dy[i] < W){
                if(A[h+dx[i]][w+dy[i]] == '#'){
                    // cerr << i << endl;
                    cnt++;
                }
            }
        }
        // cerr << cnt << endl;
        int tcnt = 0;
        rep(i, 2, 4){
            if(h + dx[i] >= 0 && w + dy[i] >= 0){
                if(A[h+dx[i]][w+dy[i]] == '#') tcnt++;
            }
        }
        if(h == 0 && w == 0) {
            if(tcnt != 0){
                puts("Impossible");
                return 0;
            }
        }else{
            if(tcnt != 1){
                puts("Impossible");
                return 0;
            }
        }
        if(cnt == 1){
            rep(i, 0, 2){
                if(h + dx[i] < H && w + dy[i] < W){
                    if(A[h+dx[i]][w+dy[i]] == '#'){
                        // cerr << i << endl;
                        h += dx[i];
                        w += dy[i];
                        break;
                    }
                }
            }
        }else{
            puts("Impossible");
            return 0;
        }
    }
    int tcnt = 0;
    rep(i, 2, 4){
        if(h + dx[i] >= 0 && w + dy[i] >= 0){
            if(A[h+dx[i]][w+dy[i]] == '#') tcnt++;
        }
    }
    if(tcnt != 1){
        puts("Impossible");
        return 0;
    }
    
    puts("Possible");

    return 0;
}