#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

constexpr long long default_mod = 1e9 + 7;

//element of Z/pZ
class Modulo
{
public:
    long long p;
    long long n;

    Modulo(long long n0, long long p0);
    
    bool operator==(const Modulo rhs) const{return n == rhs.n;}
    Modulo& operator+=(const long long rhs);
    Modulo& operator+=(const Modulo& rhs);
    Modulo& operator*=(const long long rhs);
    Modulo& operator*=(const Modulo& rhs);
    Modulo& operator-=(const long long rhs);
    Modulo& operator-=(const Modulo& rhs);
    Modulo pow(const long long k) const;
    Modulo inverse() const;
    Modulo& operator/=(const long long rhs);
    Modulo& operator/=(const Modulo& rhs);
    long long get() const{return n;};
};

const Modulo operator+(const Modulo &lhs, const Modulo &rhs);
const Modulo operator+(const Modulo &lhs, const long long rhs);
const Modulo operator+(const long long lhs, const Modulo &rhs);
const Modulo operator*(const Modulo &lhs, const Modulo &rhs);
const Modulo operator*(const Modulo &lhs, const long long rhs);
const Modulo operator*(const long long lhs, const Modulo &rhs);

template <class T>
T ext_gcd(T a, T b, T& x, T& y);

//constructor
Modulo::Modulo(long long n0, long long p0 = default_mod): p(p0)
{
    n = n0 >= 0 ? n0 % p : (p - (-n0 % p)) % p;
}

//operator +=
inline Modulo& Modulo::operator+=(const long long rhs)
{
    long long rhs1 = rhs >= 0 ? rhs % p : (p - (-rhs % p)) % p;
    n = (n + rhs1) % p;
    return *this;
}

inline Modulo& Modulo::operator+=(const Modulo& rhs)
{
    (*this) += rhs.n;
    return *this;
}

//operator *=
inline Modulo& Modulo::operator*=(const long long rhs)
{
    long long rhs1 = rhs >= 0 ? rhs % p : (p - (-rhs % p)) % p;
    n = (n * rhs1) % p;
    return *this;
}

inline Modulo& Modulo::operator*=(const Modulo& rhs)
{
    (*this) *= rhs.n;
    return *this;
}

//operator -=
inline Modulo& Modulo::operator-=(const long long rhs)
{
    return *this += -rhs;
}

inline Modulo& Modulo::operator-=(const Modulo& rhs)
{
    (*this) -= rhs.get();
    return *this; 
}

//(*this)**k
Modulo Modulo::pow(const long long k) const
{
    if(k == 0) return Modulo(1, p);
    if(k == 1) return Modulo(n, p);
    long long k1 = k >= 0 ? k % (p-1) : ((p-1) - (-k % (p-1))) % (p-1);
    Modulo r = pow(k1/2);
    if(k1 % 2 == 0) return r * r;
    else return r * r * n; 
}

//(*this)**(-1)
Modulo Modulo::inverse() const
{
    long long x, y;
    ext_gcd(n, p, x, y);
    return Modulo(x, p).n;
}

//operator /=
inline Modulo& Modulo::operator/=(const long long rhs)
{
    Modulo inv(rhs, p);
    inv = inv.inverse();
    return *this *= inv;
}

inline Modulo& Modulo::operator/=(const Modulo& rhs)
{
    (*this) /= rhs.get();
    return *this; 
}

//operator +
const Modulo operator+(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get(), lhs.p) += rhs;
}

const Modulo operator+(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get(), lhs.p) += rhs;
}

const Modulo operator+(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs, rhs.p) += rhs;
}

//operator *
const Modulo operator*(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get(), lhs.p) *= rhs;
}

const Modulo operator*(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get(), lhs.p) *= rhs;
}

const Modulo operator*(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs, rhs.p) *= rhs;
}

//operator -
const Modulo operator-(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get(), lhs.p) -= rhs;
}

const Modulo operator-(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get(), lhs.p) -= rhs;
}

const Modulo operator-(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs, rhs.p) -= rhs;
}

//operator /
const Modulo operator/(const Modulo &lhs, const Modulo &rhs)
{
    return Modulo(lhs.get(), lhs.p) /= rhs;
}

const Modulo operator/(const Modulo &lhs, const long long rhs)
{
    return Modulo(lhs.get(), lhs.p) /= rhs;
}

const Modulo operator/(const long long lhs, const Modulo &rhs)
{
    return Modulo(lhs, rhs.p) /= rhs;
}

//very very useful functions
//n**k
Modulo pow(Modulo n, long long k)
{
    Modulo tmp = n;
    tmp = tmp.pow(k);
    return tmp;
}

//n!
void fact_set(long long *base, int size)
{
    Modulo m = 1;
    if(size >= 0) base[0] = 1;
    for(int i=1; i<size; i++){
        m *= i;
        base[i] = m.get();
    }
}

Modulo fact(long long n, long long p = default_mod){
    using Pll = std::pair<long long, long long>;

    static std::unordered_map<long long, long long> p2index;
    static std::vector<std::vector<long long> > dat;

    if(n >= p) return 0;

    auto itr = p2index.find(p);
    if(itr == p2index.end()){
        p2index.insert(Pll(p, p2index.size()));
        dat.push_back(std::vector<long long>(1, 1));
    }

    int i = p2index[p];
    while(dat[i].size() < n+1) dat[i].push_back(dat[i].back()*dat[i].size()%p);
    return Modulo(dat[i][n], p);
}

Modulo ifact(long long n, long long p = default_mod){
    using Pll = std::pair<long long, long long>;

    static std::unordered_map<long long, long long> p2index;
    static std::vector<std::vector<long long> > dat;

    auto itr = p2index.find(p);
    if(itr == p2index.end()){
        p2index.insert(Pll(p, p2index.size()));
        dat.push_back(std::vector<long long>(1, 1));
    }

    int i = p2index[p];
    while(dat[i].size() < n+1)
        dat[i].push_back(fact(dat[i].size(), p).inverse().n);
    return Modulo(dat[i][n], p);
}

//nCk
Modulo comb(long long n, long long k, long long p = default_mod)
{
    Modulo a = fact(n, p);
    Modulo b = fact(k, p);
    Modulo c = fact(n-k, p);
    return a / b / c;
}

// ax + by = d
template <class T>
T ext_gcd(T a, T b, T& x, T& y)
{
    if(b == 0){
        x = 1; y = 0; return a;
    }
    T d = ext_gcd(b, a%b, x, y);
    T x_ = x;
    x = y;
    y = x_ - a/b * y;
    return d;
}

int main()
{
    ll MOD = 1e9+7;

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    vector<ll> dp(N+1, 0);
    dp[0] = 1;

    for(int i=A; i<=B; i++){
        // for(int k=1; k<10; k++){
        //     if(i==(A*(10-k)+B*k)/10) cout << 10*k << "%\n";
        // }
        Modulo fi_inv = ifact(i);
        // cout << "i = " << i << ", (i)!^(-1) = " << fi_inv.n << endl;
        for(int j=N; j>=0; j--){
            Modulo next(dp[j]);
            Modulo fimk = fi_inv.pow(C);
            for(int k=C; j-i*k>=0 && k<=D; k++){
                next += Modulo(dp[j-i*k]) * fact(j) * ifact(j-i*k)
                    * fimk * ifact(k);
                fimk *= fi_inv;
            }
            dp[j] = next.n;
        }
    }

    // for(ll& x: dp) cout << x << " "; cout << endl;
    cout << dp[N] << endl;
}