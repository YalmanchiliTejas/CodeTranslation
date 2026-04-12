#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <tuple>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
using namespace std;
using ll = long long int;
using P = pair<ll, ll>;

// clang-format off
#ifdef _DEBUG_
#define dump(...) do{ cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; PPPPP(__VA_ARGS__); cerr << endl; } while(false)
template<typename T> void PPPPP(T t) { cerr << t; }
template<typename T, typename... S> void PPPPP(T t, S... s) { cerr << t << ", "; PPPPP(s...); }
#else
#define dump(...) do{ } while(false)
#endif
template<typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
template<typename T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template<typename T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }
template<typename T> void print(T a) { cout << a << endl; }
template<typename T, typename... Ts> void print(T a, Ts... ts) { cout << a << ' '; print(ts...); }
template<typename T> istream &operator,(istream &in, T &t) { return in >> t; }
// clang-format on

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, x, m;
    cin, n, x, m;
    const int sz = 100010;
    vector<P> arr(sz, P(-1, -1));
    ll sum = 0;
    REP(i, 1, m + 2) {
        sum += x;
        x = (x * x) % m;
        if (arr[x].first != -1) {
            ll loop = i - arr[x].first;
            ll tail = arr[x].first;
            ll rest = (n - tail) % loop;
            ll diff = sum - arr[x].second;
            ll tails = arr[x].second;
            sum = tails + (n - tail) / loop * diff;
            REP(j, 0, rest) {
                sum += x;
                x = (x * x) % m;
            }
            break;
        }
        arr[x] = P(i, sum);
        if (i == n) break;
    }
    print(sum);
    return 0;
}
