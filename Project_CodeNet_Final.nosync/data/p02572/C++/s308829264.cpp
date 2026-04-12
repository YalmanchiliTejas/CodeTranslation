#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define Mp make_pair
#define pb push_back

using ll = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
mt19937 mrand(time(0));
ll get(ll r) { return ((ll)mrand() * mrand() % r + r) % r; }
ll get(ll l, ll r) { return get(r - l + 1) + l; }

const int P = 1e9 + 7;
ll n, a[200100];
signed main() {
    scanf("%lld", &n); ll sum = 0;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), (sum += a[i]) %= P;
    sum = sum * sum % P;
    for(int i = 1; i <= n; i++) (sum += P - a[i] * a[i] % P) %= P;
    printf("%lld\n", (sum * ((P + 1) / 2)) % P);
    fprintf(stderr, "time=%.4f\n", (db)clock()/CLOCKS_PER_SEC);
    return 0;
    /* 取模直接除，爆零两行泪
     * 不开ll见祖宗
     */
}