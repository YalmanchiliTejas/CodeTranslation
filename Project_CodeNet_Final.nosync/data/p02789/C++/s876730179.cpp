// https://atcoder.jp/contests/abcXXX/tasks/abcXXX_x

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;

static const ll INF = 1001001001;
static const ll LLINF = 1001001001001001001;

#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define RANGE(i, m, n) for(ll i = (m); i <= (n); ++i)

void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 1
#endif

int run(istream& in, ostream& out) {
    ll N, M;
    in >> N >> M;
    ll ans = 0;

    // solution here

    out << (N == M  ? "Yes" : "No") << endl;
    return 0;
}

int main() {
    return run(cin, cout);
}
