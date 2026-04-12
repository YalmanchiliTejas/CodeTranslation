#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a,b);
    
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a,b);
    return (a/g)*b;
}

// 素数判定 O(√n)
bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// 約数列挙 O(√n)
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll, ll> > res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        ll num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

template<int param>
class ModInt{//{{{
    using Z = int;
    using N = unsigned int;
    using ZZ = long long;
    using NN = unsigned long long;
    struct {} constexpr static exact{};

    // Using Z deliberately to avoid Z -> N promotion.
    template<class Ret = Z&>
    static auto modulo() -> std::enable_if_t<(param<=0), Ret> { static Z mod = 0; return mod; }
    template<class Ret = const Z>
    static auto mod() -> std::enable_if_t<(param<=0), Ret> { return modulo(); }
    template<class Ret = const Z>
    static constexpr auto mod() -> std::enable_if_t<(param>0), Ret> { return param; }
    // std::swap is not a constexpr function in C++14
    static constexpr void swap(Z &a, Z &b){ Z tmp = a; a = b; b = tmp; }

    Z val;
    constexpr ModInt(decltype(exact), const N v) : val(v) {}

public:
    template<class Arg = Z>
    static void set_modulo(const std::enable_if_t<(param<=0), Arg> mod) { modulo() = mod; }

    constexpr ModInt() : val(0) {}
    constexpr ModInt(Z v) : val((v%=mod()) < 0 ? v+mod() : v) {}
    constexpr ModInt(ZZ v) : val((v%=mod()) < 0 ? v+mod() : v) {}

    constexpr int get_val() const { return val; }

    constexpr ModInt inv() const {
        Z a = mod(), b = val;
        Z x = 0, u = 1;
        while (b) {
            const Z t = a / b;
            swap(a -= t * b, b);
            swap(x -= t * u, u);
        }
        return ModInt(exact, x < 0 ? x+mod() : x);
    }

    constexpr explicit operator int() const { return val; }
    constexpr ModInt operator+() const { return *this; }
    constexpr ModInt operator-() const { return ModInt(exact, val ? mod() - val : 0); }

    constexpr ModInt operator++(){ if(++val == mod()) val = 0; return *this; }
    constexpr ModInt operator--(){ val = (val == 0 ? mod()-1 : val-1); return *this; }
    constexpr ModInt operator++(int){ const ModInt res(*this); ++*this; return res; }
    constexpr ModInt operator--(int){ const ModInt res(*this); --*this; return res; }

    constexpr bool operator==(const ModInt &rhs) const { return val == rhs.val; }
    constexpr bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
    constexpr ModInt &operator+=(const ModInt &rhs){
        if((val += rhs.val) >= mod()) val -= mod();
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs){
        if(rhs.val && (val += mod()-rhs.val) >= mod()) val -= mod();
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs){ val = (NN)(val) * rhs.val % mod(); return *this; }
    constexpr ModInt &operator/=(const ModInt &rhs){ return *this *= rhs.inv(); }

    constexpr ModInt pow(long long e) const {
        if(e < 0) return pow(-e).inv();
        NN res = 1, b = val;
        for(; e; e >>= 1, (b *= b) %= mod()) if(e&1) (res *= b) %= mod();
        return ModInt(exact, res);
    }
    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs){ return lhs += rhs; }
    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs){ return lhs -= rhs; }
    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs){ return lhs *= rhs; }
    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs){ return lhs /= rhs; }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &v) { return os << v.val; }
    friend std::istream &operator>>(std::istream &is, ModInt &v) {
        int val;
        is >> val;
        v = ModInt(val);
        return is;
    }
};//}}}

const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
using mi = ModInt<1000000007>; 

void addM(ll &a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(ll &a, ll b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);  

    int N;
    cin >> N;
    vector<ll> s(N);
    REP(i, N) cin >> s[i];

    ll res = 0;
    for (int p = 1; p <= N-1; ++p) {
        ll tmp = 0;
        ll cur = 0;
        int i = 0, j = N-1;
        if ((N-1) % p == 0) {
            for (; i < j; i += p, j -= p) {
                cur += s[i] + s[j];
                chmax(tmp, cur);
            }
        } else {
            for (; i < N-1 && j > p; i += p, j -= p) {
                cur += s[i] + s[j];
                chmax(tmp, cur);
            }
        }
        chmax(res, tmp);
    }
    cout << res << endl;

    return 0;
}