#include<bits/stdc++.h> 
#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vb = vector<bool>;
const int INF = 1e9;
const int MOD = 1e9+7;

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vl A(N); REP(i, N) cin >> A[i];
    sort(ALL(A));

    ll ans = 0;

    if(N % 2 == 0)
    {
        ll sum = 0;
        REP(i, N/2) sum -= 2*A[i];
        sum += A[N/2-1];
        sum -= A[N/2];
        for(int i = N/2; i < N; i++) sum += 2*A[i];
        ans = max(ans, sum);
    }
    else
    {
        ll sum = 0;
        REP(i, N/2) sum -= 2*A[i];
        sum -= A[N/2];
        sum -= A[N/2+1];
        for(int i = N/2; i < N; i++) sum += 2*A[i];
        ans = max(ans, sum);

        sum = 0;
        reverse(ALL(A));
        REP(i, N/2) sum += 2*A[i];
        sum += A[N/2];
        sum += A[N/2+1];
        for(int i = N/2; i < N; i++) sum -= 2*A[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;
}