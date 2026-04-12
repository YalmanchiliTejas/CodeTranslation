//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
////
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>

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

ll mod = 1e9 + 7;

ll add(ll a, ll b){
    return (a + b) % mod;
}
ll mult(ll a, ll b) {
    return (a * b) % mod;
}


const int MAXN = 205;
const int MAXK = 20 + 3;

ll bin_pw(ll base, ll p) {
    if (p == 0)return 1;
    if (p & 1) return mult(base, bin_pw(base, p - 1));
    ll v = bin_pw(base, p >> 1);
    return mult(v, v);
}

ll get_back(ll elem){
    return bin_pw(elem, mod - 2);
}

void solve() {

    int n;
    cin >> n;

    vector<ll>  v;

    for (int i = 0; i < n; ++ i){
        ll curr;
        cin >> curr;
        v.push_back(curr);
    }


    ll summ = 0;
    ll summ_sq = 0;
    for (int i = 0; i < n; ++ i) {
        summ = add(summ, v[i]);
        summ_sq = add(summ_sq, mult(v[i], v[i]));
    }

    ll ans = mult(summ, summ) - summ_sq;
    ans += mod;
    ans %= mod;

    ans = mult(ans, get_back(2));


    cout << ans;
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

#ifndef ONLINE_JUDGE
//    freopen("../input.in", "r", stdin);
#else

#endif
#ifdef multi
//        gen();
    multisolve();
#else
    solve();
//    gen();
#endif

}
