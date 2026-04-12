#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, A[100010];

ll solve(){
    ll ans = 0;
    if(N % 2 == 0){
        REP(i, N / 2 - 1) ans += 2 * A[i];
        ans += A[N / 2 - 1];
        ans -= A[N / 2];
        FOR(i, N / 2 + 1, N) ans -= 2 * A[i];
    }else{
        REP(i, N / 2 - 1) ans += 2 * A[i];
        ans += A[N / 2 - 1] + A[N / 2];
        FOR(i, N / 2 + 1, N) ans -= 2 * A[i];
    }
    return ans;
}

signed main(){
    cin >> N;
    REP(i, N) cin >> A[i];
    sort(A, A + N, greater<ll>());
    ll ans = 0;
    ans = solve();
    REP(i, N) A[i] *= -1;
    reverse(A, A + N);
    ans = max(ans, solve());
    PRINT(ans);
    return 0;
}