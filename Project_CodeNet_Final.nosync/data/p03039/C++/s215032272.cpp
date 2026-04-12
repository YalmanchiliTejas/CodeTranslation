//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <chrono>
#include <complex>
#include <regex>
#include <locale>
#include <random>
#include <type_traits>

using namespace std;

// typedef
//------------------------------------------
typedef long long LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VLL> VVLL;
typedef vector<VVI> VVVI;
typedef vector<VVLL> VVVLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<VPII> VVPII;
typedef vector<VPLL> VVPLL;
typedef vector<VS> VVS;
typedef map<int, int> MII;
typedef map<LL, LL> MLL;
typedef map<string, int> MSI;
typedef map<int, string> MIS;

// to-method
//------------------------------------------
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

inline LL toLongLong(string s) {
    LL v;
    istringstream sin(s);
    sin >> v;
    return v;
}

template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

inline VC toVC(string s) {
    VC data(s.begin(), s.end());
    return data;
}



// container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i, arr) for(typeof((arr).begin()) i=(arr).begin(); i!=(arr).end(); ++i)
#define EXIST(str, e) ((str).find(e)!=(str).end())
#define COUNT(arr, v) count((arr).begin(), (arr).end(), v)
#define SEARCH(v, w) search((v).begin(), (v).end(), (w).begin(), (w).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define ROTATE_LEFT(arr, c) rotate((arr).begin(), (arr).begin()+(c), (arr).end())
#define ROTATE_RIGHT(arr, c) rotate((arr).rbegin(), (arr).rbegin() + (c), (arr).rend())
#define SUMI(arr) accumulate((arr).begin(), (arr).end(), 0)
#define SUMD(arr) accumulate((arr).begin(), (arr).end(), 0.)
#define SUMLL(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#define SUMS(arr) accumulate((arr).begin(), (arr).end(), string())
#define MULD(arr) accumulate((arr).begin(), (arr).end(), 1., multiplies<double>())
#define MULLL(arr) accumulate((arr).begin(), (arr).end(), 1LL, multiplies<long long>())
#define UB(arr, n) upper_bound((arr).begin(), (arr).end(), n)
#define LB(arr, n) lower_bound((arr).begin(), (arr).end(), n)
#define OF_ALL(arr, func) all_of((arr).begin(), (arr).end(), (func))
#define OF_NONE(arr, func) none_of((arr).begin(), (arr).end(), (func))
#define OF_ANY(arr, func) any_of((arr).begin(), (arr).end(), (func))
#define PB push_back
#define MP make_pair
#define ft first
#define sd second



// input output
//------------------------------------------
#define GL(s) getline(cin, (s))
#define INIT() std::ios::sync_with_stdio(false);std::cin.tie(0)
#define OUT(d) std::cout<<(d)
#define OUT_L(d) std::cout<<(d)<<endl
#define FOUT(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)
#define FOUT_L(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)<<"\n"
#define EL() printf("\n")
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v) {std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yay() printf("Yay!\n")
#define Nnn() printf(":(\n")


template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
    out << "[" << p.first << ", " << p.second << "]" << "\n";
    return out;
}


//repetition
//------------------------------------------
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORLL(i, a, b) for(LL i=LL(a);i<LL(b);++i)
#define RFORLL(i, a, b) for(LL i=LL(b)-1;i>=LL(a);--i)
#define REPLL(i, n) for(LL i=0;i<LL(n);++i)
#define RREPLL(i, n) for(LL i=LL(n)-1;i>=0;--i)
#define FOREACH(x, arr) for(auto &(x) : (arr))
#define FORITER(x, arr) for(auto (x) = (arr).begin(); (x) != (arr).end(); ++(x))

template<class T>
void chmin(T &a, const T b) { a = min(a, b); }
template<class T>
void chmax(T &a, const T b) { a = max(a, b); }

//------------------------------------------
//------------------------------------------

template<uint_fast64_t Modulas = 1000000007ul>
class ModInt {
    using u64 = uint_fast64_t;
public:
    u64 x;

