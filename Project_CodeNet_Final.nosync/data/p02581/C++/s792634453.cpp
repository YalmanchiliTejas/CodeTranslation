///////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

#define DEBUG 0

#define pb push_back
#define V vector
#define M unordered_map
#define S static

#define rep(i,n) for(ll i=0LL; i<n; ++i)
#define srep(i,s,n) for(ll i=s; i<n; ++i)
#define rrep(i,n) for(ll i=n-1LL; i>=0LL; --i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CIN(x) do { \
        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);
#if DEBUG
#define debug_print(...) _debug_print(__VA_ARGS__)
#define debug_printf(...) printf(__VA_ARGS__)
#define debug_print_time _debug_print_time
#else // DEBUG
#define debug_print(...)
#define debug_printf(...)
#define debug_print_time
#endif // DEBUG

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;

///////////////////////////////////////////////////////////////////////////////

template <typename TT, typename T>
T get_m(M<TT, T> &m, TT k, T default_value)
{
    if (m.find(k) == m.end()) return m[k] = default_value;
    return m[k];
}

template <typename TT, typename T>
void incr_m(M<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

template <typename TT, typename T>
void incr_m(map<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

void llin(ll &a)
{
    CIN(a);
}

void llinl1(V<ll> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void llinl2(V<t2> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void llinl3(V<t3> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void llinl4(V<t4> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(V<ll> &v, ll count)
{
    llinl1(v, count);
}

template <typename T>
void sort(V<T> &v)
{
    sort(v.begin(), v.end());
}

template <typename T>
void sort_reverse(V<T> &v)
{
    sort(v.begin(), v.end(), greater<T>());
}

template <typename T>
void _debug_print(T x)
{
    cout << x << endl;
}

void _debug_print(const t2 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    cout << "-- " << x1 << " -- " << x2 << endl;
}

void _debug_print(const t3 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    cout << "-- " << x1 << " -- " << x2 << " -- " << x3 << endl;
}

void _debug_print(const t4 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    cout << "-- " << x1 << " -- " << x2
         << " -- " << x3 << " -- " << x4 << endl;
}

template <typename T>
void _debug_print(T xarray[], ll n)
{
    rep (i, n) _debug_print(xarray[i]);
}

template <typename T>
void _debug_print(const V<T> &xlist)
{
    for (auto x : xlist) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename T>
void _debug_print(const set<T> &xset)
{
    for (auto x : xset) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename TT, typename T>
void _debug_print(const M<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "====" << endl;
        cout << "K=";
        _debug_print(k);
        cout << "V=";
        _debug_print(v);
    }
}

template <typename TT, typename T>
void _debug_print(const map<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "====" << endl;
        cout << "K=";
        _debug_print(k);
        cout << "V=";
        _debug_print(v);
    }
}

void _debug_print_time(const char *prefix)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
#if DEBUG
    struct tm *tm = localtime(&tv.tv_sec);
#endif
    debug_printf("-- %s %02d:%02d:%02d.%06ld\n",
                  prefix, tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_usec);
}

///////////////////////////////////////////////////////////////////////////////

void _main();
int main()
{
    cout << setprecision(12);
#if !DEBUG
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif

    _main();
    return 0;
}

S ll cnts[2005][2005];
S ll maxcnts[2005];
S ll updated[2005][2005];
S V<t2> updated_idxs;

void f_cnts(ll idx0, ll idx1, ll val)
{
    cnts[idx0][idx1] = max(cnts[idx0][idx1], val);
    maxcnts[idx0] = max(maxcnts[idx0], val);
    cnts[idx1][idx0] = max(cnts[idx1][idx0], val);
    maxcnts[idx1] = max(maxcnts[idx1], val);
}

void f_updated(ll idx0, ll idx1, ll val)
{
    updated[idx0][idx1] = max(updated[idx0][idx1], val);
    updated[idx1][idx0] = max(updated[idx1][idx0], val);
    updated_idxs.pb(t2(idx0, idx1));
}

void _main()
{
    ll n; llin(n);
    V<ll> alist; llina(alist, 3LL * n);

    rep (i, 2005) rep (j, 2005) cnts[i][j] = -1e18;
    rep (i, 2005) maxcnts[i] = -1e18;
    rep (i, 2005) rep (j, 2005) updated[i][j] = -1e18;
    f_cnts(alist[0], alist[1], 0);

    ll bonus = 0;

    rep (i, n-1) {
        debug_printf("-------------\n");
        debug_printf("---- cnts[1]\n");
        debug_print(cnts[1], 3);
        debug_printf("---- cnts[2]\n");
        debug_print(cnts[2], 3);

        ll a0 = alist[i*3+2];
        ll a1 = alist[i*3+3];
        ll a2 = alist[i*3+4];

        if (a0 == a1 && a1 == a2) {
            bonus++;
            continue;
        }

        ll allmax = -1e18;
        rep (j, 2005) allmax = max(allmax, maxcnts[j]);

        V<ll> as;
        as.pb(a0);
        as.pb(a1);
        as.pb(a2);
        updated_idxs.clear();

        rep (j, 3) {
            ll discard = as[j];
            ll remain0 = as[(j+1)%3];
            ll remain1 = as[(j+2)%3];
            ll newval = max(cnts[discard][discard] + 1LL, allmax);
            f_updated(remain0, remain1, newval);
        }

        rep (j, 3) {
            ll remain = as[j];
            ll discard0 = as[(j+1)%3];
            ll discard1 = as[(j+2)%3];
            rep (b, 2005) f_updated(remain, b, maxcnts[b]);
            if (discard0 == discard1) {
                rep (b, 2005) f_updated(remain, b, cnts[b][discard0] + 1LL);
            }
        }

        for (auto updated_idxs : updated_idxs) {
            ll idx0 = get<0>(updated_idxs);
            ll idx1 = get<1>(updated_idxs);
            f_cnts(idx0, idx1, updated[idx0][idx1]);
        }
    }

    debug_printf("-------------\n");
    debug_printf("---- cnts[1]\n");
    debug_print(cnts[1], 3);
    debug_printf("---- cnts[2]\n");
    debug_print(cnts[2], 3);

    ll la = alist[3*n-1];
    cnts[la][la]++;

    ll ans = -1e18;
    rep (i, 2005) rep (j, 2005) ans = max(ans, cnts[i][j]);
    ans += bonus;

    debug_printf("-------- ans\n");
    cout << ans << endl;
}

///////////////////////////////////////////////////////////////////////////////
