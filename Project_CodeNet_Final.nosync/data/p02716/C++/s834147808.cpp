#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...)name
#define _rep(i,n)repi(i,0,n)
#define repi(i,a,b)for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define MSVC_UNKO(x)x
#define rep(...)MSVC_UNKO(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define all(c)c.begin(),c.end()
#define write(x)cout<<(x)<<'\n'
using namespace std; typedef long long ll; template<class T>using vv = vector<vector<T>>;
template<class T>auto vvec(int n, int m, T v) { return vv<T>(n, vector<T>(m, v)); }
constexpr int INF = 1 << 29, MOD = int(1e9) + 7; constexpr ll LINF = 1LL << 60;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }aaaa;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    if (N <= 3) {
        write(*max_element(all(A)));
        return 0;
    }

    vv<ll> dp = vvec(N, 3, -LINF);
    dp[0][0] = A[0];
    dp[1][1] = A[1];
    dp[2][0] = A[0] + A[2];
    dp[2][2] = A[2];
    dp[3][1] = A[3] + max(A[0], A[1]);
    rep(i, 4, N) {
        //if (i % 2 == 0) {
        //    dp[i][0] = max(dp[i][0], dp[i - 2][0] + A[i]);
        //    dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i]);
        //    dp[i][1] = max(dp[i][1], dp[i - 3][0] + A[i]);
        //    dp[i][2] = max(dp[i][2], dp[i - 2][2] + A[i]);
        //    dp[i][2] = max(dp[i][2], dp[i - 3][1] + A[i]);
        //    dp[i][2] = max(dp[i][2], dp[i - 4][0] + A[i]);
        //}
        //else {
        //    dp[i][1] = max(dp[i][0], dp[i - 2][1] + A[i]);
        //    dp[i][1] = max(dp[i][0], dp[i - 3][0] + A[i]);
        //}

        dp[i][0] = max(dp[i][0], dp[i - 2][0] + A[i]);
        dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i]);
        dp[i][1] = max(dp[i][1], dp[i - 3][0] + A[i]);
        dp[i][2] = max(dp[i][2], dp[i - 2][2] + A[i]);
        dp[i][2] = max(dp[i][2], dp[i - 3][1] + A[i]);
        dp[i][2] = max(dp[i][2], dp[i - 4][0] + A[i]);
    }

    ll ans;
    if (N % 2 == 0) {
        ans = max(dp[N - 2][0], dp[N - 1][1]);
    }
    else {
        ans = max({ dp[N - 3][0], dp[N - 2][1], dp[N - 1][2] });
    }
    write(ans);
}