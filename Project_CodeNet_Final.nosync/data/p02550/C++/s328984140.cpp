//
//#include <atcoder/fenwicktree>
//#include <atcoder/segtree>
//#include <atcoder/lazysegtree>
//#include <atcoder/string>
//#include <atcoder/math>
//#include <atcoder/convolution>
//#include <atcoder/modint>
//#include <atcoder/dsu>
//#include <atcoder/maxflow>
//#include <atcoder/mincostflow>
//#include <atcoder/scc>
//#include <atcoder/twosat>
//
#include <vector>
#include <set>
#include <map>
#include <array>
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <iomanip>
//
using ll = long long;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);++i)
#define outD(fpv) cout << setprecision(20) << fpv << endl;
inline void yes(bool cond) { cond ? puts("Yes") : puts("No"); }
inline void YES(bool cond) { cond ? puts("YES") : puts("NO"); }
template<typename Type> inline void chmin(Type& a, Type b) { if (a > b) a = b; }
template<typename Type> inline void chmax(Type& a, Type b) { if (a < b) a = b; }
template<typename Arr, typename Type> inline void fill(Arr& arr, Type v) { std::fill(arr.begin(), arr.end(), v); }
template<typename Type> inline void sort(Type& arr) { std::sort(arr.begin(), arr.end()); }
template<typename Type> inline void reverse(Type& arr) { reverse(arr.begin(), arr.end()); }
template<typename Type> inline Type nth(vector<Type>& arr, size_t pos) { std::nth_element(arr.begin(), arr.begin() + pos, arr.end()); return arr[pos]; }
template<typename Type> inline void unique(Type& arr) { sort(arr); arr.erase(unique(arr.begin(), arr.end()), arr.end()); }
constexpr ll INF_I = std::numeric_limits<ll>::max();
constexpr ll BIGP = 1000000007L;
constexpr double INF_F = std::numeric_limits<float>::infinity();
constexpr double PI = 3.14159265358979323846L;
using P = pair<ll, ll>;
//
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, X, M;
    cin >> N >> X >> M;

    // ループするまで回す
    ll A = X;
    ll loopStart = 0;
    ll loopLen = 0;
    ll loopTotal = 0;
    ll sigma = 0;
    struct Item
    {
        ll index;
        ll sigma;
    };
    map<ll, Item> apper; // (数値、Item)
    ll i = 0;
    for(i =0;;++i)
    {
        //
        auto ite = apper.find(A);
        if (ite != apper.end())
        {
            loopStart = ite->second.index;
            loopLen = i - ite->second.index;
            loopTotal = sigma - ite->second.sigma;
            break;
        }
        Item item = { i,sigma };
        apper.insert({ A, item });
        //
        sigma += A;
        A = (A * A) % M;
        //
        if (i+1 == N)
        {
            cout << sigma;
            return 0;
        }
    }
    //
    N -= loopStart;
    sigma += (N / loopLen - 1) * loopTotal;
    // 残りのループ分を出す
    ll remain = N % loopLen;
    for (ll i = 0; i < remain; ++i)
    {
        sigma += A;
        A = (A * A) % M;
    }
    cout << sigma;
    return 0;
}
//492443256280248
//492443256176507
//492443217470467
//       38706040
