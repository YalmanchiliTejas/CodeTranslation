#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,n) for (int i = 1; i <= (int)(n); ++i)
#define repd(i,n) for (int i = (int)(n - 1); i >= 0; --i)
#define repds(i,n) for (int i = (int)(n); i > 0; --i)
#define loop(i,x,n) for (int i = (int)(x); i < (n); ++i)
#define loops(i,x,n) for (int i = (int)(x); i <= (n); ++i)
#define loopd(i,x,n) for (int i = (int)(x); i > (n); --i)
#define loopds(i,x,n) for (int i = (int)(x); i >= (n); --i)
#define itrep(i,a) for (auto i = begin(a); i != end(a); ++i)
#define itrepd(i,a) for (auto i = rbegin(a); i != rend(a); ++i)
#define all(f,x,...) [&](decltype(x)& whole) { return (f)(begin(whole), end(whole), ##__VA_ARGS__); }(x)
using namespace std;
using ll = long long;
using ld = long double;
template<class T> using priority_queuel = priority_queue<T, vector<T>, greater<T>>;
constexpr ll inf = static_cast<ll>(1e18);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e18;
constexpr double eps = 1e-10;
ll mod = static_cast<ll>(1e9 + 7);
template<class T> constexpr int sz(const T& a) { return (int)a.size(); }
template<class T> constexpr T pow2(const T a) { return a * a; }
template<class T, class ... Args> constexpr void mins(T& a, Args... args) { a = min<T>({ a, args... }); }
template<class T, class... Args> constexpr void maxs(T& a, Args... args) { a = max<T>({ a,args... }); }
template<class A, int N, class T>
void fillArray(A(&array)[N], const T& val) { std::fill((T*)array, (T*)(array + N), val); }

int n;
ll a[200005];
map<ll, ll> dp[200005];
void solve() {
    cin >> n;
    rep(i, n) cin >> a[i];

    dp[0][0] = 0;
    rep(i, n) for (auto& v : dp[i]) {
        auto ni = min(n, i + 2);
        auto nj = v.first + 1;
        if (nj >= max(0, (ni - 1) / 2) && nj <= (ni + 1) / 2) {
            auto val = dp[ni].try_emplace(nj, -inf).first;
            maxs(val->second, v.second + a[i]);
        }
        ni = i + 1;
        nj = v.first;
        if (nj >= max(0, (ni - 1) / 2) && nj <= (ni + 1) / 2) {
            auto val = dp[ni].try_emplace(nj, -inf).first;
            maxs(val->second, v.second);
        }
    }
    cout << dp[n][n / 2] << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
