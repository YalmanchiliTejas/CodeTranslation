#include <bits/stdc++.h>
using namespace std;

#define M_PI                                                                3.14159265358979323846
using ull = unsigned long long;
using ll = long long;
#define endl "\n"

#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define fill(x, y) memset(x, y, sizeof(x))
#define even(x) (x) % 2 == 0
#define odd(x) (x) % 2 != 0
#define all(x) x.begin(), x.end()
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define IN1(type, x) type x; cin >> x;
#define inll(x) ll x; cin >> x;
#define INIT() cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(20)

// these functions return the position of result of Binary Search.
#define LB(s, t, x) (int) (lower_bound(s, t, x) - s)
#define UB(s, t, x) (int) (upper_bound(s, t, x) - s)

const ll MOD_CONST = (ll)(1e9 + 7);
const ll CFM = (ll)(998244353);
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1) ans = 1ll * ans * a % mo; a = 1ll * a * a % mo; } while (b >>= 1); return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll temp = gcd(a, b); return temp ? (a / temp * b) : 0; }
int mDays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx8[] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dy8[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template<typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && __GNUC_PREREQ(3, 4)
__attribute__((warn_unused_result))
#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
FixPoint : F
{
public:
  explicit constexpr FixPoint(F&& f) noexcept
    : F(std::forward<F>(f))
  {}

  template<typename... Args>
  constexpr decltype(auto)
  operator()(Args&&... args) const
  {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};  // class FixPoint
template<typename F>
static inline constexpr decltype(auto)
makeFixPoint(F&& f) noexcept {
  return FixPoint<F>{std::forward<F>(f)};
}

template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts>
auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }

template <typename T>
vector<T> pows(int b, int n) { // vec{b^0, b^1, b^2, ...}
    vector<T> ret;
    T x = 1;
    while (ret.size() < n) {
        ret.push_back(x);
        x *= b;
    }
    return ret;
}
template <class T>
bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

inline tuple<ll, ll> rotate45(tuple<ll, ll> point) { ll x = get<0>(point), y = get<1>(point); return tuple<ll, ll>(x + y, x - y); }
inline bool rangeCheck2D(int nx, int ny, int Width, int Height) { return nx >= 0 and nx < Width and ny >= 0 and ny < Height; }

template <typename T>
vector<T> INPA(ll n) {
	vector<T> x;
	REP(i, n) {
		T tmp; cin >> tmp;
		x.push_back(tmp);
	}
	return move(x);
}
// base^x % MOD  - O(x)
ll p_base(ll base, ll x) {
	ll ans = 1;
	REP(i, x) {
		ans *= base;
		ans %= MOD_CONST;
	}
	return ans;
}
template <typename T>
void out(T o) { cout << o << endl; }
template <typename T>
void out(vector<T> &out) { REP(i, (int)out.size()) { cout << out[i]; if (i == (int)out.size() - 1) cout << endl; else cout << " "; } }
template <typename T>
void out(vector<vector<T>> o) { REP(i, o.size()) out(o[i]); }
void YesNo(bool f) { cout << (f?"Yes":"No") << endl; }
void YESNO(bool f) { cout << (f?"YES":"NO") << endl; }
string i_query(ll x, ll y) {
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    string ret; cin >> ret;
    return ret;
}
void i_answer(ll ans) {
    cout << "! " << ans << endl;
    fflush(stdout);
} 

// use " for (const auto& e : V)

// lambda expression
// auto f = [](int arg1, double arg2) { return ret; };
// lambda recursion
// auto result = makeFixPoint([&](auto rec, int pos, int v) -> int {
//	   rec(pos, v);
// })(0, 1);
// auto func = makeFixPoint([]() -> int {});
// int ret = func();

// tuple binding
// auto t = make_tuple(0, 0);
// int x, y; tie(x, y) = t;

// bitset<N> bs(ini_val); // N must be constant
// bs.reset(); // reset all

int main(void)
{
    INIT(); // comment out for Interective Program

    inll(N);
    auto a = INPA<ll>(N);

    auto dp = make_v<ll>(3010, 3010, 2);
    fill_v(dp, -1);
    auto result = makeFixPoint([&](auto rec, int l, int r, char turn) -> ll {
        if (dp[l][r][turn] != -1) return dp[l][r][turn];
        ll ret = 0;
        if (l == r) {
            if (turn) ret -= a[l];
            else ret += a[l];
        } else {
            char nturn = (turn)?0:1;
            if (turn) {
                ll getf = - a[l] + rec(l+1, r, nturn);
                ll getb = - a[r] + rec(l, r-1, nturn);
                ret += min(getf, getb);
            } else {
                ll getf = a[l] + rec(l+1, r, nturn);
                ll getb = a[r] + rec(l, r-1, nturn);
                ret += max(getf, getb);
            }
        }
        return dp[l][r][turn] = ret;
    })(0, N-1, 0);
    out(result);

	return 0;
}