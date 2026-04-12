#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
template<class T> using PQ = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);++(i))
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);++(i))
#define rFOR(i,a,n) for(int (i)=(n)-1;(i)>=(a);--(i))
#define erFOR(i,a,n) for(int (i)=(n);(i)>=(a);--(i))
#define each(i, a) for(auto &i : a)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
#define out(y,x) ((y) < 0 || h <= (y) || (x) < 0 || w <= (x))
#define line cout << "-----------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
#define stop system("pause")
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
constexpr ld eps = 1e-10;
constexpr ld pi = 3.1415926535897932;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& is, vector<T>& v) { for (auto& elemnt : v)is >> elemnt; return is; }
template<class T>inline istream& operator>>(istream& is, deque<T>& v) { for (auto& elemnt : v)is >> elemnt; return is; }
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T>inline vector<T> vec(size_t a) { return vector<T>(a); }
template<class T>inline vector<T> defvec(T def, size_t a) { return vector<T>(a, def); }
template<class T, class... Ts>inline auto vec(size_t a, Ts... ts) { return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...)); }
template<class T, class... Ts>inline auto defvec(T def, size_t a, Ts... ts) { return vector<decltype(defvec<T>(def, ts...))>(a, defvec<T>(def, ts...)); }

int main() {
    init();

    int n; cin >> n;
    VL a(n); cin >> a;
    ll ans = 0;
    while (*max_element(all(a)) >= n) {
        ll sum = 0;
        each(i, a)sum += i / n;
        each(i, a)i = i % n + sum - i / n;
        ans += sum;
    }
    cout << ans << "\n";
}