    constexpr ModInt() : x(0) {}
    constexpr ModInt(const u64 x) : x(x % Modulas) {}
    constexpr ModInt operator+(const ModInt rhs) const noexcept {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt rhs) const noexcept {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt rhs) const noexcept {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt rhs) const noexcept {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt operator/(const long long rhs) const noexcept {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt operator+=(const ModInt rhs) noexcept {
        x += rhs.x;
        if (x >= Modulas) x -= Modulas;
        return *this;
    }
    constexpr ModInt operator+=(const long long rhs) noexcept {
        auto hs = ModInt<Modulas>(rhs);
        (*this) += hs;
        return *this;
    }
    constexpr ModInt operator-=(const ModInt rhs) noexcept {
        if (x < rhs.x) x += Modulas;
        x -= rhs.x;
        return *this;
    }
    constexpr ModInt operator-=(const long long rhs) noexcept {
        auto hs = ModInt<Modulas>(rhs);
        (*this) -= hs;
        return *this;
    }
    constexpr ModInt operator*=(const ModInt rhs) noexcept {
        x = x * rhs.x % Modulas;
        return *this;
    }
    constexpr ModInt operator*=(const long long rhs) noexcept {
        auto hs = ModInt<Modulas>(rhs);
        (*this) *= hs;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = Modulas - 2;
        while (exp > 0) {
            if (exp & 1ul) *this *= rhs;
            rhs *= rhs;
            exp >>= 1ul;
        }
        return *this;
    }
    constexpr ModInt &operator/=(long long rhs) noexcept {
        auto hs = ModInt<Modulas>(rhs);
        (*this) /= hs;
        return *this;
    }

    constexpr ModInt &operator++() noexcept {
        x++;
        if (x >= Modulas) x -= Modulas;
        return *this;
    }
    constexpr ModInt &operator--() noexcept {
        if (x == 0) x += Modulas;
        x--;
        return *this;
    }
    constexpr bool operator<(const ModInt rhs) const noexcept {
        return x < rhs.x;
    }
    constexpr bool operator==(const ModInt rhs) const noexcept {
        return this->x == rhs.x;
    }
    constexpr bool operator!=(const ModInt rhs) const noexcept {
        return !(*this == rhs);
    }
    friend istream &operator>>(istream &in, ModInt &m) {
        in >> m.x;
        m.x %= Modulas;
        return in;
    }
    friend ostream &operator<<(ostream &out, const ModInt &p) {
        out << p.x;
        return out;
    }
    constexpr ModInt pow(u64 p) const {
        ModInt ret(1);
        ModInt mul(x);
        while (p > 0) {
            if (p & 1ul) ret *= mul;
            mul *= mul;
            p >>= 1ul;
        }
        return ret;
    }
    constexpr ModInt operator~() const noexcept {
        u64 exp = Modulas - 2;
        return pow(exp);
    }

    constexpr static ModInt arith_sum(ModInt<Modulas> a, ModInt<Modulas> d, ModInt<Modulas> n) noexcept {
        return (a * ModInt<Modulas>(2) + (n - 1) * d) * n / ModInt<Modulas>(2);
    }
};

const LL MAX = 440000;

ModInt<> fac[MAX];
ModInt<> inv[MAX];

void setup() {
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    for (LL i = 2; i < MAX - 1; i++) {
        fac[i] = fac[i - 1] * i;
        inv[i] = ~fac[i];
    }
}

ModInt<> ncr(LL n, LL r) {
    return fac[n] * inv[r] * inv[n - r];
}

int main() {

    setup();

    LL N, M, K;
    cin >> N >> M >> K;

    // calc X
    ModInt<> X = 0;
    for (LL i = 0; i < M; i++) {
        X += i * (M - i) * N * N;
    }

    ModInt<> Y = 0;
    for (LL i = 0; i < N; i++) {
        Y += i * (N - i) * M * M;
    }

    ModInt<> ans = X + Y;
    ans *= ncr(N * M - 2, K - 2);

    cout << ans << endl;

    return 0;
}




































