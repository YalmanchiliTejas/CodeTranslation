#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    priority_queue<int64> PQ;
    rep(i, 0, N) {
        int64 a; cin >> a;
        PQ.push(a);
    }
    int64 ans = 0;
    while(PQ.top() + ans > N - 1) {
        int64 t = PQ.top() + ans; PQ.pop();
        int64 a = t / N;
        ans += a;
        PQ.push(t % N - ans);
    }
    cout << ans << endl;
    return 0;
}
