// #define DEBUGGING
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
using ll = int64_t;
using ull = uint64_t;
using PLL = pair<ll, ll>;

template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return max(low, min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { t = clamp(t, low, high); }

namespace init__ {

struct InitIO {
    InitIO() {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

}

#ifdef DEBUGGING
#include "../../debug/debug.cpp"
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

ll dp[202][12][1ll << 12];
ll pre_up[16], pre_down[16];
ll N, K, M;

PLL calc_pre_puts(ll i, ll k) {
    ll up_idx = 0, down_idx = 0;
    ll cnt_upper = min<ll>(i, 12);
    for(ll cnt = 0; cnt < cnt_upper; cnt++, i--) {
        if(k & 1) {
            pre_down[down_idx] = i;
            down_idx++;
        } else {
            pre_up[up_idx] = i;
            up_idx++;
        }
        k >>= 1;
    }
    reverse(pre_up, pre_up + up_idx);
    reverse(pre_down, pre_down + down_idx);
    return make_pair(up_idx, down_idx);
}

bool enable_put(ll up_idx, ll down_idx, ll j, bool up, ll num) {
    if(up) {
        if(K < num - pre_up[up_idx - 1]) return false;
    } else {
        if(0 < down_idx && K < num - pre_down[down_idx - 1]) return false;
        if(up_idx == 0) return false;
        if(up_idx - j < 0) return false;
        if(K < num - pre_up[up_idx - j]) return false;
    }
    return true;
}

const ll mask = 1ll << 12;

ll bit_mask(ll k) {
    k <<= 1;
    k |= mask;
    k ^= mask;
    return k;
}

int main() {
    cin >> N >> K >> M;
    dp[1][1][0] = 1;
    for(ll i = 1; i < 2 * N; i++) for(ll j = 0; j < 12; j++) for(ll k = 0; k < (1ll << min<ll>(12, i)); k++) {
        ll up_idx, down_idx;
        tie(up_idx, down_idx) = calc_pre_puts(i, k);
        DEBUG(make_tuple(i, k, up_idx));

        /*
        if(!up_idx || (K < i && !down_idx)) continue;
        if(up_idx + j < down_idx) continue;
        */

        DEBUG(make_tuple(i, j, k, enable_put(up_idx, down_idx, true, i + 1), enable_put(up_idx, down_idx, false, i + 1)));

        // put upper
        if(enable_put(up_idx, down_idx, j, true, i + 1) && j + 1 <= K) (dp[i + 1][j + 1][bit_mask(k)] += dp[i][j][k]) %= M;
        
        // put lower
        if(enable_put(up_idx, down_idx, j, false, i + 1) && 0 <= j - 1) (dp[i + 1][j - 1][bit_mask(k) + 1] += dp[i][j][k]) %= M;
        DEBUG(dp[i][j][k], dp[i + 1][j - 1][bit_mask(k) + 1]);
    }

    ll ans = 0;
    ll max_act_log = min<ll>(12, 2 * N);
    for(ll i = 0; i < (1ll << max_act_log); i++) (ans += dp[2 * N][0][i]) %= M;
    cout << ans << endl;
    return 0;
}

