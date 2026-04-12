/*
    ahuhu :((
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

#define SZ size()
#define BG begin()
#define ED end()
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define FOR(i, a, b)  for (int i = (a), _b = (b);  i< _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define openfile ({freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);})

typedef vector <int> VI;
typedef pair <int, int> II;
typedef long long LL;
typedef long double LD;

const int N = (int) (2505);
const int LOGN = log2(N) + 2;
const LL MOD = (LL) (1e9 + 7);
const LL INF = (LL) 1e18;
const double PI = 2 * acos(0);
const double EPS = 1e-9;

template <typename T> inline void read(T &n) {
    n = 0; char ch; bool neg = false;
    for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') neg = !neg; n = ch - 48;
    for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar()) n = (n << 1) + (n << 3) + ch - 48; if (neg) n = -n;
}
template <typename T> inline void writee(T n) { if (n > 9) writee(n / 10); putchar(n % 10 + 48); }
template <typename T> inline void write(T n) { if (n < 0) { putchar('-'); n = -n; } writee(n); }
template <typename T> inline void writeln(T x) { write(x); putchar('\n'); }
inline long long __lcm(long long a, long long b) { return a / __gcd(a, b) * b; }
inline long long power(long long a, long long n) {
    long long r = 1;
    while (n) {
        if (n & 1) r = r * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return r;
}
inline void add(int &a, const int& b) { a = (a + b) % MOD; }
inline void sub(int &a, const int& b) { a = (a - b + MOD) % MOD; }

char s[10];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> s + 1;
    int n = strlen(s + 1);
    for (int i = 1; i < n; i++)
        if (s[i] == 'A' && s[i + 1] == 'C') return cout << "Yes\n", 0;
    cout << "No\n";
    return 0;
}
