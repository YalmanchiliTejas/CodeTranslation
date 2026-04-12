// >>> TEMPLATES
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define rep1(i,n) for (int i = 1; i <= int(n); i++)
#define repR(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = int(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#ifdef LOCAL
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", dump_impl(#__VA_ARGS__, __VA_ARGS__)
#define say(x) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] " << x << endl;
#define debug if (1)
void dump_impl(const char*) { cerr << endl; }
template <class T, class... U> void dump_impl(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; dump_impl(s, y...); }
#else
#define dump(...)
#define say(x)
#define debug if (0)
#endif
using ll = long long;
using ld = long double;
#define int ll
#define double ld
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { os << "{"; for (auto const& x : v) os << " " << x; return os << " }"; }
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
template <size_t i, class T> typename enable_if<i >= tuple_size<T>::value>::type output_tuple(ostream&, T const&) { }
template <size_t i = 0, class T> typename enable_if<i < tuple_size<T>::value>::type
output_tuple(ostream& os, T const& t) { os << (i ? " " : "") << get<i>(t); output_tuple<i+1,T>(os,t); }
template <class... T> ostream& operator<<(ostream& os, tuple<T...> const& t) { return output_tuple(os,t), os; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
const ll INF = (1LL<<62)-1; // ~ 4.6e18
// <<<

int32_t main() {
    int n,k; cin >> n >> k;

    int cnt = 0;
    loop (b,k+1,<=n) {
        for (int q = 0; b*q+k <= n; q++) {
            cnt += min(b-1,n-b*q)-k+1-(k==0 && q ==0);
        }
    }
    cout << cnt << endl;

}
