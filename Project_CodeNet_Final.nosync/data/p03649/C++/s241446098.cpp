#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x) x
#define rep(...) MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c) c.begin(),c.end()
#define mp make_pair
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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll ans = 0;
    while (1) {
        bool leBase = std::all_of(all(A), [&](auto x) { return x < N; });
        if (leBase) {
            write(ans);
            return 0;
        }
        bool geBase = std::all_of(all(A), [&](auto x) { return x >= N - 1; });
        if (geBase) break;

        rep(i, N) {
            if (A[i] > N - 1) {
                A[i] -= N;
                rep(j, N) if (j != i) A[j]++;
                ans++;
                break;
            }
        }
    }

    rep(i, N) {
        ll exceed = A[i] - (N - 1);
        A[i] -= exceed / (N + 1) * (N + 1);
        ans += exceed / (N + 1) * (N + 1);
    }

    while (1) {
        bool leBase = std::all_of(all(A), [&](auto x) { return x < N; });
        if (leBase) {
            write(ans);
            return 0;
        }

        rep(i, N) {
            if (A[i] > N - 1) {
                A[i] -= N;
                rep(j, N) if (j != i) A[j]++;
                ans++;
                break;
            }
        }
    }
}