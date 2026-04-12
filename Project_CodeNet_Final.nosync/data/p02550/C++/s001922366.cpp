#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<60);

class mint {
public:
    ll x;
    static ll mod;
    static unsigned long long mod_plus;
    static bool prime;

    static void set_mod(ll _mod, bool _prime = false) {
        mint::mod = _mod;
        mint::mod_plus = (LLONG_MAX / mod) * mod;
        mint::prime = _prime;
    }

    mint() { x = 0; }

    mint(ll _x) : x((_x < 0 ? ((_x += mod_plus) < 0 ? _x + mod_plus : _x) : _x)%mod){}

    void set_raw(ll _x){
        //caution : _x must be in [0, mod)
        x = _x;
    }
    mint operator-() {
        return x == 0 ? 0 : mod - x;
    }

    mint &operator+=(const mint &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint operator+(const mint &a) const {
        return mint(*this) += a;
    }

    mint &operator-=(const mint &a) {
        if ((x -= a.x) < 0) x += mod;
        return *this;
    }

    mint operator-(const mint &a) const {
        return mint(*this) -= a;
    }

    mint &operator*=(const mint &a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator*(const mint &a) const {
        return mint(*this) *= a;
    }

    mint pow(unsigned long long pw) const {
        mint res(1), comp(*this);
        while (pw) {
            if (pw & 1) res *= comp;
            comp *= comp;
            pw >>= 1;
        }
        return res;
    }

    //modと互いに素な数aなら可能
    mint inv() const {
        if(prime){
            return mint(*this).pow(mod - 2);
        }else {
            // return p = (s.x, s.y)  :  a * p.fi + b * p.se = gcd(a, b);
            // 不要なのでxは省略
            ll su = mod, sy = 0, tu = x, ty = 1;
            while (tu != 0) {
                ll temp = su / tu;
                su -= tu * temp;
                sy -= ty * temp;
                swap(su, tu);
                swap(sy, ty);
            }
            mint res;
            res.set_raw(sy < 0 ? sy + mod : sy);
            return res;
        }
    }

    mint &operator/=(const mint &a) {
        (x *= a.inv().x) %= mod;
        return *this;
    }

    mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
};
ostream& operator<<(ostream& os, const mint& a){
    os << a.x;
    return os;
}
long long mint::mod;
unsigned long long mint::mod_plus;
bool mint::prime;
using vm = vector<mint>;

int main() {
    ll X;
    cin>>N>>X>>M;
    mint::set_mod(M);
    vm a(1, X);
    vec used(M, -1);
    used[X] = 0;
    mint now(X * X);
    int sz = 1;
    while(used[now.x] == -1){
        a.push_back(now);
        used[now.x] = sz++;
        now *= now;
    }
    ll first_len = used[now.x];
    vec sum(sz + 1, 0);
    rep(i, sz) sum[i + 1] = sum[i] + a[i].x;
    //cout<<first_len<<endl;
    if(N < first_len){
        cout<<sum[N]<<endl;
    }else{
        //cout<<first_len<<endl;
        N -= first_len;
        ll loop_len = sz - first_len, loop_sum = sum[sz] - sum[first_len];
        cout<<sum[first_len] + loop_sum * (N / loop_len) + (sum[first_len + (N % loop_len)] - sum[first_len])<<endl;
    }
}
