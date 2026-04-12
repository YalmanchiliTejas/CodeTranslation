// clang-format off
#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define popcnt __builtin_popcount
#define ffs __builtin_ffs
#define ctz __builtin_ctz
#define clz __builtin_clz
#define all(a) (a).begin(), (a).end()
 
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using pll = pair<ll,ll>;
template <typename T> using vec = vector<T>;
using vi = vec<int>;
using vl = vec<ll>;
template <typename T> using que = queue<T>;
template <typename T> using deq = deque<T>;

template <typename T> T id(T b) {return b;};
template <typename T> void chmax(T &x, T y) {if (x < y) x = y;}
template <typename T> void chmin(T &x, T y) {if (x > y) x = y;}
template <typename S, typename K> bool contains(S &s, K k) { return s.find(k) != s.end(); }
void fastio() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
constexpr ll TEN(int n) { if (n == 0) return 1LL; else return 10LL*TEN(n-1); }
// clang-format on

int main() {
    fastio();

    int x, y, z;
    cin >> x >> y >> z;

    x -= z;

    cout << x / (y + z) << endl;

    return 0;
}