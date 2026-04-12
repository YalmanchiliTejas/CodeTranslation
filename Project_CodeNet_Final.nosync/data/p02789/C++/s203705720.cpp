#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
using namespace std;
typedef long long int ll;

// clang-format off
#ifdef _DEBUG_
#define dump(...) do{ cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; PPPPP(__VA_ARGS__); cerr << endl; } while(false)
template<typename T> void PPPPP(T t) { cerr << t; }
template<typename T, typename... S> void PPPPP(T t, S... s) { cerr << t << ", "; PPPPP(s...); }
#else
#define dump(...)
#endif
template<typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
template<typename T>
bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false;}
template<typename T>
bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false;}
// clang-format on

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << (a == b ? "Yes" : "No") << endl;
    return 0;
}
