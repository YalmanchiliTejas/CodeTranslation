#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }


ll dp[3010][3010];
ll a[3010];

ll solve(int head, int tail) {
    if(dp[head][tail] != -1) return dp[head][tail];
    if(head == tail) return a[head];
    
    return dp[head][tail] = max(a[head]-solve(head+1, tail), a[tail]-solve(head, tail-1));
}


int main() {
    int n; cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, 3010) rep(j, 3010) dp[i][j] = -1;
    
    cout << solve(0, n-1) << endl;

    return 0;
}
