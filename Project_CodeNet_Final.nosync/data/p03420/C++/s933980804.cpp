#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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
    for (int b = K + 1; b <= N; ++b) {
        ans += N / b * (b - K);

        if (K <= N % b) ans += N % b - (K - 1);
    }

    cout << ans << endl;
}