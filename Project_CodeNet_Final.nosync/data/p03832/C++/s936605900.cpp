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

const int MOD = 1000000007;

int N, A, B, C, D;

vector<vector<int>> dp, sum;
vector<int> fact, invfact;

void add (int & a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int mul (int a, int b) {
    return (int64)a * b % MOD;
}

int fast_pow(int a, int p) {
    if (p == 0) return 1;
    if (p == 1) return a;
    int res = fast_pow(a, p / 2);
    res = mul(res, res);
    if (p & 1)
        res = mul(res, a);
    return res;
}

int inverse(int a) {
    return fast_pow(a, MOD - 2);
}

int Choose (int n, int k) {
    if (k == 0)
        return 1;
    if (n == k)
        return 1;
    return mul(fact[n], mul(invfact[n-k], invfact[k]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> A >> B >> C >> D;

    fact.resize(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = mul(fact[i-1], i);

    invfact.resize(N + 1);
    invfact[N] = inverse(fact[N]);
    for (int i = N - 1; i >= 0; i--) {
        invfact[i] = mul(invfact[i + 1], i + 1);
    }

    dp = vector<vector<int>> (N + 1, vector<int>(N + 1));
    //dp[0][A - 1] = 1;

    sum = dp;
    for (int i = 0; i <= B; i++)
        sum[0][i] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = A; j <= B; j++) {
            if (j <= i) {
                for (int k = C; k <= D && i - j * k >= 0; k++) {
                    //debug() << i << " take " << j << " times " << k;
                    int multiplier = Choose(i, k * j);

                    //debug() << multiplier;

                    multiplier = mul(multiplier, fact[k * j]);
                    multiplier = mul(multiplier, invfact[k]);

                    
                    int inverse_pow = fast_pow(invfact[j], k);
                    multiplier = mul(multiplier, inverse_pow);

                    //debug() << multiplier;
                    //debug() << "sum " << i - k * j << ", " << j - 1;

                    add (dp[i][j], mul(sum[i - k * j][j-1], multiplier));
                }
            }

            //debug() << "dp " << i << "," << j << " = " << dp[i][j];

            sum[i][j] = sum[i][j-1];
            add(sum[i][j], dp[i][j]);
        }
    }

    cout << sum[N][B] << "\n";

    return 0;
}
