#define LOCAL

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <iomanip>

using namespace std;

// From Errichto's Youtube stream
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////
int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int64 result = 0;

    if (!K) {
        for (int b = 1; b <= N; b++) {
            for (int a = b; a <= N; a += b) {
                result++;
            }
        }
        K++;
    }

    for (int b = K + 1; b <= N; b++) {
        // a = K, K + b, K + 2 * b
        int cur = 0;
        int a = 0;
        for (a = K; a <= N; a += b) {
            //debug() << a << " " << b;
            cur++;
        }
        if (a > N)
            a -= b;

        if (b - K <= N - a + 1) {
            result += (int64)cur * (b - K);
        } else {
            result += (int64)cur * (N - a + 1);
            int dif = (b - K) - (N - a + 1);
            cur--;
            result += (int64)dif * cur;
        }
    }

    cout << result << "\n";

    return 0;
}
