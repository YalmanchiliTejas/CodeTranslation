#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <map>
typedef long long ll;
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define all(v) v.begin(), v.end()
#define ss second
#define ff first
#define pb push_back
#pragma GCC optimize("Ofast", "unroll-loops", "fast-math", "no-stack-protector")
#pragma GCC target("avx2")
using namespace std;
/*
string s;
vector < int > skobe;
ll mod = 998244353;
pair < pair < ll, ll >, pair < ll, ll > > ask(int l, int r) {
    if (l == r) return {{2, 2}, {2, 2}};
    int ind = skobe[l + 1] + 1;
    //cout << s[ind] << "- " << endl;
    auto k1 = ask(l + 1, skobe[l + 1]);
    auto k2 = ask(ind + 1, r - 1);
    pair < pair < ll, ll >, pair < ll, ll > > ans;
    if (s[ind] == '&') {
        ans.ff.ff = ((k1.ff.ff * k2.ff.ff) % mod) + ((k1.ff.ff * k2.ff.ss) % mod) + ((k1.ff.ss * k2.ff.ff) % mod);
        ans.ff.ss = ((k1.ff.ss * k2.ff.ss) % mod);
        ans.ss.ff = ((k1.ss.ff * k2.ss.ff) % mod) + ((k1.ss.ff * k2.ss.ss) % mod) + ((k1.ss.ss * k2.ss.ff) % mod);
        ans.ss.ss = ((k1.ss.ss * k2.ss.ss) % mod);
    }
    if (s[ind] == '|') {
        ans.ff.ff = ((k1.ff.ff * k2.ff.ff) % mod);
        ans.ff.ss = ((k1.ff.ff * k2.ff.ss) % mod) + ((k1.ff.ss * k2.ff.ff) % mod) + ((k1.ff.ss * k2.ff.ss) % mod);
        ans.ss.ff = ((k1.ss.ff * k2.ss.ff) % mod);
        ans.ss.ss = ((k1.ss.ff * k2.ss.ss) % mod) + ((k1.ss.ss * k2.ss.ff) % mod) + ((k1.ss.ss * k2.ss.ss) % mod);
    }
    if (s[ind] == '^') {
        ans.ff.ff = ((k1.ff.ff * k2.ff.ff) % mod) + ((k1.ff.ss * k2.ff.ss) % mod);
        ans.ff.ss = ((k1.ff.ff * k2.ff.ss) % mod) + ((k1.ff.ss * k2.ff.ff) % mod);
        ans.ss.ff = ((k1.ss.ff * k2.ss.ff) % mod) + ((k1.ss.ss * k2.ss.ss) % mod);
        ans.ss.ss = ((k1.ss.ff * k2.ss.ss) % mod) + ((k1.ss.ss * k2.ss.ff) % mod);
    }
    ans.ff.ff %= mod;
    ans.ff.ss %= mod;
    ans.ss.ff %= mod;
    ans.ss.ss %= mod;
    return ans;
}
ll step(ll x, ll a) {
    if (a == 0) return 1;
    if (a == 1) return x;
    if (a % 2 == 0) return step((x * x) % mod, a / 2);
    else return (step(x, a - 1) * x) % mod;
}
void solve() {
    cin >> s;
    int n = s.size();
    skobe.clear();
    skobe.resize(n);
    fori(n) skobe[i] = i;
    vector < int > buf;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') buf.pb(i);
        else if (s[i] == '(') {
            skobe[i] = buf.back();
            buf.pop_back();
        }
    }
    int cnt = 0;
    fori(n) if (s[i] == '#') cnt++;
    ll bib = step(4, cnt * 2);
    bib = step(bib, mod - 2);
    auto ans = ask(0, n - 1);
    cout << (ans.ff.ff * ans.ss.ff * bib) % mod << " ";
    cout << (ans.ff.ss * ans.ss.ss * bib) % mod << " ";
    cout << (ans.ff.ff * ans.ss.ss * bib) % mod << " ";
    cout << (ans.ff.ss * ans.ss.ff * bib) % mod << " ";
    cout << endl;
}
/// ((#|#)|((#&#)^#))
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}*/
int main() {
    int n;
    cin >> n;
    vector < ll > a;
    a.resize(n);
    fori(n) cin >> a[i];
    vector < ll > l, r;
    l.resize(n);
    r.resize(n);
    l[0] = a[0];
    l[1] = a[1];
    for (int i = 2; i < n; i++) {
        l[i] = l[i - 2] + a[i];
    }
    r[n - 1] = a[n - 1];
    r[n - 2] = a[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        r[i] = r[i + 2] + a[i];
    }
    if (n % 2 == 0) {
        ll ans = max(r[0], r[1]);
        for (int i = 0; i + 3 < n; i += 2) {
            ans = max(ans, l[i] + r[i + 3]);
        }
        cout << ans;
        return 0;
    }
    ll ans = r[1];
    for (int i = 1; i + 3 < n; i += 2) {
        ans = max(ans, l[i - 1] + r[i + 3]);
    }
    for (int i = 0; i + 1 < n; i++) {
        ll ans1 = 0;
        if (i != 0) ans1 += l[i - 1];
        if (i + 2 != n) ans1 += r[i + 2];
        ans = max(ans, ans1);
    }
    vector < ll > mxsum;
    mxsum.resize(n);
    if (n > 5) {
        mxsum[3] = a[3] + a[0];
        for (int i = 5; i < n; i += 2) {
            mxsum[i] = max(mxsum[i - 2] + a[i], a[i] + l[i - 3]);
        }
        for (int i = 3; i + 3 < n; i += 2) {
            ans = max(ans, mxsum[i] + r[i + 3]);
        }
    }
    cout << ans;
}
