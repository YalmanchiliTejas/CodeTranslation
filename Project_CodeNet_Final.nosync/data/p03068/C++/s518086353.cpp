// https://tenka1-2019-beginner.contest.atcoder.jp/tasks/tenka1_2019_b

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

#define EPS (1e-7)
#define INF (1e9)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// long gcd(long a, long b) { return b ? gcd(b, a % b) : a; }
// long lcm(long a, long b) { return a * b / gcd(a, b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> s >> k;
    char rep = s[k - 1];
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != rep) {
            s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}
