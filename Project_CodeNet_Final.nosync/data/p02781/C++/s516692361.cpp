#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
const int N = 1e3 + 10;
char s[N];
ll K, a[N];
const ll d[] = {1, 9, 81, 729};

ll C(ll x, ll k) {
    if (k == 1) return x;
    else if (k == 2) return x * (x - 1) / 2;
    else return x * (x - 1) * (x - 2) / 6;
}

ll solve(ll now, ll k, bool f) {
    if (now < k) return 0;
    if (!k) return 1;
    if (f) return C(now, k) * d[k];
    ll ret = solve(now - 1, k, a[now] ? 1 : f);
    if (a[now])
        ret += solve(now - 1, k - 1, f) + solve(now - 1, k - 1, 1) * (a[now] - 1);
    return ret;
}

int main() {
    scanf("%s", s + 1);
    ll n = strlen(s + 1);
    rep(i, 1, n) a[i] = s[i] - '0';
    reverse(a + 1, a + n + 1);
    cin >> K;
    printf("%lld\n", solve(n, K, 0));
    return 0;
}
