#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 1e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> vec(N);
    ll sum = 0;
    REP(i, N) {
        cin >> vec[i];
        sum += vec[i];
    }
    sum -= vec[0];
    sum %= MOD;

    ll ans = 0;
    REP(i, N-1) {
        ans += vec[i] * sum;
        ans %= MOD;
        sum -= vec[i + 1];
        if (sum < 0) {
            sum += MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
