//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
////
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

#include <random>

#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()

#define pb push_back


using namespace std;
void dout() { cerr << endl; }
//typedef long long ll;
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

using ll = long long;
//#ifdef __int128
//using hll = __int128;
//#endif
using pii = pair<ll, ll>;
using ld = long double;
using pll = pair<long long, long long>;

template <typename T>
void do_uniq(vector<T> vec){
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}

clock_t timestamp_start = clock();
void time_calc()
{
    cerr << (ld)(clock() - timestamp_start) / CLOCKS_PER_SEC << "\n";
}


#ifdef _getchar_nolock
#else
#define _getchar_nolock getchar_unlocked
#endif

//#define solvsh
//#define multi

#ifdef solvsh
#else

ll mod = 998244353;

ll add(ll a, ll b){
    return (a + b) % mod;
}
ll ml(ll a, ll b) {
    return (a * b) % mod;
}

ll sub(ll a, ll b) {
    return add(a, mod - b);
}

ll b_p(ll b, ll p) {
    if (p == 0) return 1;
    if (p & 1) return ml(b, b_p(b, p ^ 1));
    ll v = ml(b, p >> 1);
    return ml(v, v);
}

const int MAXN = 1e5 + 132;

bool was[MAXN];

void solve() {

    ll n, x, m;
    cin >> n >> x >> m;

    mod = m;

    ll len = 0;

    ll curr = x;
    ll cycle_val = 0;

    while (!was[curr]) {
        was[curr] = true;
        cycle_val += curr;
        ++len;
        curr = ml(curr, curr);
    }

    ll start = x;

    ll answr = 0;

    while (start != curr) {
        answr += start;
        start = ml(start, start);
        --len;
        --n;
    }
    cycle_val -= answr;

    ll cnt = n / len;
    answr += cnt * cycle_val;

    for (int i = 0; i < n % len; ++ i) {
        answr += curr;
        curr = ml(curr, curr);
    }

    cout << answr << "\n";
}

#endif

void multisolve() {
    int t;
    cin >> t;

    int i = 1;
    while (t--) {
        solve();
        i++;
    }
}

#define int int
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(20);

#ifdef multi
    //        gen();
    multisolve();
#else
    solve();
//    gen();
#endif
//    time_calc();
}
