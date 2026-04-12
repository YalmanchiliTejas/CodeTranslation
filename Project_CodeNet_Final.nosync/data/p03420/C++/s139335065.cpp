#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vs = vector<string>;
using vp = vector<pii>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (ll)((x).size())
#define all(x) (x).begin(), (x).end()
#define each(a, x) for (auto&& a : (x))
#define _overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) rep2(_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, n) rep4(i, a, n, 1)
#define rep4(i, a, n, s) for (ll i = (a); i < (n); i += (s))
#define rep(...) _overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
template<typename T> inline void chmax(T& a, const T& b) {if (a < b) a = b;}
template<typename T> inline void chmin(T& a, const T& b) {if (a > b) a = b;}
template<typename T> inline void print(const T& x) {cout << x << "\n";}
struct Init {Init() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} init;

int main() {
    ll n, k;
    cin >> n >> k;
    ll res = 0;
    if (k == 0) res = n * n;
    else {
        rep(b, k + 1, n + 1) {
            ll tmp = (n / b) * (b - k);
            if (n % b != 0) tmp += max(0LL, (n % b) - k + 1);
            res += tmp;
        }
    }
    print(res);
}