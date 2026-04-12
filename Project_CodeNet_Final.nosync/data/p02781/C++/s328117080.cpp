#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod = 1e9 + 7;
const LL N = 1e6 + 5;
const LL M = 1e3 + 5;
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define mid ((l + r) >> 1)
#define lson (l, mid)
#define rson (mid + 1, r)
#define r(a) read(a)
#define rr(a, b) r(a), r(b)
#define rrr(a, b, c) rr(a, b), r(c)
#define rrrr(a, b, c, d) rrr(a, b, c), r(d)
int n, m, k, T;
template <class T>
T read(T &x) {
    T f = 1;
    x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch - '0');
        ch = getchar();
    }
    x *= f;
}
LL qpow(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
LL ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL res = ex_gcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - a / b * y;
    return res;
}
LL prime[N + 10], phi[N + 10], mou[N + 10], cnt_prime;
bool judgeprime[N + 10];
void ouler() {
    phi[1] = mou[1] = 1;
    FOR(i, 2, N) {
        if (!judgeprime[i]) prime[cnt_prime++] = i, phi[i] = i - 1, mou[i] = -1;
        for (int j = 0; j < cnt_prime && i * prime[j] <= N; j++) {
            judgeprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                mou[i * prime[j]] = 0;
                break;
            } else {
                mou[i * prime[j]] = -mou[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}
LL C2(LL n) { return n < 2 ? 0 : n * (n - 1) / 2; }
LL C3(LL n) { return n < 3 ? 0 : n * (n - 1) * (n - 2) / 6; }
LL a[N], sum[N], ans;
int main() {
    string s;
    cin >> s;
    cin >> k;
    int len = s.size();
    if (k == 1ll) {
        ans += s[0] - '0';
        ans += 9 * (len - 1);
    }
    if (k == (LL)2) {
        if (len >= k) {
            int pos;
            for (int i = 1; i < len; i++)
                if (s[i] > '0') {
                    pos = i;
                    break;
                }
            ans += (s[pos] - '0') + (len - pos - 1) * 9 +
                   (s[0] - '0' - 1) * 9 * (len - 1);
            ans += C2(len - 1) * 81;
        }
    }
    if (k == (LL)3) {
        if (len >= k) {
            int pos = 0;
            for (int i = 1; i < len; i++) {
                if (s[i] > '0') {
                    pos = i;
                    break;
                }
            }
            int pos1 = 0;
            for (int i = pos + 1; i < len; i++) {
                if (s[i] > '0') {
                    pos1 = i;
                    break;
                }
            }
            if (pos1 > 0) {
                ans += (s[pos1] - '0') + 9 * (len - pos1 - 1);
            }
            if (pos > 0) {
                ans += (s[pos] - '0' - 1) * 9 * (len - pos - 1) + C2(len - pos - 1) * 81;
            }
            ans += (s[0] - '0' - 1) * C2(len - 1) * 81;
            ans += C3(len - 1) * 729;
        }
    }
    cout << ans << endl;
    return 0;
}