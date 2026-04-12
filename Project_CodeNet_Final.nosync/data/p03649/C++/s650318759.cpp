#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;

template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

// #define DEBUGGING
#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#endif

int main() {
    init_io();
    ll N;
    cin >> N;
    V<ll> A(N);
    for(ll &e : A) cin >> e;
    
    ll ok = 5e18, ng = -1;
    auto ceil = [](ll n, ll k) { return n / k + !!(n % k); };
    
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        V<ll> cpy = A;
        ll times;
        bool suc = false;
        for(times = max<ll>(0, mid - 2 * N); times <= mid; times++) {
            ll cnt = 0;
            for(ll e : cpy) {
                e += times;
                e -= (N - 1);
                chmax(e, (ll)0);
                cnt += ceil(e, N + 1);
            }
            if(cnt <= times) {
                suc = true;
                break;
            }
        }
        if(suc) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
