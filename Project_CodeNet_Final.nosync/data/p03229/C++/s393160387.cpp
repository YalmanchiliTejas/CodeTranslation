#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    ll ans = 0;
    if (N % 2 == 0) {
        int num = N - 2;
        rep(i, num / 2) ans -= A[i] * 2;
        rep(i, num / 2) ans += A[N - 1 - i] * 2;
        ans -= A[N / 2 - 1];
        ans += A[N / 2];
    } else {
        int num = N - 2;
        rep(i, (num + 1) / 2) ans -= A[i] * 2;
        rep(i, num / 2)       ans += A[N - 1 - i] * 2;
        ans += A[N / 2];
        ans += A[N / 2 + 1];

        ll res = 0;
        rep(i, num / 2)       res -= A[i] * 2;
        rep(i, (num + 1) / 2) res += A[N - 1 - i] * 2;
        res -= A[N / 2 - 1];
        res -= A[N / 2];

        ans = max(ans, res);
    }

    cout << ans << endl;
}