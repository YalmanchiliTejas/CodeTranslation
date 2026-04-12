#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, A[101010], B[101010];
ll get() {
    ll sm = 0;
    rep(i, N-1) sm += abs(B[i+1] - B[i]);
    return sm;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    rep(i, N) cin >> A[i];
    sort(A, A+N);
    ll ans = 0;
    if (N % 2 == 0) {
        rep(i, N/2) B[i*2+1] = A[i];
        rep(i, N/2) B[i*2] = A[i+N/2];
        ans = get();
    } else {
        rep(i, N/2) B[i*2+1] = A[i];
        B[N-1] = A[N/2];
        rep(i, N/2) B[i*2] = A[i+N/2+1];
        ans = get();
        B[0] = A[N/2];
        rep(i, N/2) B[i*2+2] = A[i];
        rep(i, N/2) B[i*2+1] = A[i+N/2+1];
        chmax(ans, get());
    }
    cout << ans << endl;
    return 0;
}