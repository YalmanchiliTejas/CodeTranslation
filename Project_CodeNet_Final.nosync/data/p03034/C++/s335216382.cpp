#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x) x
#define rep(...) MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c) c.begin(),c.end()
#define write(x) cout<<(x)<<'\n'
using namespace std; typedef long long ll; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T, class U>bool chmax(T& a, U&& b) { return a < b ? a = b, 1 : 0; }
template<class T, class U>bool chmin(T& a, U&& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

int main() {
    int N;
    cin >> N;
    vector<ll> S(N);
    rep(i, N) cin >> S[i];

    // C = A - B
    // とおくと
    // 0C, A + 0C,
    // 1C, A + 1C,
    // 2C, A + 2C,
    // ...
    // kC, A + kC(= N - 1)
    
    // A = N - 1 - kC
    // として
    // 0C, N - 1 - (k - 0)C,
    // 1C, N - 1 - (k - 1)C,
    // 2C, N - 1 - (k - 2)C,
    // ...
    // kC, N - 1 - (k - k)C
    // すべての段で左 < 右
    
    // f(k) - f(k - 1) = S[kC] + S[N - 1 - kC]

    ll ans = 0;

    for (int C = 1; C < N; ++C) {
        ll sum = 0;

        for (int k = 1; k * C < N; ++k) {
            if ((N - 1) % C == 0 && k <= (N - 1) / C && (N - 1) / C <= 2 * k) {
                break;
            }
            else if ((k + 1) * C >= N - 1) {
                break;
            }
            else {
                sum += S[k * C] + S[N - 1 - k * C];

                ans = max(ans, sum);
            }
        }
    }

    write(ans);
}