// #define DEBUGGING
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
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return max(low, min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { t = clamp(t, low, high); }

namespace __init {

struct InitIO {
    InitIO() {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

}

#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#define DEBUG_SEPARATOR_LINE 0
#endif

template <typename T>
T make_v(T init) { return init; }

template <typename T, typename... Tail>
auto make_v(T init, size_t s, Tail... tail) {
#define rec make_v(init, tail...)
    return V<decltype(rec)>(s, rec);
#undef rec
}

bool check_dup_insert(set<ll> &st, ll n) {
    if(st.find(n) != st.end()) return false;
    st.insert(n);
    return true;
}

int main() {
    ll N;
    cin >> N;
    V<ll> S(N);
    for(ll &e : S) cin >> e;
    
    ll ans = 0;
    for(ll range = 1; range <= N - 1; range++) {
        ll left = 0, right = N - 1;
        ll score = 0;
        ll max_score = 0;
        set<ll> st;
        while(right - range > 0) {
            right -= range;
            left += range;
            bool ok = (check_dup_insert(st, left) &
                       check_dup_insert(st, right));
            if(!ok) break;
            score += S[left] + S[right];
            ll A = right;
            ll B = A - range;
            if(!(0 < A && 0 < B && B < A)) continue;
            DEBUG(make_tuple(A, B, range, score));
            chmax(max_score, score);
        }
        chmax(ans, max_score);
    }

    cout << ans << endl;
    return 0;
}
