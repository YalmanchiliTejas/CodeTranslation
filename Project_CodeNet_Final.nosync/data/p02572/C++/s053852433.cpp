#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;
int main()
{
    int N;
    cin >> N;
    vector<ll> A(N), sum(N + 1);
    rep(i, N) {
        cin >> A[i];
        sum[i + 1] = sum[i] + A[i];
    }

    ll ans = 0;
    rep(i, N - 1) {
        ll t = sum[N] - sum[i + 1];
        t %= MOD;
        ans += (t * A[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}