#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    ll N, K, ans = 0;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    FOR(i, K + 1, N + 1) {
        ans += (N / i) * (i - K);
        ans += max(0LL, (N % i) - K + 1);
    }
    cout << ans << endl;
    return 0;
}