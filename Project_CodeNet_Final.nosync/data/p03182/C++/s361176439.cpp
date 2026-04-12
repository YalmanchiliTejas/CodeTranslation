#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

//range maximum query and range add query 遅延評価セグメント木
template<typename T>
struct segtree {
    T L0 = 0;
    T INF = 0;
    int n;
    vector<T> lazy, dat;
 
    void init(int n_) {
        n = 1;
        while (n < n_) {
            n *= 2;
        }
        lazy.assign(2 * n - 1, L0);
        dat.assign(2 * n - 1, INF);
    }
 
    // void update(int k, T a) {
    //     k += n - 1;
    //     dat[k] = a;
    //     while (k > 0) {
    //         k = (k - 1) / 2;
    //         dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
    //     }
    // }

    void push(int k) {
        if (lazy[k] == L0) {
            return;
        }
        dat[k] += lazy[k];
        if (k < n - 1) {
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        lazy[k] = L0;
    }
    
    void baseadd(int a, int b, T x, int k, int l, int r) {
        push(k);
        if (a <= l && r <= b) {
            lazy[k] += x;
            push(k);
        } else if (l < b && a < r) {
            baseadd(a, b, x, k * 2 + 1, l, (l + r) / 2);
            baseadd(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void addquery(int a, int b, T x) {
        baseadd(a, b, x, 0, 0, n);
    }
 
    T basemax(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = basemax(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = basemax(a, b, k * 2 + 2, (l + r) / 2, r);
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
            return max(vl, vr);
        }
    }

    //[l, r)の範囲の最大値を返す
    T maxquery(int l, int r) {
        return basemax(l, r, 0, 0, n);
    }

    void update(int k, T a) {
        ll base = maxquery(k, k + 1);
        addquery(k, k + 1, a - base);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    tlglglg t[M];
    REP(i, 0, M) {
        ll l, r, a;
        cin >> l >> r >> a;
        t[i] = tlglglg(r - 1, l - 1, a);
    }
    sort(t, t + M);
    segtree<ll> seg;
    seg.init(N);
    ll ite = 0;
    REP(i, 0, N) {
        if (i == 0) {
            seg.update(i, 0);
        } else {
            seg.update(i, max(seg.maxquery(0, i), (ll)0));
        }
        while (get<0>(t[ite]) == i && ite < M) {
            ll l = get<1>(t[ite]);
            ll r = get<0>(t[ite]);
            ll a = get<2>(t[ite]);
            seg.addquery(l, r + 1, a);
            ite++;
        }
    }
    // REP(i, 0, N) {
    //     cout << seg.maxquery(i, i + 1) << " ";
    // }
    // cout << endl;
    ll ans = max(seg.maxquery(0, N), (ll)0);
    cout << ans << endl;
}
