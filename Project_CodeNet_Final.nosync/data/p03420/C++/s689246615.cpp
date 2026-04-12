#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << (ll)N * N << endl;
        return 0;
    }

    ll ans = 0;
    for (int b = K + 1; b <= N; ++ b) {
        ans += (b - K) * (N / b);
        ans += max(0, N % b - (K - 1));
    }

    cout << ans << endl;
}