#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define rep(i, n) for(int i=0;i<(n);++i)
#define INF (1ll<<60)
#define FI first
#define SE second
typedef pair<int, int> pii;
#define l_b lower_bound
#define u_b upper_bound

int N, K;

signed main() {
    cin >> N >> K;
    int ans = 0;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    for (int b = K + 1; b <= N; ++b) {
        ans += (b - K) * (N / b);
        int mod = N % b;
        if (mod >= K) {
            ans += mod - K + 1;
        }
    }
    cout << ans << endl;
}
