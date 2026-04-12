#include <bits/stdc++.h>
using namespace std;

namespace {
    #define DUMPOUT cerr
    #ifndef DEBUG_
    #define dump(...)
    #else
    #define dump(...)                                                                       \
        DUMPOUT << "  ";                                                                    \
        DUMPOUT << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl; \
        DUMPOUT << "    ";                                                                  \
        dump_func(__VA_ARGS__)
    #endif
    void dump_func()
    {
        DUMPOUT << endl;
    }
    template <class Head, class... Tail>
    void dump_func(Head &&head, Tail &&... tail)
    {
        DUMPOUT << head;
        if (sizeof...(Tail) == 0)
        {
            DUMPOUT << " ";
        }
        else
        {
            DUMPOUT << ", ";
        }
        dump_func(std::move(tail)...);
    }
    template <class T>
    ostream &operator<<(ostream &os, const vector<T> &v)
    {
        for (auto i = begin(v); i != end(v); ++i)
            os << *i << (i == end(v) - 1 ? "" : " ");
        return os;
    }
    template <class T>
    void out2Dvector(vector<T> v)
    {
        for (const auto &vv : v)
            cout << vv << endl;
    }
    template <class T>
    istream &operator>>(istream &is, vector<T> &v)
    {
        for (auto i = begin(v); i != end(v); ++i)
            is >> *i;
        return is;
    }
    template <typename T, typename U>
    ostream &operator<<(ostream &os, pair<T, U> &pair_var)
    {
        os << "(" << pair_var.first << ", " << pair_var.second << ")";
        return os;
    }
    template <typename T, typename U>
    ostream &operator<<(ostream &os, map<T, U> &map_var)
    {
        os << "{";
        for (auto itr = map_var.begin(); itr != map_var.end(); itr++)
        {
            os << "(" << itr->first << ", " << itr->second << ")";
            itr++;
            if (itr != map_var.end())
                os << ", ";
            itr--;
        }
        os << "}";
        return os;
    }
    template <typename T>
    ostream &operator<<(ostream &os, set<T> &set_var)
    {
        os << "{";
        for (auto itr = set_var.begin(); itr != set_var.end(); itr++)
        {
            os << *itr;
            ++itr;
            if (itr != set_var.end())
                os << ", ";
            itr--;
        }
        os << "}";
        return os;
    }
} // namespace

namespace {
    using ull = unsigned long long;
    using ll = long long;
    using ld = long double;

    #define REP(i, n) for (ll i = 0; i < n; i++)
    #define REPR(i, n) for (ll i = n; i >= 0; i--)
    #define FOR(i, m, n) for (ll i = m; i < n; i++)
    #define even(x) (x) % 2 == 0
    #define odd(x) (x) % 2 != 0
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define pcnt __builtin_popcount
    #define buli(x) __builtin_popcountll(x)
    #define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
    #define inp(t, x) \
        t x;          \
        cin >> x;
    #define ithBit(n, i) ((n) >> (i)&1)
    #define INIT()               \
        cin.tie(0);              \
        ios::sync_with_stdio(0); \
        cout << fixed << setprecision(20)

    // these functions return the position of result of Binary Search.
    #define LB(s, t, x) (int)(lower_bound(s, t, x) - s)
    #define UB(s, t, x) (int)(upper_bound(s, t, x) - s)

    #define M_PI 3.14159265358979323846
    ll qp(ll a, ll b, int mo)
    {
        ll ans = 1;
        do
        {
            if (b & 1)
                ans = 1ll * ans * a % mo;
            a = 1ll * a * a % mo;
        } while (b >>= 1);
        return ans;
    }
    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    ll lcm(ll a, ll b)
    {
        ll temp = gcd(a, b);
        return temp ? (a / temp * b) : 0;
    }
    int mDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int dx8[] = {1, -1, 0, 0, 1, 1, -1, -1}, dy8[] = {0, 0, -1, 1, -1, 1, -1, 1};

