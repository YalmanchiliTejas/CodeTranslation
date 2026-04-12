#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
        t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
        if(n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

using modint = ModInt<MOD>;

class combM {
private:
    vector<ll> fac;  //n!(mod M)
    vector<ll> ifac; //k!^{M-2} (mod M)
    ll mpow(ll x, ll n);
public:
    combM();
    ll com(ll a, ll b);
};

// x^n(mod M)
ll combM::mpow(ll x, ll n) {
    ll ans = 1ll;
    while(n != 0){
        if (n&1) ans = ans*x%MOD;
        x = x*x%MOD;
        n = n >> 1;
    }
    return ans;
}

// aCb をmod計算
ll combM::com(ll a, ll b) {
    if (a == 0 && b == 0) return 1;
    if (a < b || a < 0) return 0;
    ll tmp = ifac[a-b]*ifac[b]%MOD;
    return tmp*fac[a]%MOD;
}

combM::combM() {
    fac.resize(300001);
    ifac.resize(300001);
    fac[0] = 1;
    ifac[0] = 1;
    for (ll i = 0; i < 300000; ++i) {
        fac[i+1] = fac[i]*(i+1)%MOD;
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2)%MOD;
    }
}

modint calc(ll n, ll m, modint all_nm) {
    modint pair_sum = 0;
    for (ll i = n-1; i >= 1; --i) {
        modint tmp = i;
        modint M = m*m;
        tmp *= (n-i);
        tmp *= M;
        pair_sum += tmp;
    }
    modint ret = all_nm*pair_sum;
    return ret;
}

int main(int argc, char const *argv[]) {
    ll n,m,k; cin>>n>>m>>k;
    modint ans = 0;
    combM C;
    modint all_nm = C.com(n*m-2,k-2);
    ans += calc(n,m,all_nm);
    ans += calc(m,n,all_nm);
    cout << ans << '\n';
    return 0;
}