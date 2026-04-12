#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
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
#define line cout << "------------------------\n" 
#define ENDL(i,n) ((i) == (n) - 1 ? "\n" : " ")
#define stop system("pause")
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
const long double pi = acos(-1);
const long double eps = 1e-10;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& is, vector<T>& v) { for (auto& elemnt : v)is >> elemnt; return is; }
template<class T, class U>inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template<class T>inline vector<T> vec(size_t a) { return vector<T>(a); }
template<class T>inline vector<T> defvec(T def, size_t a) { return vector<T>(a, def); }
template<class T, class... Ts>inline auto vec(size_t a, Ts... ts) { return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...)); }
template<class T, class... Ts>inline auto defvec(T def, size_t a, Ts... ts) { return vector<decltype(defvec<T>(def, ts...))>(a, defvec<T>(def, ts...)); }

int n;
VL a;
vector<VL> memo;
ll solve(int l, int r){
    if(r < l)return 0LL;
    if(memo[l][r] != -1)return memo[l][r];

    ll ret = 0;
    if((r - l) % 2 != n % 2){
        ret = max(solve(l + 1, r) + a[l], solve(l, r - 1) + a[r]);
    }
    else{
        ret = min(solve(l + 1, r) - a[l], solve(l, r - 1) - a[r]);
    }
    
    return memo[l][r] = ret;
}

int main() {
    init();

    cin >> n;
    a.resize(n); cin >> a;
    memo = defvec<ll>(-1, n, n);
    cout << solve(0, n - 1) << "\n";
}
