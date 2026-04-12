#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double LD;
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const ll INF64 = 4e18;
const double INFD = 1e30;
const double EPS = 1e-10;
const long double PI = acosl(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}
const int MAXN = 117777;
const int MAXV = 100005;
int n, m, k;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;

int rem[MAXN];
int app[MAXV];
ll pref[MAXN];
int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ll a = read<ll>();
    int x = read<int>();
    int m = read<int>();
    rem[1] = x % m;
    app[rem[1]] = 1;
    int base = 1;
    int length = 0;
    for (ll i = 2; i <= a; i++) {
        rem[i] = (ll)rem[i - 1] * rem[i - 1] % m;
        if (app[rem[i]]) {
            base = app[rem[i]];
            length = i - base;
            break;
        }
        app[rem[i]] = i;
    }
    if (!length) length = a;
    for (int i = 1; i < base + length; i++) {
        pref[i] = pref[i - 1] + rem[i];
    }
    ll ans = 0;
    if (a >= base - 1) {
        ans += pref[base - 1];
        a -= base - 1;
    }
    ll cyc = pref[base + length - 1] - pref[base - 1];
    ans += cyc * (a / length);
    ans += (pref[(a % length) + base - 1] - pref[base - 1]);
    printf("%lld\n", ans);
    return 0;
}