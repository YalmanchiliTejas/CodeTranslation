#include <bits/stdc++.h>


using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,n) for (int i = 1; i <= (int)(n); ++i)
#define repd(i,n) for (int i = (int)(n - 1); i >= 0; --i)
#define repds(i,n) for (int i = (int)(n); i > 0; --i)
#define loop(i,x,n) for (int i = (int)(x); i < (n); ++i)
#define loops(i,x,n) for (int i = (int)(x); i <= (n); ++i)
#define loopd(i,x,n) for (int i = (int)(x); i > (n); --i)
#define loopds(i,x,n) for (int i = (int)(x); i >= (n); --i)
#define itrep(i,s) for (auto i = begin(s); i != end(s); ++i)
#define itrepd(i,s) for (auto i = rbegin(s); i != rend(s); ++i)
#define all(f,x,...) [&](decltype(x)& whole) { return (f)(begin(whole), end(whole), ##__VA_ARGS__); }(x)
#define rall(f,x,...) [&](decltype(x)& whole) { return (f)(rbegin(whole), rend(whole), ##__VA_ARGS__); }(x)
using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e17;
ll mod = static_cast<ll>(1e9 + 7);
std::ostream& endn(std::ostream& os) { return os.put(os.widen('\n')); }
template<class T> constexpr int sz(const T& a) { return (int)a.size(); }
template<class T> constexpr T pow2(const T a) { return a * a; }
template<class T, class ... Args> constexpr T mins(T& a, Args... args) { return a = min<T>({ a, args... }); }
template<class T, class... Args> constexpr T maxs(T& a, Args... args) { return a = max<T>({ a,args... }); }
template<typename A, size_t N, typename T>
void fillArray(A(&array)[N], const T& val) { std::fill((T*)array, (T*)(array + N), val); }

string s;
void solve() {
    cin >> s;

    if (s != "AAA" && s != "BBB") cout << "Yes" << endn;
    else cout << "No" << endn;

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    cout << flush;
    return 0;
}
