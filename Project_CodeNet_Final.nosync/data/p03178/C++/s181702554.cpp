#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT_ON(bit, i) (((bit >> i) & 1) > 0)
#define BIT_COUNT(bit) (__builtin_popcount(bit))

typedef long long LL;
template<typename T> std::vector<T> make_v(size_t a){return std::vector<T>(a);}
template<typename T,typename... Ts> auto make_v(size_t a, Ts... ts){ return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}    // C++14
template<typename T,typename V> typename std::enable_if<std::is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename std::enable_if<std::is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
template<class T> inline T ceil(T a, T b) { return (a + b - 1) / b; }
template<class T> inline void print(T x) { std::cout << x << std::endl; }
template<class T> inline void print_vec(const std::vector<T> &v) { for (int i = 0; i < v.size(); ++i) {  if (i != 0) {std::cout << " ";} std::cout << v[i];} std::cout << "\n"; }
template<class T> inline bool inside(T y, T x, T H, T W) {return 0 <= y and y < H and 0 <= x and x < W; }
template<class T> inline double euclidean_distance(T y1, T x1, T y2, T x2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
template<class T> inline double manhattan_distance(T y1, T x1, T y2, T x2) { return abs(x1 - x2) + abs(y1 - y2); }
template<typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template<typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }

template<class T> inline std::vector<T> unique(std::vector<T> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}
// 初項s, 交差dのn個の数列の和
long long sum_of_arithmetic_progression(long long s, long long d, long long n) {
    return n * (2 * s + (n - 1) * d) / 2;
}

// 2のべき乗数かどうか
bool is_power_of_two(long long x) {
    return !(x & (x - 1));
}

// aとbの最大公約数 O(log min(a, b))
long long gcd(long long a, long long b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

// 数列vの最大公約数 O(N log d)
long long gcd(std::vector<long long> &v) {
    long long ans = v[0];
    for (int i = 1; i < (int)v.size(); ++i) {
        ans = gcd(ans, v[i]);
    }
    return ans;
}

// aとbの最小公倍数 O(log min(a, b))
long long lcm(long long a, long long b) {
    long long g = gcd(a, b);
    return a / g * b;
}

const int INF = 1 << 30;
const double EPS = 1e-9;
const long double PI = acos(-1.0);
const std::vector<int> dy2 = {0, 1}, dx2 = {1, 0};  // 右，下
const std::vector<int> dy4 = {0, -1, 0, 1}, dx4 = {1, 0, -1, 0};    // 右，上，左，下
const std::vector<int> dy8 = { 0, -1, 0, 1, 1, -1, -1, 1 }, dx8 = { 1, 0, -1, 0, 1, 1, -1, -1 };

using namespace std;

int mod = 1000000000 + 7;

vector<vector<vector<LL>>> dp;
long long func(int d, bool is_tight, const string &s, int D, int r) {
    if (d >= s.size()) {
        return r == 0;
    }

    if (dp[d][is_tight][r] != -1) {
        return dp[d][is_tight][r];
    }

    int upper = 9;
    if (is_tight) {
        upper = s[d] - '0';
    }

    long long ans = 0;
    for (int i = 0; i < upper + 1; ++i) {
        ans += func(d + 1, i == upper && is_tight, s, D, (r + i) % D);
        ans %= mod;
    }

    return dp[d][is_tight][r] = ans;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string K;
    LL D;
    cin >> K;
    cin >> D;

    dp.resize(K.size() + 10, vector<vector<LL>>(2, vector<LL>(110, -1)));
    print((func(0, true, K, D, 0) + mod - 1) % mod);

    return 0;
}
