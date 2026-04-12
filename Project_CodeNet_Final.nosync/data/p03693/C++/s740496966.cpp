#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <string>
#include <cstring>
#include <cctype>
#include <numeric>
#include <cstdio>
#include <math.h>
#include <functional>
using namespace std;
struct initon
{
    initon()
    {
        cin.tie(0);
        ios::sync_with_stdio(false);
    };
};
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvi = vector<vi>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using vp = vector<P>;
using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
using f80 = __float80;
constexpr i64 INF = 1'010'000'000'000'000'017LL;
constexpr i64 MOD = 1'000'000'007LL;
constexpr f64 EPS = 1e-12;
constexpr f64 PI = 3.14159265358979323846;
#define rep(i, n) for (i64 i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (i64 i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RS(x) rsort(x.begin(),x,end()))
#define REVE(x) reverse(x.begin(), x.end())
#define all(x) (x).begin(), (x).end()
#define fst first
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define sw swap
#define UP(x) transform(x.begin(), x.end(), x.begin(), ::toupper);
#define LOW(x) transform(x.begin(), x.end(), x.begin(), ::tolower);
#define na(a, n) rep(i, n) cin >> a[i];
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
vb d(10);
int ans(int x)
{
    while (x)
    {
        if (d[x % 10])
            return 0;
        x /= 10;
    }
    return 1;
}
//ここからメイン
int main()
{
    int r, g, b, a;
    cin >> r >> g >> b;
    a = 100 * r + 10 * g + b;
    if (a % 4 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}