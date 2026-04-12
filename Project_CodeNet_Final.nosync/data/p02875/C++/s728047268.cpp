#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = (int)1e6 * 5 + 10;
int fact[maxN], invfact[maxN], inv[maxN];
int n;
int pref[maxN];
int pw2[maxN];
int cnk(int a, int b) {
    if (a < b || b < 0) return 0;
    return mult(fact[a], mult(invfact[a - b], invfact[b]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    n /= 2;
    fact[0] = invfact[0] = inv[1] = fact[1] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(mod - mod / i, inv[mod % i]);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    pw2[0] = 1;
    for (int i = 1; i < maxN; i++) pw2[i] = mult(2, pw2[i - 1]);
    for (int i = 0; i <= n; i++) {
        pref[i] = mult(pw2[i], cnk(n, i));
        if (i > 0) pref[i] = sum(pref[i], pref[i - 1]);
    }
    int coef = 1;
    for (int i = 0; i < 2 * n; i++) coef = mult(coef, 3);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot = sum(tot, mult(pref[i - 1], mult(cnk(n, i), pw2[n - i])));
    }
    coef = sub(coef, mult(2, tot));
    cout << coef;
    return 0;
}