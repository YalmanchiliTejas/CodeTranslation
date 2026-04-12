#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rrep(i, n) for(ll i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
template <class X> void print(X x) { cout << x << endl; }
#define in(A, n)                                                                                                       \
    rep(i, n) {                                                                                                        \
        cin >> f;                                                                                                      \
        A.push_back(f);                                                                                                \
    }

void print(vl x) {
    for(ll i : x) {
        cout << i << " ";
    }
    cout << endl;
}
const ll INF = (1LL << 61) - 1;
const ll MOD = 1000000007 /*998244353*/;
const ll MAX_N = 500010;
ll a, b, c, d, e, f, h, x, y, z, p, q, n, t, r, k, w, l, ans, i, j, u, v, m;
ll codeforces = 1;
string S, T;
vector<vl> g(MAX_N);
vl A, B;
void input() { cin >> n >> x >> m; }
void solve() {
    vl syuki(m, 0);
    while(syuki[x] == 0) {
        A.pb(x);
        syuki[x]++;
        x = (x * x) % m;
    }

    rep(i, A.size()) {
        if(A[i] == x) {
            a = i;
            break;
        }
    }

    // print(A);
    // print(a);
    if(n < a) {
        rep(i, n) { ans += A[i]; }
        print(ans);
    } else {
        rep(i, a) { ans += A[i]; }
        n -= a;
        k = n / (A.size() - a);
        t = n % (A.size() - a);
        rep(i, A.size() - a) { p += A[i + a]; }
        ans += p * k;
        rep(i, t) { ans += A[i + a]; }
        print(ans);
    }
}
int main() {
    // cout<<fixed<<setprecision(15);
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    while(codeforces--) {
        solve();
    }
}