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

ll n, x, m, a[200100], l, r, sum, ans;
signed main() {
    cin >> n >> x >> m; set<ll> st; a[1] = x;
    for(r = 1; st.find(a[r]) == st.end(); r++)
        a[r + 1] = a[r] * a[r] % m, st.insert(a[r]);
    for(l = 1; a[l] != a[r]; l++);
    if(n <= r) {
        for(int i = 1; i <= n; i++)
            ans += a[i];
        cout << ans << endl;
        return 0;
    }
    for(int i = 1; i < l; i++) ans += a[i];
    for(int i = l; i < r; i++) sum += a[i];
    ll len = r - l; n -= l - 1, ans += n / len * sum, n %= len;
    for(int i = 0; i < n; i++) ans += a[l + i];
    cout << ans << endl;
    fprintf(stderr, "time=%.4f\n", (db)clock()/CLOCKS_PER_SEC);
    return 0;
    /* 取模直接除，爆零两行泪
     * 不开ll见祖宗
     */
}