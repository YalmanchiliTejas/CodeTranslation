#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

#define M 1000'000'007ll
int n;
vector<ll> v, s;

int main() {
    cin >> n;
    v.resize(n);
    s.resize(n);
    rep(i, n) cin >> v[i];
    s.back() = v.back();
    rrep(i, n - 1) { s[i] = (s[i + 1] + v[i]) % M; }
    ll ans = 0;
    rep(i, n - 1) { ans = (ans + s[i + 1] * v[i]) % M; }
    cout << ans << endl;
    return 0;
}