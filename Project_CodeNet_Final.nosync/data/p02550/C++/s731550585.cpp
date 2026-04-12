#include <bits/stdc++.h>
using namespace std;

#ifdef _LOCAL
    #include <utils/debug.hpp>
    #include <utils/random_generate.hpp>
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
    #define generate_string(...) 42
    #define generate_array(...) 42
    #define generate_unique_array(...) 42
#endif

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vl2;
const bool multiple_queries = false;
#define rep(i, n) for(ll i = 0; i < (n) ; ++i)
#define For(i, a, b) for(ll i = (a); i < (b) ; ++i)
#define revrep(i, n) for(ll i = (n) - 1; i >= 0 ; --i)
#define revFor(i, b, a) for(ll i = (b) - 1; i >= (a) ; --i)
#define all(v) v.begin(), v.end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(i) __builtin_popcountl((i))
#define substring(s, start, end) s.substr((start), (end) - (start) + 1)

void scan(){}
template <class Head, class... Tail>
void scan(Head&& head, Tail&&... tail) {
    cin >> head;
    scan(forward<Tail>(tail)...);
}

void print(){}
void println(){cout << endl;}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T>& vs){
    for (auto v: vs){
        cout << v;
        if (&v != &vs.back()) cout << " ";
    }
    cout << endl;
}

template <class Head, class... Tail>
void println(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    println(forward<Tail>(tail)...);
}

template <class T>
void println(vector<T>& vs){for (auto v: vs) cout << v << endl;}

void solve(){
    ll n, x, m, cur;
    scan(n, x, m);

    vector<bool> visited(m, false);
    cur = x;
    vl bs;
    while (!visited[cur]){
        visited[cur] = true;
        bs.push_back(cur);
        (cur *= cur) %= m;
    }

    ll loc = 0, ans = 0;
    while (bs[loc] != cur) ++loc;
    ll n_loop = bs.size() - loc;
    rep(i, loc) ans += bs[i];
    n -= loc;
    ll res = n / n_loop, v = 0, resres = n % n_loop;
    For(i, loc, ll(bs.size())) v += bs[i];
    For(i, loc, loc + resres) ans += bs[i];
    ans += v * res;
    println(ans);
}

void test(ll num = 0, bool verbose = false){
    rep(i, max(1LL, num)){
        ll t = clock();
        if (verbose) cout << "\n#####" << " " << i + 1 << " " << "#####" << " " << "\n## Answer ##\n";
        solve();
        if (verbose) {cout << "\nElapsed Time:" << " " << 1000.0 * (clock() - t) / CLOCKS_PER_SEC << " " << "[ms]" << endl;}
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    #ifdef _LOCAL
        test(6, true);
    #else
        ll t = 0;
        if (multiple_queries) cin >> t;
        test(t, false);
    #endif
    return 0;
}