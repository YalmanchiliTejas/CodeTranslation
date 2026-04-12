#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

ll N;
vector<ll> S;

signed main()
{
    cin >> N;
    S.resize(N);
    REP(i, N) { cin >> S[i]; }

    ll ans = 0;

    // C = A - B とすると、
    // B 移動では C * k の場所を取得でき、
    // A 移動では A + C * k の場所を取得する
    for(ll C = 1; C < N; ++C) {
        ll prev_val_a = 0;
        ll prev_ind_a = N-1;
        ll prev_val_b = 0;
        ll prev_ind_b = 0;
        if((N - 1)  % C == 0) {
            // A 移動でとる位置と B 移動でとる位置がかぶったらだめ
            // -> C が N - 1 の約数の場合
            for(ll k = 1; k < N / C; ++k) {
                // C を固定した場合、1 つ前のループの値が使いまわせる
                ll A = N - 1 - C * k;
                ll B = A - C;
                if(A <= 0 || B <= 0 || A <= B) { continue; }
                prev_ind_b += C;
                prev_val_b += S[prev_ind_b];
                if(prev_ind_a == prev_ind_b) { break; }
                prev_ind_a -= C;
                prev_val_a += S[prev_ind_a];
                if(prev_ind_a == prev_ind_b) { break; }
                if(prev_ind_a <= 0 || prev_ind_b >= N - 1) { break; }
                ans = max(ans, prev_val_a + prev_val_b);
            }
        }
        else {
            for(ll k = 1; k < N / C; ++k) {
                // C を固定した場合、1 つ前のループの値が使いまわせる
                ll A = N - 1 - C * k;
                ll B = A - C;
                if(A <= 0 || B <= 0 || A <= B) { continue; }
                prev_ind_b += C;
                prev_val_b += S[prev_ind_b];
                prev_ind_a -= C;
                prev_val_a += S[prev_ind_a];
                if(prev_ind_a <= 0 || prev_ind_b >= N - 1) { break; }
                ans = max(ans, prev_val_a + prev_val_b);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
