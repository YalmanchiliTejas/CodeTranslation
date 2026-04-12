#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

// 答えを見たよ。
int calc(int N, int K, int b) {
    int p = N / b;
    int r = N % b;

    // a % b >= K であるようなaの種類
    // (0 <= a <= N)
    int ans = p * max(0LL, b - K) + max(0LL, r - K + 1);

    // 0 % b => K であるものをカウントしてしまっているので引く
    if (K == 0) {
        ans -= 1;
    }

    return ans;
}

signed main() {
    int N, K;

    cin >> N >> K;

    int ans = 0;
    FORE(b, 1, N) {
        ans += calc(N, K, b);
    }

    cout << ans << endl;
    return 0;
}