    template <typename F>
    class
    #if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
        [[nodiscard]]
    #elif defined(__GNUC__) && __GNUC_PREREQ(3, 4)
        __attribute__((warn_unused_result))
    #endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
        FixPoint : F {
            public :
                explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)) {}

            template <typename... Args>
            constexpr decltype(auto)
            operator()(Args &&... args) const {
                return F::operator()(*this, std::forward<Args>(args)...);
    } // namespace
    }
    ; // class FixPoint
    template <typename F>
    static inline constexpr decltype(auto)
    makeFixPoint(F &&f) noexcept
    {
        return FixPoint<F>{std::forward<F>(f)};
    }

    template <typename T>
    vector<T> make_v(size_t a) { return vector<T>(a); }
    template <typename T, typename... Ts>
    auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }
    template <typename T, typename U, typename... V>
    typename enable_if<is_same<T, U>::value != 0>::type
    fill_v(U &u, const V... v) { u = U(v...); }
    template <typename T, typename U, typename... V>
    typename enable_if<is_same<T, U>::value == 0>::type
    fill_v(U &u, const V... v)
    {
        for (auto &e : u)
            fill_v<T>(e, v...);
    }

    template <class T>
    bool chmax(T &a, const T &b)
    {
        if (a < b)
        {
            a = b;
            return 1;
        }
        return 0;
    }
    template <class T>
    bool chmin(T &a, const T &b)
    {
        if (b < a)
        {
            a = b;
            return 1;
        }
        return 0;
    }

    inline bool rangeCheck2D(int nx, int ny, int Width, int Height) { return nx >= 0 and nx < Width and ny >= 0 and ny < Height; }

    int i_query(int a, int b)
    {
        cout << "? " << a << " " << b << endl;
        fflush(stdout);
        ll ret;
        cin >> ret;
        return ret;
    }

    void i_answer(vector<ll> ans)
    {
        cout << "! " << ans << endl;
        fflush(stdout);
    }
} // namespace

/*
    tuple binding
    auto [x, y] = make_tuple(0, 0);
    for pair
    auto [a, b] = pair<int, int>({v1, v2});

    bitset<N> bs(ini_val); // N must be constant
    bs.reset(); // reset all
*/

namespace PrimeLib {
    //* 素数判定 is_prime<unsigned>(N)
    template<typename T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
    bool is_prime(const T n) {
        if (n < 4) return n == 2 || n == 3;
        if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
        for (T i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }
    //* 素数テーブル生成　エラトステネスの篩 10^7 => 1s
    //* 1e9を素因数分解したい時，sqrt(1e9)まで(31623程)を生成すればよい
    vector<ll> primeTable(ll n) {
        vector<bool> table(n - 1);
        vector<ll> ret;
        for (ll i = 0; i < n - 1; ++i) {
            if (table[i] == false) {
                ll num = i + 2;
                ret.push_back(i + 2);
                for (int j = i + num; j < n - 1; j += num)
                    table[j] = true;	
            }
        }
        return ret;
    }
    vector<pair<ll, ll>> factorize(ll n) {
        vector<pair<ll, ll>> ps;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                ps.emplace_back(i, cnt);
            }
        }
        //assert(c == 1);
        // if c is still not 1, 
        // there's one prime num bigger than sqrt(N)
        if (n > 1)
            ps.emplace_back(n, 1);
        return ps;
    }
    // 約数列挙
    std::vector<ll> divisors(ll n) {
        std::vector<ll> ret;
        for(ll i=1 ; i*i<=n ; ++i)
        {
            if(n%i == 0)
            {
                ret.push_back(i);
                if(i!=1 && i*i!=n)
                {
                    ret.push_back(n/i);
                }
            }
        }
        if (n > 1) ret.push_back(n);
        sort(all(ret));
        return ret;
    }
}

int main(void)
{
    INIT(); // comment out for Interective Problem
    
    inp(ll, N);
    multiset<ll> last;
    REP(i, N) {
        inp(ll, v);
        auto itr = last.lower_bound(v);
        if (itr != last.begin()) itr--;
        if (last.size() == 0 or (*last.begin() >= v)) {
            last.insert(v);
        } else {
            if (last.end() == itr)
                itr = --last.end();
            last.erase(itr);
            last.insert(v);
        }
    }
    cout << last.size() << endl;

    return 0;
}
//*/