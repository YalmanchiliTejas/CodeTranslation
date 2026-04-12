#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    FOR(b,1,N+1) {
        ll p = N/b;
        ans += p*max(0ll,b-K);
        ans += max(0ll,(N%b)-K+1);
    }
    if (K==0) ans-=N;
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}