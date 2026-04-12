#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(ALL(A));
    if (N % 2 == 0) {
        ll ans1 = A[N/2] - A[N/2-1];
        ll ans2 = A[N/2] - A[N/2-1];
        REP(i, (N-2) / 2) {
            ans1 += A[N-1 - i] * 2;
            ans1 -= A[i] * 2;
            ans2 += A[i] * 2;
            ans2 -= A[N-1 - i] * 2;
        }
        PRINT(max(ans1, ans2));
    } else {
        ll ans1 = -A[N/2] - A[N/2-1];
        ll ans2 = + A[N/2] + A[N/2+1];
        REP(i, (N-1) / 2) {
            ans1 += A[N-1 - i] * 2;
            ans2 -= A[i] * 2;
        }
        REP(i, (N-2)/2) {
            ans1 -= A[i] * 2;
            ans2 += A[N-1 - i] * 2;
        }
        PRINT(max(ans1, ans2));
    }
    return 0;
}
