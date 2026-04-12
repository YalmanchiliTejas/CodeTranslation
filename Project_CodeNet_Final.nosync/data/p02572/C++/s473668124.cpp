#include <bits/stdc++.h>
using namespace std;

// typedef
// -----------------------------------------------------------------------------
typedef long long ll;
typedef long double ld;

// container util
// -----------------------------------------------------------------------------
#define ALL(c)  (c).begin(),(c).end()
#define SZ(c) ((ll)(c).size())
#define MAX(c) *max_element(ALL(c))
#define MIN(c) *min_element(ALL(c))
#define SORT(c) sort((c).begin(),(c).end())

// repetition
// -----------------------------------------------------------------------------
#define FOR(i, a, b) for(ll i= (a); i < (ll)(b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
// -----------------------------------------------------------------------------
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

// debug
// -----------------------------------------------------------------------------
#define DUMP(x)  cerr << #x << " = " << (x) << endl


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    ll N; cin >> N;
    ll A[N]; 
    ll sum_a = 0;
    REP(i, N) {
        cin >> A[i];
        sum_a += A[i];
    }
    ll ans = 0;
    REP(i, N - 1) {
        sum_a -= A[i];
        ans += (sum_a % MOD) * (A[i] % MOD);
        ans = ans % MOD;
    }
    cout << ans << "\n";
}