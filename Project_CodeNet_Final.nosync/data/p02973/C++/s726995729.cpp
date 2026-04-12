#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x) x
#define rep(...) MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c) c.begin(),c.end()
#define mp make_pair
#define write(x) cout<<(x)<<"\n"
using namespace std; typedef long long ll; typedef vector<int> vi; typedef vector<ll> vll;
template<class T>using vv = vector<vector<T>>; template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
template<class T1, class T2>bool chmax(T1& a, const T2& b) { return a < b ? a = b, 1 : 0; }
template<class T1, class T2>bool chmin(T1& a, const T2& b) { return b < a ? a = b, 1 : 0; }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];

    //vv<ll> dp = vvec(N + 1, 2, LINF);

    //int l = 0, h = N;
    //while (h - l > 1) {
    //    int mid = (l + h) / 2;

    //    rep(i, N + 1) dp[i][0] = dp[i][1] = LINF;

    //    




    //}

    //write(h);

    vll B = { A[0] };
    int ans = 1;

    rep(i, 1, N) {
        

        auto lb = lower_bound(B.rbegin(), B.rend(), A[i]);
        auto ub = upper_bound(B.rbegin(), B.rend(), A[i]);

        if (lb == B.rbegin()) {
            B.push_back(A[i]);

            ans++;
        }
        else {
            *(lb - 1) = A[i];
        }
    }

    write(ans);
}