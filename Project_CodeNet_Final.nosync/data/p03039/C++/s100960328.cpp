#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

constexpr ll MOD{1000000007};
constexpr ll MAX_SIZE{3000010LL};
template <ll MOD = MOD>
class Mint
{
public:
    ll x;
    Mint() : x{0LL} {}
    Mint(ll x) : x{x % MOD} {}
    Mint operator-() const { return x ? MOD - x : 0; }
    Mint &operator+=(const Mint &a)
    {
        if ((x += a.x) >= MOD)
        {
            x -= MOD;
        }
        return *this;
    }
    Mint &operator-=(const Mint &a) { return *this += -a; }
    Mint &operator*=(const Mint &a)
    {
        (x *= a.x) %= MOD;
        return *this;
    }
    Mint &operator/=(const Mint &a)
    {
        Mint b{a};
        return *this *= b.power(MOD - 2);
    }
    Mint operator+(const Mint &a) const { return Mint(*this) += a; }
    Mint operator-(const Mint &a) const { return Mint(*this) -= a; }
    Mint operator*(const Mint &a) const { return Mint(*this) *= a; }
    Mint operator/(const Mint &a) const { return Mint(*this) /= a; }
    bool operator<(const Mint &a) const { return x < a.x; }
    bool operator==(const Mint &a) const { return x == a.x; }
    const Mint power(ll N)
    {
        if (N == 0)
        {
            return 1;
        }
        else if (N % 2 == 1)
        {
            return *this * power(N - 1);
        }
        else
        {
            Mint half = power(N / 2);
            return half * half;
        }
    }
};
template <ll MOD>
Mint<MOD> operator+(ll lhs, const Mint<MOD> &rhs)
{
    return rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator-(ll lhs, const Mint<MOD> &rhs)
{
    return -rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator*(ll lhs, const Mint<MOD> &rhs)
{
    return rhs * lhs;
}
template <ll MOD>
Mint<MOD> operator/(ll lhs, const Mint<MOD> &rhs)
{
    return Mint<MOD>{lhs} / rhs;
}
template <ll MOD>
istream &operator>>(istream &stream, Mint<MOD> &a)
{
    return stream >> a.x;
}
template <ll MOD>
ostream &operator<<(ostream &stream, const Mint<MOD> &a)
{
    return stream << a.x;
}
template <ll MOD = MOD, ll MAX_SIZE = MAX_SIZE>
class Combination
{
public:
    vector<Mint<MOD>> inv, fact, factinv;
    Combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
    {
        inv[1] = 1;
        for (auto i = 2LL; i < MAX_SIZE; i++)
        {
            inv[i] = (-inv[MOD % i]) * (MOD / i);
        }
        fact[0] = factinv[0] = 1;
        for (auto i = 1LL; i < MAX_SIZE; i++)
        {
            fact[i] = Mint<MOD>(i) * fact[i - 1];
            factinv[i] = inv[i] * factinv[i - 1];
        }
    }
    Mint<MOD> operator()(int n, int k)
    {
        if (n >= 0 && k >= 0 && n - k >= 0)
        {
            return fact[n] * factinv[k] * factinv[n - k];
        }
        return 0;
    }
    Mint<MOD> catalan(int x, int y)
    {
        return (*this)(x + y, y) - (*this)(x + y, y - 1);
    }
};
// for C++14
using mint = Mint<MOD>;
using combination = Combination<MOD, MAX_SIZE>;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    combination c = combination();
    mint sum = 0;
    for (int i = 0; i <= N-1; ++i) {
        for (int j = 0; j <= M-1; ++j) {
            mint tmp = mint(N - i) * mint(M - j) * mint(i + j);
            if (i != 0 && j != 0) tmp *= 2;
            sum += tmp;
        }
    }

    cout << sum * c(N*M-2, K-2) << endl;
}
