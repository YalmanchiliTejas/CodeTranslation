#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    vector<int> s(N);
    rep(i, 0, N) cin >> s[i];
    long long ans = 0;
    rep(i, 1, N) {
        int l = 0, r = N - 1;
        long long res = 0;
        long long sum = 0;
        if((N - 1) % i == 0) {
            for(; l < r; l += i, r -= i) {
                sum += s[l] + s[r];
                res = max(res, sum);
            }
        } else {
            for(; l < N - 1 && r - i > 0; l += i, r -= i) {
                sum += s[l] + s[r];
                res = max(res, sum);
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
